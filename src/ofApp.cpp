#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    maxParti = 50;
    p.assign(maxParti, expParticle());
    
    partiNum = 0;
    
    ofBackground(8, 12, 32);

}

//--------------------------------------------------------------
void ofApp::update(){

    for(unsigned int i = 0; i < p.size(); i++){
        p[i].update();
    }
    
    
    for(unsigned int i = 0; i < p.size(); i++){
        p1 = p[i].particlePos;
        
        bool close = false;
        
        for(unsigned int j = 0; j < p.size(); j++){
            p2 = p[j].particlePos;
            
            float distn = p1.distance( p2 );
//            ofLog(OF_LOG_NOTICE, "the number is " + ofToString(distn));
            if (distn > 10 && distn < 100){
                close = true;
            }
        }
        
//        float distn = p1.distance( p2 );
        
        if(close){
            p[i].haloColour = ofColor(250,80,50,120);
        } else {
           p[i].haloColour = ofColor(0,120,250,120);
        }
    }


    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if( key == 'h'){
        for(unsigned int i = 0; i < p.size(); i++){
            p[i].movePart(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        }
    }
    
    if( key == 'j'){
        p[partiNum].reset(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        
        if(partiNum < (maxParti-1)) {
            partiNum += 1;
        } else {
            partiNum = 0;
            
        }
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
    p[partiNum].reset(x,y);
    

    if(partiNum < (maxParti-1)) {
       partiNum += 1;
    } else {
        partiNum = 0;

    }
    
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
