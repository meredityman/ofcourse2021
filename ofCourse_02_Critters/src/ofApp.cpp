#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogNotice("ofApp::setup") << "Hello World";

}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetWindowTitle( ofToString( ofGetFrameRate() ) );
	ofLogNotice("ofApp::update") << "Update";

	glm::vec3 critterPosition = glm::vec3(ofGetWidth(), ofGetHeight() * 0.5, 0.0);

	critterPosition.x -= ofGetWidth() * (float)(ofGetElapsedTimeMillis() % 2000)/2000;

    critter.node.setPosition(critterPosition ); 
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofLogNotice("ofApp::draw") << "Draw";
    ofSetBackgroundColor(ofColor::mediumSeaGreen);

    critter.draw();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    critter = Critter();
};