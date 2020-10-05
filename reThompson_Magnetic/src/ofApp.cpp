#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
  
    ofBackground(0);
//    ofSetBackgroundAuto(false);
    
    flowField.set_resolution(20);
    flowField.set_forces(ofVec2f(400,400), PI, 10.0);
    
    for (int i = 0; i < 20; i++) {
        traveller new_traveler;
        new_traveler.set_size(10);
        new_traveler.initialize(1.5, 10.0);
        travellers.push_back(new_traveler);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

    flowField.set_forces(ofVec2f(mouseX,mouseY), PI, 10.0);
    for (int i = 0; i < travellers.size(); i++) {
        travellers[i].pathfind(flowField);
        travellers[i].move();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSeedRandom(10);
    
    flowField.draw_field(2.0);
    
    for (int i = 0; i < travellers.size(); i++) {
        ofSetColor(ofRandom(255), 50, 42);
        travellers[i].draw();
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
