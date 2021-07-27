#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogNotice("ofApp::setup") << "Hello World";
	ofSetFrameRate(60);


	for (int i = 0; i < numCritters; i++) {
		critters.push_back( Critter());
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetWindowTitle( ofToString( ofGetFrameRate() ) );
	ofLogNotice("ofApp::update") << "Update";


	for (int i = 0; i < critters.size(); i++) {

		float h = i * ofGetHeight()/numCritters;

		glm::vec3 critterPosition = glm::vec3(ofGetWidth(), h, 0.0);

		critterPosition.x -= ofGetWidth() * fmod((float)ofGetElapsedTimeMillis(), critters[i].period) / critters[i].period;

  		critters[i].node.setPosition(critterPosition);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofLogNotice("ofApp::draw") << "Draw";
    ofSetBackgroundColor(ofColor::mediumSeaGreen);

	for (int i = 0; i < critters.size(); i++) {
		critters[i].draw();
	}


	screenGrab.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	std::ostringstream fileName;


	// ffmpeg -i  bin/data/frames/frame_%04d.jpg bin/data/out.mp4
	fileName << "frames/" << "frame_" << ofToString(screenGrabIndex++, 4, '0') << ".jpg";

	screenGrab.save(fileName.str());
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r') {
		for (int i = 0; i < critters.size(); i++) {
			critters[i] = Critter();
		}
	} else if (key == ' ') {
		screenGrab.grabScreen(0, 0, ofGetWidth(), ofGetHeight());

		std::ostringstream fileName;
		fileName  << "screenGrabs/" << "screenGrab_" << screenGrabIndex++ << ".jpg";

		screenGrab.save(fileName.str());
	}
};