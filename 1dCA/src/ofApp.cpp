#include "ofApp.h"

int n = 0;      //Current rule
int pn = -1;     //Previous rule

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Let w be an odd number
    w = 1279;
    h = 720;
    
    //Set all pixels of the image as white
    unsigned char *pixels = new unsigned char[ w * h ];
    for (int i = 0; i != w*h; i++) {
        pixels[i] = 255;
    }
    blankImage.setFromPixels(pixels, w, h, OF_IMAGE_GRAYSCALE);
    
    image = blankImage;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //Update the pixel of image when needed
    if ((n != pn || n == 0) && n < 256) {
        
        //Set all pixels to white
        image = blankImage;
        
        //Set the initial state
        int stateSize = w;
        string initState = string(stateSize/2, '0') + "1" + string(stateSize/2, '0');
        
        //Set up a CA
        cellularAutomaton = CA( initState, true );
        //Change the ruleset
        cellularAutomaton.setRules( base2Num::convertToBase2(n, 8) );
        
        //Generate h-1 generations so that there will be
        //h generations with the initial one
        for (int i = 0; i != h-1; i++) {
            cellularAutomaton.generate();
        }
        
        //Get the history matrix
        auto history = cellularAutomaton.getHistory();
        
        for (int y = 0; y != history.size(); y++) {
            for (int x = 0; x != history[y].size(); x++) {
                
                //Change the pixels' color only when needed
                if (history[y][x] == '1') {
                    ofPixels &pixels = image.getPixelsRef();
                    pixels.setColor(x, y, 0);
                }
                
            }
        }
        
        //Update image
        image.update();
        
        //Save image
        image.saveImage(ofToString(n) + ".png");
        
        //Update n and pn
        n++;
        pn++;
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    //image.draw(0, 0);

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
