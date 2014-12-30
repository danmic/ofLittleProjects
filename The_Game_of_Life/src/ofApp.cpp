#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){    
    
    ofSetFrameRate(20);
    
    SquareCell c(8);
    vector<SquareCell> r;
    int w = 16 * 5;
    int h = 9 * 5;
    for (int i = 0; i != w; i++) {
        c.setState(0);
        r.push_back(c);
    }
    vector<vector<SquareCell> > g(h, r);
    
    //Gun
    
    g[1][25].setState(1);
    
    g[2][23].setState(1);
    g[2][25].setState(1);
    
    g[3][13].setState(1);
    g[3][14].setState(1);
    g[3][21].setState(1);
    g[3][22].setState(1);
    g[3][35].setState(1);
    g[3][36].setState(1);
    
    g[4][12].setState(1);
    g[4][16].setState(1);
    g[4][21].setState(1);
    g[4][22].setState(1);
    g[4][35].setState(1);
    g[4][36].setState(1);
    
    g[5][1].setState(1);
    g[5][2].setState(1);
    g[5][11].setState(1);
    g[5][17].setState(1);
    g[5][21].setState(1);
    g[5][22].setState(1);
    
    g[6][1].setState(1);
    g[6][2].setState(1);
    g[6][11].setState(1);
    g[6][15].setState(1);
    g[6][17].setState(1);
    g[6][18].setState(1);
    g[6][23].setState(1);
    g[6][25].setState(1);
    
    g[7][11].setState(1);
    g[7][17].setState(1);
    g[7][25].setState(1);
    
    g[8][12].setState(1);
    g[8][16].setState(1);
    
    g[9][13].setState(1);
    g[9][14].setState(1);
    
    
    //RANDOM INITIALIZATION
    /*
     for (int i = 0; i != g.size(); i++) {
     for (int j = 0; j != g.begin()->size(); j++) {
     g[i][j].setState(int(ofRandom(-1, 2)));
        }
     }
    */
    
    grid = SquareGrid(g);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grid.gameOfLife();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(94, 178, 242);
    
    grid.display();
    
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
