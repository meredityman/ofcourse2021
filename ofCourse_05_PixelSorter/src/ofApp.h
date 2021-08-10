#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void process();
		void onProcess( float & val){ process();
		}

		void keyPressed(int key);
		void dragEvent(ofDragInfo dragInfo);

		ofxPanel gui;

		ofParameter<float> lineThreshold;

		std::vector<std::vector<ofColor>> pixels;

		ofImage inImg, outImg;

		ofShader shader;
};
