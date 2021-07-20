#pragma once
#include "ofMain.h"


class Critter{
public:

	Critter();

	void draw();

    void drawHead();
    void drawBody();
    void drawLegs();
    void drawTail();

	int legs_n;
	int tail_n;

	float head_w;
	float body_w;
	float tail_w;
	float body_h;

	float eye_h;

	ofColor primary;
	ofColor secondary;

};
