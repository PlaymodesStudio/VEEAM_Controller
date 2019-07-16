#include "ofApp.h"
#include "oscillatorTexture.h"
#include "waveScope.h"
#include "positionsCreator.h"
#include "vertexToLines.h"
#include "graphicPatternGenerator.h"
#include "polylinesSVGRenderer.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
    auto reg = make_shared<ofxOceanodeNodeRegistry>();
    auto treg = make_shared<ofxOceanodeTypesRegistry>();
    reg->registerModel<oscillatorTexture>("LedNodes");
    reg->registerModel<waveScope>("LedNodes");
    reg->registerModel<positionsCreator>("VECTOR");
    reg->registerModel<vertexToLines>("VECTOR");
    reg->registerModel<graphicPatternGenerator>("VECTOR");
    reg->registerModel<polylinesSVGRenderer>("VECTOR");
//    reg->registerModel<senderManager>("LedNodes");
//    reg->registerModel<colorApplier>("LedNodes");
//    reg->registerModel<textureRecorder>("LedNodes");
//    reg->registerModel<scriptModule>("Scripting");
//    reg->registerModel<textureUnifier>("LedNodes");
    treg->registerType<ofTexture*>();
    treg->registerType<vector<pair<ofPolyline, ofColor>>>();
    treg->registerType<vector<glm::vec2>>();
    
    
    container = make_shared<ofxOceanodeContainer>(reg, treg);
    canvas.setContainer(container);
    canvas.setup();
    
    controls = make_shared<ofxOceanodeControls>(container);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
