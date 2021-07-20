#include "critter.h"

Critter::Critter(){
    legs_n = 10;
    tail_n = 10;

    head_w = ofRandom(40.0, 30);
    body_w = ofRandom(100, 600.0);
    tail_w = ofRandom(100, 200.0);
    body_h = ofRandom(10, 30.0);

    eye_h = 20;	


    primary    = ofColor(
        ofRandom(0, 255), // Red
        ofRandom(0, 255), // Green 
        ofRandom(0, 255)  // Blue
    );

    secondary  = ofColor::fromHsb (
        ofRandom(0, 255),   // Hue
        ofRandom(127, 255), // Saturation 
        200                 // Brightness
    );
}


void Critter::draw(){
    ofPushMatrix();

        ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
        ofTranslate(-1.0 * (head_w + body_w * 0.5), -2.0 * body_h);

        drawHead();
        drawBody();
        drawLegs();
        drawTail();

    ofPopMatrix();

}
void Critter::drawHead(){
    ofSetColor(secondary);
    ofDrawRectangle(0.0, 0.0, head_w, body_h);

    ofSetColor(ofColor::antiqueWhite);
    ofDrawCircle(0.0, 0.0, eye_h * 0.75);

    ofSetColor(ofColor::black);
    ofDrawCircle(0.0, 0.0, eye_h * 0.25); 
};
void Critter::drawBody(){
    ofSetColor(primary);
    ofDrawRectangle(head_w, 0.0, body_w, body_h);

};
void Critter::drawLegs(){
    ofSetColor(ofColor::black);
    for (int i = 0; i < legs_n; i++) {
        float leg_seg = body_w / legs_n;

        ofDrawRectangle(head_w + leg_seg * i, body_h, leg_seg * 0.3, body_h);
    }

};

void Critter::drawTail(){
    for (int i = 0; i < tail_n; i++) {
        float tail_seg = tail_w / tail_n;

        float x = (float)i / (tail_n - 1.0);

        ofColor tailColor = primary;		
        ofSetColor(tailColor.lerp(secondary, x));

        glm::vec2 size( tail_seg,  body_h * ( 1.0 - x) );

        glm::vec2 pos(
            head_w + body_w + tail_seg * i,
            (body_h - size.y) * 0.5            
        );

        ofDrawRectangle( pos.x, pos.y, size.x, size.y);
    }
};