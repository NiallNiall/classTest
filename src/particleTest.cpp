//
//  particleTest.cpp
//  classTest
//
//  Created by Niall Henn on 31/03/2015.
//
//

#include "particleTest.h"

//------------------------------------------------------------------
expParticle::expParticle(){
    
    particleAlive = false;
    
    particleDir = 1;
//    haloRad = 100;

    
}

void expParticle::reset(int partX, int partY){
    particlePos = ofVec2f(partX, partY);
    particleDestPos = particlePos;
    particleAlive = true;
    
//    haloRad = 100;
   
    particleRad = 0;
    particleGrowing = true;
    haloRad = 0;
    haloGrowing = true;

    
//    maxPartiSize = ofRandom(4,50);
    maxPartiSize = 30;
    
    maxHaloSize = ofRandom(200,400);
    
    partiEasing = 0.05;
}

//------------------------------------------------------------------
void expParticle::update(){
    

    
    if (particleGrowing) {
        particleRad += 0.7;
    }
   
    if (particleRad > maxPartiSize) {
        particleGrowing = false;
    }
    
    if (haloGrowing) {
        haloRad += 1.4;
    }
    
    if (haloRad > maxHaloSize) {
        haloGrowing = false;
    }

    if(particleMoving){
        particleD = particleDestPos - particlePos;
        
        if(ABS(particleD.x) > 1) {
            particlePos.x += particleD.x * partiEasing;
        }
        
        if(ABS(particleD.y) > 1) {
            particlePos.y += particleD.y * partiEasing;
        }
    }
    
    if(particlePos == particleDestPos) {
        particleMoving = false;
    }
    
//    haloRad += 0.6 * particleDir;

//    haloRad = particleRad * 5;
    
//    if (haloRad > 120 || haloRad < 80 ) {
//        particleDir *= -1;
//    }
//    
}

//------------------------------------------------------------------
void expParticle::draw(){
    


    if (particleAlive) {
        ofSetColor(250, 250, 250);
        ofCircle(particlePos.x, particlePos.y, particleRad);
        
        
        ofSetColor(120, 170, 200, 140);
        for(int i=0;i<360;i+=1){
            float angle = i * TWO_PI / 360;
            float x = particlePos.x + cos(angle) * ofRandom(haloRad -10, haloRad +10);
            float y = particlePos.y + sin(angle) * ofRandom(haloRad -10, haloRad +10);
            ofCircle(x,y, 5);

        }
        
        
    }

}

//------------------------------------------------------------------
void expParticle::movePart(int partX, int partY){
    particleDestPos = ofVec2f(partX, partY);
    particleMoving = true;
    
}