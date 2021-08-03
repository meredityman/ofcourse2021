#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //img.setUseTexture(false);
    //img.load("dog.jpg");
    img.load("C:/Users/mered/Desktop/dog2.jpg");


    //tex = img.getTexture();
    //pixels = img.getPixels();
}

//--------------------------------------------------------------
void ofApp::update(){
    img.save("dog_var.jpg", OF_IMAGE_QUALITY_WORST);
    img.load("dog_var.jpg");

    int scale = 100 * ofRandomf();

    img.resize(img.getWidth() - scale, img.getHeight() - scale);
    img.resize(img.getWidth() + scale, img.getHeight() + scale);
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofRectangle imgRect(0, 0, img.getWidth(), img.getHeight());
    ofRectangle winRect(0, 0, ofGetWidth()  , ofGetHeight());
    imgRect.scaleTo(winRect);

    //tex.draw(0, 0, imgRect.width, imgRect.height);
    img.draw(0, 0, imgRect.width, imgRect.height);
    //pixels.draw(0, 0, imgRect.width, imgRect.height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
