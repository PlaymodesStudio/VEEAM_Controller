//
//  positionsRotator.h
//  Espills_controller
//
//  Created by Eduard Frigola on 28/08/2018.
//

#ifndef positionsRotator_h
#define positionsRotator_h

#include "ofxOceanodeNodeModel.h"

class positionsRotator : public ofxOceanodeNodeModel{
public:
    positionsRotator() : ofxOceanodeNodeModel("Positions Rotator"){}
    ~positionsRotator(){};
    
    void setup() override{
        parameters->add(input.set("Input", {glm::vec2()}));
        parameters->add(rotation.set("Rotation", 0, 0, 1));
        parameters->add(output.set("Output", {glm::vec2()}));
        
        listener = input.newListener([&](vector<ofPoint> &points){
            vector<glm::vec2> tempOut;
            tempOut.resize(points.size());
            for(int i = 0; i < points.size(); i++){
                float x = ofMap(points[i].x, 0, 1, -1, 1);
                float y = ofMap(points[i].y, 0, 1, -1, 1);
                float rotated_x = (x*cos(rotation*2*PI)) - (y*sin(rotation*2*PI));
                float rotated_y = (y*cos(rotation*2*PI)) + (x*sin(rotation*2*PI));
                tempOut[i] = glm::vec2(ofMap(rotated_x, -1, 1, 0, 1),ofMap(rotated_y, -1, 1, 0, 1));
            }
            output = tempOut;
        });
    }
    
private:
    ofEventListener listener;
    ofParameter<vector<glm::vec2>> input;
    ofParameter<vector<glm::vec2>> output;
    ofParameter<float> rotation;
};

#endif /* positionsRotator_h */
