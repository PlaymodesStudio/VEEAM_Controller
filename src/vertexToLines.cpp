//
//  vertexToLines.cpp
//  VEEAM_Controller
//
//  Created by Eduard Frigola Bagué on 16/07/2019.
//

#include "vertexToLines.h"

void vertexToLines::setup(){
    parameters->add(vertex.set("Vertex", {glm::vec2()}));
    parameters->add(doShader.set("do Shader", true));
    parameters->add(thickness.set("Thickness", 20, 1, 100));
    parameters->add(texture.set("Texture", nullptr));
    
    firstPass = false;
    
    shader.setGeometryInputType(GL_LINES);
    shader.setGeometryOutputType(GL_TRIANGLE_STRIP);
    shader.setGeometryOutputCount(4);
    shader.load("shaders/vert.glsl", "shaders/frag.glsl", "shaders/geom.glsl");
    
    ofLog() << "Maximum number of output vertices support is: " << shader.getGeometryMaxOutputCount();
}

void vertexToLines::update(ofEventArgs &a){
    if(firstPass){
        fbo.allocate(ofGetWidth(), ofGetHeight());
        firstPass = false;
    }
}

void vertexToLines::draw(ofEventArgs &a){
    fbo.begin();
    ofPushMatrix();
    
    if(doShader) {
        shader.begin();
        
        // set thickness of ribbons
        shader.setUniform1f("thickness", thickness);
        
        // make light direction slowly rotate
        shader.setUniform3f("lightDir", sin(ofGetElapsedTimef()/10), cos(ofGetElapsedTimef()/10), 0);
    }
    
    ofColor(255);
    
    //ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
//    ofRotateXDeg(mouseY);
//    ofRotateYDeg(mouseX);
    
    for(unsigned int i=1; i<vertex->size(); i++) {
        ofDrawLine(vertex.get()[i-1] * ofGetWidth(), vertex.get()[i]*ofGetHeight());
    }
    
    if(doShader) shader.end();
    
    ofPopMatrix();
    fbo.end();
    
    texture = &fbo.getTexture();
}
