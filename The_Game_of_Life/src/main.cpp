#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
    
    ofAppGlutWindow window;
    ofSetupOpenGL(&window, 720, 405, OF_WINDOW);
    ofRunApp( new ofApp());

}
