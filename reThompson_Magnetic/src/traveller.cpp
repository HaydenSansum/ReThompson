//
//  traveller.cpp
//  reThompson_Magnetic
//
//  Created by Hayden on 10/4/20.
//

#include <stdio.h>
#include "traveller.h"

traveller::traveller(){
}

void traveller::set_size(int size_set) {
    size = size_set;
}

void traveller::initialize(float mspeed, float mforce) {
    
    pos = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    vel = ofVec2f(0, 0);
    acc = ofVec2f(0, 0);
    
    max_speed = mspeed;
    max_force = mforce;
    
}

void traveller::draw() {
    ofDrawCircle(pos.x, pos.y, size);
}

void traveller::apply_force(ofVec2f force) {
    force.x = ofClamp(force.x, -max_force, max_force);
    force.y = ofClamp(force.y, -max_force, max_force);
    acc = acc + force;
}

void traveller::move() {
    // Update velocity
    vel = vel + acc;
    vel.x = ofClamp(vel.x, -max_speed, max_speed);
    vel.y = ofClamp(vel.y, -max_speed, max_speed);
    
    // Update Position
    pos = pos + vel;
    
    // Reset Acceleration
    acc = ofVec2f(0,0);
}

void traveller::pathfind(flowField flows) {
    ofVec2f applied_force = flows.lookup_force(pos);
    ofVec2f steering_force = applied_force - vel;
    
    steering_force.x = ofClamp(steering_force.x, -max_force, max_force);
    steering_force.y = ofClamp(steering_force.y, -max_force, max_force);
    
    apply_force(steering_force);
}

void traveller::pathfind_90(flowField flows) {
    ofVec2f applied_force = flows.lookup_force(pos);
    ofVec2f perpendicular_force = applied_force.getRotatedRad(PI/2);
    ofVec2f steering_force = perpendicular_force - vel;
    
    steering_force.x = ofClamp(steering_force.x, -max_force, max_force);
    steering_force.y = ofClamp(steering_force.y, -max_force, max_force);
    
    apply_force(steering_force);
}

