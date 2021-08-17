#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// open an outgoing connection to HOST:PORT
	sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(allLetters, 50, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

        allLetters += key;
        if(allLetters.size() % 140 == 0) allLetters += "\n";

		// send as a binary blob
		ofxOscMessage m;
		m.setAddress("/character");
		m.addCharArg((char)key);
		sender.sendMessage(m);
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
