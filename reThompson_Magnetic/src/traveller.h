//
//  traveller.h
//  reThompson_Magnetic
//
//  Created by Hayden on 10/4/20.
//

#ifndef _traveller
#define _traveller

#include "ofMain.h"
#include "flowField.h"

class traveller {
    
    public:
        traveller();
        void set_size(int size);
        void initialize(float mspeed, float mforce);
        void draw();
        void apply_force(ofVec2f force);
        void move();
        void pathfind(flowField flows);
    
    private:
        // Variables
        int size;
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f acc;
        float max_speed;
        float max_force;
    
};

#endif /* traveller_h */
