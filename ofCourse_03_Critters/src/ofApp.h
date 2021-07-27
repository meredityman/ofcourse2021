#pragma once

#include "ofMain.h"
#include "critter.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);


		int numCritters = 20;

		std::vector<Critter> critters;

		ofImage screenGrab;
		int screenGrabIndex = 0;
};
