#version 410

uniform mat4 modelViewProjectionMatrix;
layout(location = 0) in vec4  position;

void main()
{
//    gl_FrontColor =  gl_Color;
//    gl_TexCoord[0] = gl_MultiTexCoord0;
//    gl_Position = gl_Vertex;
    gl_Position = modelViewProjectionMatrix * position;
}
