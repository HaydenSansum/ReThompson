//
//  flowField.cpp
//  reThompson_Magnetic
//
//  Created by Hayden on 10/3/20.
//

#include <stdio.h>
#include "flowField.h"

flowField::flowField(){
}

void flowField::set_resolution(int r) {
    resolution = r;
    num_rows = ofGetHeight() / resolution;
    num_cols = ofGetWidth() / resolution;
}

void flowField::set_forces(ofVec2f target, float max_noise_angle, float noise_scale) {
    
    // Initialize the array with zero vectors to represent the flow field
    field_array.clear();
    for (int i = 0; i < num_rows; i++) {
        inner_vec.clear();
        for (int j = 0; j < num_cols; j++) {
            inner_vec.push_back(ofVec2f(0,0));
        }
        field_array.push_back(inner_vec);
    }
    
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            
            float angular_noise = ofNoise(j/noise_scale, i/noise_scale);
            float scaled_angle_noise = ofMap(angular_noise, 0, 1, -max_noise_angle/2.0, max_noise_angle/2.0);
            
            ofVec2f current_pos = ofVec2f(j * resolution, i * resolution);
            ofVec2f force = target - current_pos;
            ofVec2f noisy_force = force.getRotatedRad(scaled_angle_noise);
            field_array[i][j] = noisy_force.getNormalized();
        }
    }
    
}

ofVec2f flowField::lookup_force(ofVec2f position) {
    
    int nearest_row = floor(position.y / resolution);
    int nearest_col = floor(position.x / resolution);
    
    return field_array[nearest_row][nearest_col];
    
}
    

void flowField::draw_field(float lw) {
    
    ofSetLineWidth(lw);
    ofSetColor(200);
    
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {

            ofVec2f current_pos = ofVec2f(j * resolution, i * resolution);
            ofVec2f current_force = field_array[i][j];
            ofVec2f arrow_end = current_pos + (current_force * 10);
            
            ofDrawArrow(ofVec3f(current_pos.x, current_pos.y, 0),
                        ofVec3f(arrow_end.x, arrow_end.y, 0), lw+1);
            
        }
    }
    
}
