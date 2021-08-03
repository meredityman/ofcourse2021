#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    inImg.load("default.jpg");
    process();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(outImg.isAllocated()){
        outImg.draw(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::process(){
    pixels.clear();

    for( int y = 0; y < inImg.getHeight(); y++){
        std::vector<ofColor> row;
        for( int x = 0; x < inImg.getWidth(); x++){
            ofColor col = inImg.getColor(x, y);
            row.push_back(col);
            //ofLogNotice("ofApp::process") << x << ", " << y << ": " << ofToString(col);
        }
        pixels.push_back(row);
    }

    for( auto & row : pixels){
        std::sort(row.begin(), row.end(), [](ofColor a, ofColor b){
            return a.r < b.r;
        });
    }


    outImg.allocate(inImg.getWidth(), inImg.getHeight(), OF_IMAGE_COLOR);

    for( int y = 0; y < outImg.getHeight(); y++){
        std::vector<ofColor> & row = pixels[y];
        for( int x = 0; x < outImg.getWidth(); x++){
            ofColor col = row[x];
            ofLogNotice() << x << ", " << y << ": "<< col;
            outImg.setColor(x, y, col);
        }
    }

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}


//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    for( std::string & path : dragInfo.files){
        ofLogNotice("ofApp::dragEvent") << path;
        inImg.load(path);
        process();
        break;
    }
}
