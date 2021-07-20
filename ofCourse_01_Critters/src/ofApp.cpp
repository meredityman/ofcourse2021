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