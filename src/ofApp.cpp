#include "ofApp.h"
#include "oscillatorTexture.h"
#include "waveScope.h"

//--------------------------------------------------------------
void ofApp::setup(){
    auto reg = make_shared<ofxOceanodeNodeRegistry>();
    auto treg = make_shared<ofxOceanodeTypesRegistry>();
    reg->registerModel<oscillatorTexture>("LedNodes");
    reg->registerModel<waveScope>("LedNodes");
//    reg->registerModel<senderManager>("LedNodes");
//    reg->registerModel<colorApplier>("LedNodes");
//    reg->registerModel<textureRecorder>("LedNodes");
//    reg->registerModel<scriptModule>("Scripting");
//    reg->registerModel<textureUnifier>("LedNodes");
    treg->registerType<ofTexture*>();
    
    
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