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
