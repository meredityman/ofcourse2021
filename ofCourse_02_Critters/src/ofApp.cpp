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

	ofPushMatrix();

        int legs_n = 10;
        int tail_n = 10;

        float head_w = 40.0;
        float body_w = 200.0;
        float tail_w = 200.0;
        float body_h = 30.0;

        float eye_h = 20;

        ofColor primary    = ofColor::purple;
        ofColor secondary  = ofColor::pink;

		ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
        ofTranslate(-1.0 * (head_w + body_w * 0.5), -2.0 * body_h);

		// Draw Head
        ofSetColor(secondary);
        ofDrawRectangle(0.0, 0.0, head_w, body_h);

        ofSetColor(ofColor::antiqueWhite);
        ofDrawCircle(0.0, 0.0, eye_h * 0.75);

        ofSetColor(ofColor::black);
        ofDrawCircle(0.0, 0.0, eye_h * 0.25); 


		// Draw Body
        ofSetColor(primary);
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

            ofColor tailColor = primary;		
            ofSetColor(tailColor.lerp(secondary, x));

            glm::vec2 size( tail_seg,  body_h * ( 1.0 - x) );

            glm::vec2 pos(
                head_w + body_w + tail_seg * i,
                (body_h - size.y) * 0.5            
            );

            ofDrawRectangle( pos.x, pos.y, size.x, size.y);
        }

	ofPopMatrix();


}