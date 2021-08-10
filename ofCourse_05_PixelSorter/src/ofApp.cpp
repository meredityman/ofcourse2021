#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofDisableArbTex();

    shader.load("shader.vert", "shader.frag");

    lineThreshold.set("Line Threshold", 200.0, 0.0, 255.0);
    lineThreshold.addListener(this, &ofApp::onProcess);

    gui.setup();
    gui.add(lineThreshold);

    inImg.load("default.jpg");
    process();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(outImg.isAllocated()){
        shader.begin();
        shader.setUniform1f("mouseX", (float)ofGetMouseX() /ofGetWidth());
        outImg.draw(0, 0);
        shader.end();
    }

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::process(){
    pixels.clear();


    // Filling pixels from the image
    for( int y = 0; y < inImg.getHeight(); y++){
        std::vector<ofColor> row;
        for( int x = 0; x < inImg.getWidth(); x++){
            ofColor col = inImg.getColor(x, y);
            row.push_back(col);
            //ofLogNotice("ofApp::process") << x << ", " << y << ": " << ofToString(col);
        }
        pixels.push_back(row);
    }

    // Filling pixels from the image
    for( auto & row : pixels){

        std::vector<ofColor>::iterator start = row.begin();

        while( start++ < row.end() - 1){
            if( start->getBrightness() > lineThreshold.get()) break;
        }

        std::vector<ofColor>::iterator end   = start;
        while( end++ < row.end() - 1){
            if( end->getBrightness() <  50) break;
        }


        std::sort(start, end, [](ofColor a, ofColor b){
            return a.getBrightness() < b.getBrightness();
        });
    }


    outImg.allocate(inImg.getWidth(), inImg.getHeight(), OF_IMAGE_COLOR);

    for( int y = 0; y < outImg.getHeight(); y++){
        std::vector<ofColor> & row = pixels[y];
        for( int x = 0; x < outImg.getWidth(); x++){
            ofColor col = row[x];
            //ofLogNotice() << x << ", " << y << ": "<< col;
            outImg.setColor(x, y, col);
        }
    }

    outImg.update();

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '='){
        lineThreshold = lineThreshold + 5;
        lineThreshold = ofClamp(lineThreshold, lineThreshold.getMin(), lineThreshold.getMax());
    } else if (key == '-'){
        lineThreshold = lineThreshold - 5;
        lineThreshold = ofClamp(lineThreshold, lineThreshold.getMin(), lineThreshold.getMax());
    }

    ofLogNotice("ofApp::keyPressed") << lineThreshold;
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
