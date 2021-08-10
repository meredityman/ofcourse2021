#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    lineThresholdStart.set("Line Threshold Start", 200.0, 0.0, 255.0);
    lineThresholdStart.addListener(this, &ofApp::onProcessFloat);

    lineThresholdEnd.set("Line Threshold End", 30.0, 0.0, 255.0);
    lineThresholdEnd.addListener(this, &ofApp::onProcessFloat);


    sortRows.set("Sort Rows/Columns", true);
    sortRows.addListener(this, &ofApp::onProcessBool);

    sortType.set("Sort type", 0, 0, 2);
    sortType.addListener(this, &ofApp::onProcessInt);

    gui.setup();
    gui.add(lineThresholdStart);
    gui.add(lineThresholdEnd);
    gui.add(sortRows);
    gui.add(sortType);

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

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::process(){
    pixels.clear();


    // Filling pixels from the image
    if( sortRows){
        for( int y = 0; y < inImg.getHeight(); y++){
            std::vector<ofColor> row;
            for( int x = 0; x < inImg.getWidth(); x++){

                ofColor col = inImg.getColor(x, y);
                row.push_back(col);
                //ofLogNotice("ofApp::process") << x << ", " << y << ": " << ofToString(col);
            }
            pixels.push_back(row);
        }
    } else {
        for( int x = 0; x < inImg.getWidth(); x++){
            std::vector<ofColor> column;
            for( int y = 0; y < inImg.getHeight(); y++){

                ofColor col = inImg.getColor(x, y);
                column.push_back(col);
                //ofLogNotice("ofApp::process") << x << ", " << y << ": " << ofToString(col);
            }
            pixels.push_back(column);
        }  
    }


    // Filling pixels from the image
    for( auto & row : pixels){

        std::vector<ofColor>::iterator start = row.begin();
        std::vector<ofColor>::iterator end;

        switch( sortType.get()){
            // Brightness
            case 0:
                while( start++ < row.end() - 1 ){
                    if( start->getBrightness() < lineThresholdStart.get()) break;
                }

                end   = start ;

                while( end++ < row.end() - 1){
                    if( end -> getBrightness() < lineThresholdEnd.get()) break;
                }


                std::sort(start, end, [](ofColor a, ofColor b){
                    return a.getBrightness() < b.getBrightness();
                });
                break;
            // Saturation
            case 1:
                while( start++ < row.end() - 1 ){
                    if( start->getSaturation() < lineThresholdStart.get()) break;
                }

                end   = start ;

                while( end++ < row.end() - 1){
                    if( end -> getSaturation() < lineThresholdEnd.get()) break;
                }


                std::sort(start, end, [](ofColor a, ofColor b){
                    return a.getSaturation() < b.getSaturation();
                });
                break;
            // HUE
            case 2:
                while( start++ < row.end() - 1 ){
                    if( start->getHue() < lineThresholdStart.get()) break;
                }

                end   = start ;

                while( end++ < row.end() - 1){
                    if( end -> getHue() < lineThresholdEnd.get()) break;
                }


                std::sort(start, end, [](ofColor a, ofColor b){
                    return a.getHue() < b.getHue();
                });
                break;
        }


    }


    outImg.allocate(inImg.getWidth(), inImg.getHeight(), OF_IMAGE_COLOR);


    if( sortRows){
        for( int y = 0; y < outImg.getHeight(); y++){
            std::vector<ofColor> & row = pixels[y];
            for( int x = 0; x < outImg.getWidth(); x++){
                ofColor col = row[x];
                //ofLogNotice() << x << ", " << y << ": "<< col;
                outImg.setColor(x, y, col);
            }
        }
    } else {
        for( int x = 0; x < outImg.getWidth(); x++){
            std::vector<ofColor> & column = pixels[x];
            for( int y = 0; y < outImg.getHeight(); y++){

                ofColor col = column[y];
                //ofLogNotice() << x << ", " << y << ": "<< col;
                outImg.setColor(x, y, col);
            }
        }
    }

    outImg.update();

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // if(key == '='){
    //     lineThreshold = lineThreshold + 5;
    //     lineThreshold = ofClamp(lineThreshold, lineThreshold.getMin(), lineThreshold.getMax());
    // } else if (key == '-'){
    //     lineThreshold = lineThreshold - 5;
    //     lineThreshold = ofClamp(lineThreshold, lineThreshold.getMin(), lineThreshold.getMax());
    // }

    // ofLogNotice("ofApp::keyPressed") << lineThreshold;
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
