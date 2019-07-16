//
//  vertexToLines.h
//  VEEAM_Controller
//
//  Created by Eduard Frigola Bagué on 16/07/2019.
//

#ifndef vertexToLines_h
#define vertexToLines_h

#include "ofxOceanodeNodeModel.h"

class vertexToLines : public ofxOceanodeNodeModel{
public:
    vertexToLines() : ofxOceanodeNodeModel("Vertex To Lines"){};
    ~vertexToLines(){};
    
    void setup();
    void update(ofEventArgs &a);
    void draw(ofEventArgs &a);
    
private:
    ofParameter<vector<glm::vec2>> vertex;
    ofParameter<bool> doShader;
    ofParameter<int> thickness;
    ofParameter<ofTexture*> texture;
    ofShader shader;
    ofFbo fbo;
    bool firstPass;
};

#endif /* vertexToLines_h */
