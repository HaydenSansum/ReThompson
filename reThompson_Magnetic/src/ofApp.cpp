#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
  
    // Parameters
    int num_travellers = 250;
    int num_off_travellers = 40;
    int max_force = 1.0;
    int max_velocity = 20.0;
    int line_thickness = 1;
    
    
    ofBackground(224, 182, 62);
    ofSetBackgroundAuto(false);
    
    
    flowField.set_resolution(8);
    flowField.set_forces(ofVec2f(600,80), 1.5*PI, 180.0);
    
    for (int i = 0; i < num_travellers; i++) {
        traveller new_traveler;
        new_traveler.set_size(line_thickness);
        new_traveler.initialize(max_force, max_velocity);
        travellers.push_back(new_traveler);
    }
    
    for (int i = 0; i < num_off_travellers; i++) {
        traveller new_traveler;
        new_traveler.set_size(2);
        new_traveler.initialize(max_force, max_velocity);
        off_travellers.push_back(new_traveler);
    }
    
    // Get color palette
    set_colors();
    
    // Initialize draw cycle counter
    num_draw_cycles = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

//    flowField.set_forces(ofVec2f(mouseX,mouseY), 1.5*PI, 30.0);
    for (int i = 0; i < travellers.size(); i++) {
        travellers[i].pathfind(flowField);
        travellers[i].move();
    }
    
    for (int i = 0; i < off_travellers.size(); i++) {
           off_travellers[i].pathfind_90(flowField);
           off_travellers[i].move();
       }
    
    num_draw_cycles = num_draw_cycles + 1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSeedRandom(10);
    
//    flowField.draw_field(2.0);
    
    for (int i = 0; i < travellers.size(); i++) {
        
        float rand_f = ofRandom(1.0);
        
        // Calibrate the chance of random colors
        if (rand_f < 0.4) {
            ofSetColor(color_palette[0]);
        } else if (rand_f < 0.65) {
            ofSetColor(color_palette[1]);
        } else if (rand_f < 0.80) {
            ofSetColor(color_palette[2]);
        } else if (rand_f < 0.92) {
            ofSetColor(color_palette[3]);
        } else {
            ofSetColor(color_palette[4]);
        }
        
        int sub_i = i / 470;
        if (num_draw_cycles % (sub_i + 30) > 10) {
            travellers[i].draw();
        }
        
    }
    
    for (int i = 0; i < off_travellers.size(); i++) {
        
        float rand_f = ofRandom(1.0);
        
        // Calibrate the chance of random colors
        if (rand_f < 0.7) {
            ofSetColor(color_palette[0]);
        } else if (rand_f < 0.85) {
            ofSetColor(color_palette[1]);
        } else if (rand_f < 0.95) {
            ofSetColor(color_palette[2]);
        } else if (rand_f < 0.98) {
            ofSetColor(color_palette[3]);
        } else {
            ofSetColor(color_palette[4]);
        }
        
        off_travellers[i].draw();
    }
    
}

//--------------------------------------------------------------
void  ofApp::set_colors() {
    
    int num_colors = 5;
    int color_r[5] = {188, 104, 202, 87, 236};
    int color_g[5] = {48, 10, 74, 177, 108};
    int color_b[5] = {27, 17, 34, 220, 135};
    
    for (int i = 0; i < num_colors; i++) {
        color_palette.push_back(ofColor(color_r[i], color_g[i], color_b[i]));
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        img.grabScreen(0,0, ofGetWidth(), ofGetHeight());
        img.save(ofGetTimestampString() + ".png");
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
