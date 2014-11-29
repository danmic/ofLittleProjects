#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main( ){
    //Switch to GLUT to make ofHideCursor working
    ofAppGlutWindow window;
    ofSetupOpenGL(&window, 750, 750, OF_WINDOW);
    ofRunApp( new ofApp());
}