#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToConsole();
    //ofDisableArbTex();
    
    maskShader.load("mask.vert", "mask.frag");

    tracker.setup();

    grabber.setup(1280, 720, true);

    maskFbo.allocate(1280, 720, GL_RGB);
    output.allocate(1280, 720, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();

    if (grabber.isFrameNew()) {
        tracker.update(grabber);

        vector<ofxFaceTracker2Instance>& instances = tracker.getInstances();

        ofLogNotice("ofApp::update") << instances.size() << " faces detected.";


        maskFbo.begin();
            ofBackground(ofColor::black);

            ofPushStyle();
                ofSetColor(ofColor::white);

                for (ofxFaceTracker2Instance & face : instances) {

                    ofxFaceTracker2Landmarks & faceLandmarks = face.getLandmarks();
                    ofMesh faceMesh = faceLandmarks.getImageMesh();

                    faceMesh.draw();
                }

            ofPopStyle();

        maskFbo.end();

        output.begin();
            //ofBackground(ofColor::black);

            maskShader.begin();
                maskShader.setUniformTexture("mainTex", grabber.getTexture(), 0);
                maskShader.setUniformTexture("maskTex", maskFbo.getTexture(), 1);
                maskShader.setUniform2f("size", glm::vec2(1280, 720));

                ofPlanePrimitive plane;
                plane.resizeToTexture(grabber.getTexture());
                plane.setPosition(glm::vec3(1280 * 0.5, 720 * 0.5, 0.0));
                plane.draw();

            maskShader.end();

        output.end();

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //grabber.draw(0, 0);
    //tracker.drawDebug();
    //maskFbo.draw(0, 0);
    output.draw(0, 0);
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
