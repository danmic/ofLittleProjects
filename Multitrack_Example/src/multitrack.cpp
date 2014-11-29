#include "multitrack.h"

/////////////////////////////////////////////////////////////////
multitrack::multitrack(const string& path){
    //Define ofDirectory from the path
    ofDirectory dir(path);
    
    //Only show wav files
    dir.allowExt("mp3");
    
    //Populate the directory object
    dir.listDir();
    
    for (int i = 0; i != dir.numFiles(); i++) {
        
        tracks.push_back(ofSoundPlayer());
        auto trackPtr = tracks.rbegin();
        //Load the current track
        trackPtr->loadSound(dir.getPath(i));
        
        //Add the track's volume to the vector vols
        vols.push_back(0);
        
        //Add 0 to selectedTracks vector (No track is selected)
        selectedTracks.push_back(false);
    }
    
    n = tracks.size();
    positions = vector<ofPoint>(n);
    
}


/////////////////////////////////////////////////////////////////
void multitrack::setup(){
    
    for(int i = 0; i != n; i++){
        //Loop the track
        tracks[i].setLoop(true);
        //Set the volume
        tracks[i].setVolume(0.5);
        //Update vols
        vols[i] = tracks[i].getVolume();
        //Play the track
        tracks[i].play();
        
    }
    
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    minRadius = min(w, h) / 6.0;
    maxRadius = minRadius + min(w, h) / 4.0;
    center = ofPoint(w/2, h/2);
    angle = float(360) / n;
    trackRadius = 8;
    
    pause = false;
    
    //Set palette
    
    //Selected Track && mouse over
    palette.push_back(ofColor(0,109,44));
    //Selected Track && mouse away
    palette.push_back(ofColor(49,163,84));
    //Not selected Track && mouse over
    palette.push_back(ofColor(116,196,118));
    //Not selected Track && mouse away
    palette.push_back(ofColor(199,233,192));
    
    deltaVol = 0.01;
}


/////////////////////////////////////////////////////////////////
void multitrack::update(bool volumeUP, bool volumeDOWN){
    
    //Update the volumes of the selected tracks
    for (int i = 0; i < n; i++) {
        
        float d = vols[i];
        
        if (volumeUP) {
            d += deltaVol;
        }else if (volumeDOWN){
            d -= deltaVol;
        }
        
        if (selectedTracks[i]) {
            vols[i] = ofClamp(d, 0, 1);
        }
        
    }
    

    //Set the volumes of tracks and
    //update the vector positions
    //according to vols
    for (int i = 0; i < n; i++) {
        
        tracks[i].setVolume(vols[i]);
        
        float length = ofMap(vols[i], 0, 1, minRadius, maxRadius, true);
        
        ofPoint position(0, length);
        position.rotate(i*angle, ofPoint(0, 0, 1));
        position += center;
        
        positions[i] = position;
        
    }

}


/////////////////////////////////////////////////////////////////
void multitrack::toggleTrackSelection(int mouseX, int mouseY){
    
    for (int i = 0; i < n; i++) {
        
        if ( ofDist(mouseX, mouseY, positions[i].x, positions[i].y) <= trackRadius ) {
            selectedTracks[i] = !selectedTracks[i];
        }
        
    }
    
}

/////////////////////////////////////////////////////////////////
void multitrack::togglePlayer(){
    
    pause = !pause;
    for(ofSoundPlayer track : tracks){
        track.setPaused(pause);        
    }
        
}

/////////////////////////////////////////////////////////////////
void multitrack::display(int mouseX, int mouseY) const{
    
    //Draw the tracks as little circles
    for (int i = 0; i < n; i++) {
        
        float distance = ofDist(mouseX, mouseY, positions[i].x, positions[i].y);
        bool mouseOver = distance <= trackRadius;
        
        //Set color
        if (selectedTracks[i] && mouseOver) {
            ofSetColor(palette[0]);
        }else if(selectedTracks[i] && !mouseOver){
            ofSetColor(palette[1]);
        }else if(!selectedTracks[i] && mouseOver){
            ofSetColor(palette[2]);
        }else{ //if(!selectedTracks[i] && mouseOver)
            ofSetColor(palette[3]);
        }
        
        ofCircle(positions[i], trackRadius);
        
    }
    
}











