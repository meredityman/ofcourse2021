#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8000

#define FONT_SIZE 128
#define QUAD_SIZE (FONT_SIZE * 2.0)
#define PADDING ((QUAD_SIZE - FONT_SIZE) * 0.5)
#define CR_TIME 5000.0


class characterObject {

public:
	characterObject(char c, const ofTrueTypeFont & font, ofColor col){
		
		this->col = col;
		characterPath = font.getCharacterAsPoints(c, false);

		fbo.allocate(QUAD_SIZE, QUAD_SIZE, GL_RGBA);

		plane.set(QUAD_SIZE, QUAD_SIZE, 2, 2);
		plane.resizeToTexture(fbo.getTexture());

		position = glm::vec3(
			fmod(ofGetElapsedTimeMillis(), CR_TIME) / CR_TIME * ofGetWidth(),
			ofGetHeight() * 0.1,
			0
		);
	}

	void update(){
		plane.setPosition(position);

		position.z -= 100 * ofGetLastFrameTime();
		position.y += 200 * ofGetLastFrameTime();

	}

	void draw(){

		fbo.begin();
			ofClear(0, 0, 0, 0);

			ofPushStyle();
				ofSetColor(col);
				characterPath.draw(PADDING, QUAD_SIZE * 0.5);
			ofPopStyle();
		fbo.end();

		fbo.getTexture().bind();
		plane.draw();
		fbo.getTexture().unbind();
	}

	ofPlanePrimitive plane;
	ofColor col;
	ofPath characterPath;
	ofFbo fbo;

	glm::vec3 position;

};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void processOsc();
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

		ofxOscReceiver receiver;


		
};
