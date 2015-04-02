//
//  particleTest.h
//  classTest
//
//  Created by Niall Henn on 31/03/2015.
//
//

#ifndef __classTest__particleTest__
#define __classTest__particleTest__

#include <stdio.h>
#include "ofMain.h"

class expParticle{
    
public:
    expParticle();
    
    void reset(int partX, int partY);
    void update();
    void draw();
    
    void movePart(int partX, int partY);
    
    ofVec2f particlePos, particleDestPos, particleD;
    
    bool particleAlive;
    
    float particleRad;
    float particleDir;
    
    float haloRad;
    bool particleGrowing;

    bool haloGrowing;
    
    float maxPartiSize, maxHaloSize;
    float partiEasing;
    bool particleMoving;

};

#endif /* defined(__classTest__particleTest__) */
