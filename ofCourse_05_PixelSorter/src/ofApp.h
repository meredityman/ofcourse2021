#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void process();
		void onProcessFloat( float & val){ process();}
		void onProcessBool( bool & val){ process();}
		void onProcessInt( int & val){ process();}

		void keyPressed(int key);
		void dragEvent(ofDragInfo dragInfo);

		ofParameter<float> lineThresholdStart;
		ofParameter<float> lineThresholdEnd;
		ofParameter<bool>  sortRows;
		ofParameter<int>   sortType;
		

		ofxPanel gui;

		ofParameter<float> lineThreshold;

		std::vector<std::vector<ofColor>> pixels;

		ofImage inImg, outImg;

		ofShader shader;
};
