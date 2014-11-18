#include "ofApp.h"

bool mouseP = false;
ofFbo fbo;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB32F);
    fbo.begin();
    ofBackground(128, 128, 128);
    fbo.end();
    
    ofPoint initPos = ofPoint( ofGetWidth() / 2, ofGetHeight() / 2 );
    float lifespan = 10;
    ofColor color = ofColor::white;
    ofPoint initVel = ofPoint(0, 0);
    ofPoint initAcc = ofPoint(0, 0);
    
    ParticleParams params ( initPos, lifespan, color, initVel, initAcc, 1 );
    
    p.setup(params);
    
    time0 = ofGetElapsedTimef();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    
    if (p.isAlive()) {
        p.update(dt);
    }
    
    time0 = ofGetElapsedTimef();
    
    friction = 0.01 * p.getVelocity() * p.getMass();
    p.applyForce(friction);
    
    if (mouseP) {
        ofPoint force;
        force.x = mouseX - p.getPosition().x;
        force.y = mouseY - p.getPosition().y;
        
        p.applyForce(force);
    }
    
    
    fbo.begin();
        ofSetColor(128, 128, 128, 50);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        p.display();
    fbo.end();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(128, 128, 128);
    
    ofSetColor(255, 255, 255, 128);
    ofCircle(mouseX, mouseY, 3);
    
    ofSetColor(255, 255, 255);
    fbo.draw(0, 0);

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
    
    mouseP = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    mouseP = false;
    
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
