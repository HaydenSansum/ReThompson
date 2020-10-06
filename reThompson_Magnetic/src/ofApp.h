#pragma once

#include "ofMain.h"
#include "flowField.h"
#include "traveller.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
        void set_colors();
    
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
        
    // Physics objects
    flowField flowField;
    vector<traveller> travellers;
    vector<traveller> off_travellers;
    
    // Colors
    vector<ofColor> color_palette;
    
    // On Off Counter
    int num_draw_cycles;
    
    // Screenshots
    ofImage img;
};
