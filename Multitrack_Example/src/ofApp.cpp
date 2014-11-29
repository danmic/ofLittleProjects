#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    //Hide the cursor
    ofHideCursor();
    
    //Define a path
    //string path = "NonLoDiroColLabbro";
    //string path = "AlexTheAdventurer";
    string path = "FunnyValentines_SleighRide_Full";
    
    //Create a multitrack object from a path
    m = multitrack(path);
    //Set m up
    m.setup();
    
    //Set the volume
    ofSoundSetVolume(0.5);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //Update m
    m.update(volumeUP, volumeDOWN);
    
    ofSoundUpdate();

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(237,248,233);
    
    m.display(mouseX, mouseY);
    
    //Display the cursor
    ofSetColor(8,81,156);
    ofCircle(mouseX, mouseY, 1);
    ofSetColor(8,81,156, 128);
    ofCircle(mouseX, mouseY, 4);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == OF_KEY_UP){     //UP
        volumeUP = true;
    }
    
    if(key == OF_KEY_DOWN){     //DOWN
        volumeDOWN = true;
    }
    
    if (key == 's') {
        m.selectAll();
    }
    
    if (key == 'u') {
        m.unselectAll();
    }
    
    if (key == 'p'){
        m.togglePlayer();
    }
    
    if (key >= 49 && key <= 50) { //[1, 2]
        float r = function( ofGetElapsedTimef(), key - 48 );
        if (r > 0) {
            volumeUP = true;
            volumeDOWN = false;
        }else{
            volumeDOWN = true;
            volumeUP = false;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    volumeUP = volumeDOWN = false;

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    m.toggleTrackSelection(x, y);

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


float ofApp::function(float time, int k){
    
    switch (k) {
        case 1:     //Random
            return ofRandom(-1.0, 1.0);
            break;
        case 2:     //Sine
            return sin(time);
            break;
        default:
            return 0;
    }
    
}










