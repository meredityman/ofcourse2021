#pragma once
#include "ofMain.h"

#define QUAD_SIZE 128

class characterObject {

public:
	characterObject(char c, const ofTrueTypeFont & font){


		fbo.allocate(QUAD_SIZE, QUAD_SIZE, GL_RGBA);


		plane.set(QUAD_SIZE, QUAD_SIZE, 2, 2);
		plane.resizeToTexture(fbo.getTexture());

		position = glm::vec3(
			ofGetWidth()  * 0.5,
			ofGetHeight() * 0.5,
			0
		);
	}

	void update(){
		plane.setPosition(position);

		position.z -= 100 * ofGetLastFrameTime();
		position.y -= 200 * ofGetLastFrameTime();


	}

	void draw(){

		fbo.begin();
			ofClear(ofColor::magenta);

			ofPushStyle();
				ofSetColor(ofColor::cyan);
				ofDrawCircle(QUAD_SIZE * 0.5, QUAD_SIZE * 0.5,  QUAD_SIZE * 0.3);
			ofPopStyle();
		fbo.end();

		fbo.getTexture().bind();
		plane.draw();
		fbo.getTexture().unbind();
	}

	ofPlanePrimitive plane;

	ofFbo fbo;

	glm::vec3 position;

};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		vector<characterObject> characters;

		ofTrueTypeFont font;


		
};
