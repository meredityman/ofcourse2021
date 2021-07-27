#include "critter.h"

Critter::Critter(){
    legs_n = 10;
    tail_n = 10;

    head_w = ofRandom(40.0, 30);
    body_w = ofRandom(100, 300.0);
    tail_w = ofRandom(100, 300.0);
    body_h = ofRandom(10, 30.0);

    eye_h = ofRandom(body_h * 0.5, 1.2 * body_h);


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

        ofTranslate(node.getX(), node.getY());
        
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

    glm::vec2  mousePos    = glm::vec2(ofGetMouseX(), ofGetMouseY());
    glm::vec2  eyePosition = glm::vec2(node.getX(), node.getY());
    glm::vec2  mouseDirection = mousePos - eyePosition;
    mouseDirection = glm::normalize(mouseDirection);

    ofLogNotice("Critter::drawHead") << mousePos.x << ", " << mousePos.y;

    ofSetColor(ofColor::antiqueWhite);
    ofDrawCircle(0.0, 0.0, eye_h);


    ofSetColor(ofColor::black);
    ofDrawCircle(mouseDirection.x * eye_h * 0.5, mouseDirection.y * eye_h * 0.5, eye_h * 0.25); 
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

        float offset = pow(x, 2.4) * body_h * sin( 0.01 * ofGetElapsedTimeMillis() + x );

        pos.y += offset;

        ofDrawRectangle( pos.x, pos.y, size.x, size.y);
    }
};