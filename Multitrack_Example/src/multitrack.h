#pragma once
#include "ofMain.h"

class multitrack {
public:
    
    //Constructors
    multitrack() : n(0) { }
    multitrack(const string& path);
    
    //Set up parameters
    void setup();
    
    //Update parameters
    void update(bool volumeUP, bool volumeDown);
    
    //Toggle the parameters inside selectedTracks if called
    void toggleTrackSelection(int mouseX, int mouseY);
    
    //Unselect all tracks
    void unselectAll(){
        selectedTracks = vector<bool>(n, false);
    }
    
    //Select all tracks
    void selectAll(){
        selectedTracks = vector<bool>(n, true);        
    }
    
    //Toggle the player
    void togglePlayer();
    
    //Display track's volume on screen
    void display(int mouseX, int mouseY) const;
    
private:
    
    //Vector of tracks
    vector<ofSoundPlayer> tracks;
    //Number of tracks
    int n;
    //Vector of tracks' volumes
    vector<float> vols;
    //Pause/Resume tracks
    bool pause;
    
    //Display Parameters
    
    //Maximum and minimum values of the main circle's radius
    float maxRadius, minRadius;
    //Main circle's center
    ofPoint center;
    //Angle between two consecutive tracks
    float angle;
    //Radius of the track
    float trackRadius;
    //Vector of points' position in display method
    vector<ofPoint> positions;
    //Vector with palette
    vector<ofColor> palette;
    
    //Speed of volume variation
    float deltaVol;
    
    //Vector which store false if the track is not selected and true otherwise
    vector<bool> selectedTracks;
    
};