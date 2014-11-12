#include "ofApp.h"

#include "InsertionSort.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    //Set framerate
    ofSetFrameRate(60);
    
    //Load the image and resize it
    originalImage.loadImage("Lenna.png");
    float resize_param = 2;
    originalImage.resize(int(originalImage.width/resize_param), int(originalImage.height/resize_param));
    
    //Set up the margin value
    margin = 10;
    
    //Set the window width and height
    ofSetWindowShape(originalImage.width * 2 + 3 * margin, originalImage.height * 2 + 3 * margin);
    
    //create an array data to store the beginning values of the image channels
    int index = originalImage.width * originalImage.height * 3;
    unsigned char * data = new unsigned char[index];
    index = 0;
    for (int y = 0; y != originalImage.height; y++) {
        for (int x = 0; x != originalImage.width; x++) {
            index = 3 * ( x + y * originalImage.width);
            data[index] = 255;
            data[index + 1] = 255;
            data[index + 2] = 255;
        }
    }
    
    //Set up the image channels from the array data
    redImage.setFromPixels(data, originalImage.width, originalImage.height, OF_IMAGE_COLOR);
    greenImage.setFromPixels(data, originalImage.width, originalImage.height, OF_IMAGE_COLOR);
    blueImage.setFromPixels(data, originalImage.width, originalImage.height, OF_IMAGE_COLOR);
    
    //Update the changes
    redImage.update();
    greenImage.update();
    blueImage.update();
    
    //Free memory
    delete [] data;
    
    //Set the current pixel (0, 0)
    x = 0;
    y = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    if (x != -1 && y != -1) {
        //Current color
        ofColor currentC(originalImage.getColor(x, y));
        
        //Red value of currentC
        int currentCR = currentC.r;
        //Green value of currentC
        int currentCG = currentC.g;
        //Blue value of currentC
        int currentCB = currentC.b;
        
        if (x == 0 && y == 0) {     //If the current pixel is (0, 0)
            
            //Set the pixel (0, 0) of each channel
            redImage.setColor(x, y, ofColor(currentCR, 0, 0));
            greenImage.setColor(x, y, ofColor(0, currentCG, 0));
            blueImage.setColor(x, y, ofColor(0, 0, currentCB));
            
        }else{                      //Otherwise
            
            insertionSort(x, y, redImage, currentCR, 'r');
            insertionSort(x, y, greenImage, currentCG, 'g');
            insertionSort(x, y, blueImage, currentCB, 'b');
            
        }
        
        //Update the pixels' values
        redImage.update();
        greenImage.update();
        blueImage.update();
        
        //Set x = -1 and y = -1 when the whole image was scanned
        if (x == originalImage.width - 1 && y == originalImage.height - 1) {
            x = -1;
            y = -1;
        }
    }
    
    //Update x and y
    if (x != -1 && y != -1) {
        if (x == originalImage.width-1) {
            x = 0;
            y++;
        }else{
            x++;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Set the background color
    ofBackground(200, 200, 200);
    
    ofPushMatrix();
    ofTranslate(margin, margin);
    
    //Draw the original image
    ofSetColor(255, 255, 255);
    originalImage.draw(0, 0);
    
    //Draw the two lines which select the current pixel
    if (x >= 0 && y >= 0) {
        ofSetColor(255, 255, 255, 200);
        ofLine(0, y, originalImage.width, y);
        ofLine(x, 0, x, originalImage.height);
    }
    
    
    //Draw the sorted red channel
    ofPushMatrix();
    ofTranslate(originalImage.width+margin, 0);
    ofSetColor(255, 255, 255);
    redImage.draw(0, 0);
    ofPopMatrix();
    
    //Draw the sorted green channel
    ofPushMatrix();
    ofTranslate(0, originalImage.height+margin);
    ofSetColor(255, 255, 255);
    greenImage.draw(0, 0);
    ofPopMatrix();
    
    //Draw the sorted blue channel
    ofPushMatrix();
    ofTranslate(originalImage.width+margin, originalImage.height+margin);
    ofSetColor(255, 255, 255);
    blueImage.draw(0, 0);
    ofPopMatrix();
    
    ofPopMatrix();
    
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
