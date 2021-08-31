#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings windowSettings;
    windowSettings.setGLVersion(4, 1);
    windowSettings.setSize(1280, 720);
    windowSettings.windowMode = OF_WINDOW;

    ofCreateWindow(windowSettings);

    ofRunApp(new ofApp());
}
