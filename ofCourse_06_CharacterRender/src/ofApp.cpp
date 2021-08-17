#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
	font.load("Slackey-Regular.ttf", CHAR_SIZE, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){

    

    for(auto & character : characters){
        character.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(ofColor::black);
    for(auto & character : characters){
        character.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    characters.push_back(characterObj((char)key, font));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
