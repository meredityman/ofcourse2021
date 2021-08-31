#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
	font.load("Slackey-Regular.ttf", CHAR_SIZE, true, true, true);
    receiver.setup(PORT);
}


void ofApp::processOsc(){
	while(receiver.hasWaitingMessages()){

		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);

        ofLogNotice("ofApp::processOsc") << m;

		// check for mouse moved message
		if(m.getAddress() == "/character"){
			char c = m.getArgAsChar(0);
            onRecievedChar(c);
		}
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    processOsc();
    
    for(auto & character : characters){
        character.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(ofColor::black);
    for(auto & character : characters){
        character.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    onRecievedChar(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
