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

	ofPushMatrix();
	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

		int legs_n = 10;
		int tail_n = 10;

		float head_w = 40.0;
		float body_w = 200.0;
		float tail_w = 200.0;
		float body_h = 30.0;


		// Draw Head
		ofSetColor(ofColor::red);
		ofDrawRectangle(0.0, 0.0, head_w, body_h);
		

		ofSetColor(ofColor::antiqueWhite);
		ofDrawCircle(0.0, 0.0, body_h * 0.75);

		ofSetColor(ofColor::black);
		ofDrawCircle(0.0, 0.0, body_h * 0.25);


		// Draw Body
		ofSetColor(ofColor::green);
		ofDrawRectangle(head_w, 0.0, body_w, body_h);

		// Draw Legs
		ofSetColor(ofColor::black);
		for (int i = 0; i < legs_n; i++) {
			float leg_seg = body_w / legs_n;

			ofDrawRectangle(head_w + leg_seg * i, body_h, leg_seg * 0.3, body_h);
		}

		// Draw Tail
		for (int i = 0; i < tail_n; i++) {
			float tail_seg = tail_w / tail_n;

			float x = (float)i / (tail_n - 1.0);
			ofLogNotice() << x;

			ofColor tailColor = ofColor::purple;		

			ofSetColor(tailColor.lerp(ofColor::pink, x));

			ofDrawRectangle(head_w + body_w + tail_seg * i, 0.0, tail_seg, body_h * ( 1.0 - x));
		}

	ofPopMatrix();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
