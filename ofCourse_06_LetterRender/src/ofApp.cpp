#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.loadFont("KaushanScript-Regular.ttf", FONT_SIZE, true, true, true);
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::processOsc(){
    while( receiver.hasWaitingMessages()){

        ofxOscMessage m;
        receiver.getNextMessage(m);
        ofLogNotice("ofApp::processOsc") << m;

        if(m.getAddress() == "/character"){
            char c = m.getArgAsChar(0);
            characters.push_back( characterObject(c, font, ofColor::red));

        }
    }

}
//--------------------------------------------------------------
void ofApp::update(){
    processOsc();


    for( auto & character : characters){
        character.update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::black);
    
    for( auto & character : characters){
        character.draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    characters.push_back( characterObject((char)key, font, ofColor::blue));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
