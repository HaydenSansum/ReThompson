//
//  flowField.h
//  reThompson_Magnetic
//
//  Created by Hayden on 10/3/20.
//

#ifndef _flowField
#define _flowField

#include "ofMain.h"

class flowField {
    
    public:
        flowField();
        int resolution;
        void set_resolution(int r);
        void draw_field(float lw);
        void set_forces(ofVec2f target, float max_noise_angle, float noise_scale);
        ofVec2f lookup_force(ofVec2f position);
    
    private:
        // Variables
        int num_rows;
        int num_cols;
        vector<vector<ofVec2f>> field_array;
        vector<ofVec2f> inner_vec;
    
};

#endif /* flowField_h */
