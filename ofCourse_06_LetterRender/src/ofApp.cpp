#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.loadFont("KaushanScript-Regular.ttf", 24, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){
    for( auto & character : characters){
        character.update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    for( auto & character : characters){
        character.draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    characters.push_back( characterObject((char)key, font));
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
