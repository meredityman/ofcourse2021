#pragma once

#include "ofMain.h"
#include "ofxGui.h"
<<<<<<< HEAD
=======

>>>>>>> e9f3262c4816d4e6e668aba0bf0c6c921b2d214e

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

<<<<<<< HEAD
=======
		ofParameter<float> lineThresholdStart;
		ofParameter<float> lineThresholdEnd;
		ofParameter<bool>  sortRows;
		ofParameter<int>   sortType;
		

>>>>>>> e9f3262c4816d4e6e668aba0bf0c6c921b2d214e
		ofxPanel gui;

		ofParameter<float> lineThreshold;

		std::vector<std::vector<ofColor>> pixels;

		ofImage inImg, outImg;

		ofShader shader;
};
