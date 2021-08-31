#pragma once

#include "ofMain.h"
#include "ofxOsc.h"


#define PORT 12345

#define CHAR_SIZE 64.0
#define QUAD_SIZE (CHAR_SIZE * 1.5)
#define PADDING ((QUAD_SIZE - CHAR_SIZE) * 0.5)


#define VAR 500.0
#define AVAR 1000.0

class characterObj {

public:

	characterObj(char c, ofTrueTypeFont font){

		ofLogNotice("characterObj::characterObj") << "Making a: '" << c << "'"; 
		character = font.getCharacterAsPoints(c, false);
		fbo.allocate(QUAD_SIZE, QUAD_SIZE, GL_RGBA);

		position = glm::vec3(
			fmod(ofGetElapsedTimeMillis(), 3000.0) / 3000.0 * ofGetWidth(), 
			ofGetHeight() * 0.5,
			0
		);


		float t = ofGetElapsedTimef();
		velocity = glm::vec3(
			VAR * ofSignedNoise(t - 1000),
			VAR * ofSignedNoise(t + 1000),
			- VAR * ofNoise(t)		
		);

		// angularVelocity = glm::vec3(
		// 	AVAR * ofSignedNoise(t - 1000),
		// 	AVAR * ofSignedNoise(t + 1000),
		// 	AVAR * ofSignedNoise(t )		
		// );

		ofLogNotice("characterObj::characterObj") << t << ", " <<  position << ", " << velocity; 

		plane.resizeToTexture(fbo.getTexture());
		plane.setResolution(2, 2); 

	}

	void update(){
		if( !isAlive ) return;
		// orientation += angularVelocity * ofGetLastFrameTime();
		// plane.setOrientation( orientation );

		position += velocity * ofGetLastFrameTime();
		plane.setPosition(position);

		if(position.z > 1000){
			isAlive = false;
		}
	}

	void draw(){
		if( !isAlive ) return;

		fbo.begin();
			ofClear(0, 0, 0, 0);
			ofPushStyle();
			ofSetColor(ofColor::white);
			character.draw(0.0 + PADDING, CHAR_SIZE + PADDING);
			ofPopStyle();
		fbo.end();


		fbo.getTexture().bind();
		plane.draw();
		fbo.getTexture().unbind();
		
		// fbo.draw(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	}

	bool isAlive = true;


	ofFbo fbo;
	ofPlanePrimitive plane;
	ofPath character;



	// glm::vec3 orientation;
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 angularVelocity;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void processOsc();

		void keyPressed(int key);
		void keyReleased(int key);

		void onRecievedChar(char c){
			characters.push_back(characterObj(c, font));
		}


		vector<characterObj> characters;

		ofTrueTypeFont  font;
		ofxOscReceiver receiver;
		
};
