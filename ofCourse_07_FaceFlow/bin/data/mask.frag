#version 450

uniform sampler2DRect mainTex;
uniform sampler2DRect maskTex;

out vec4 outputcolor;

in vec2 texCoordVarying;

void main(){
    float mask  = texture(maskTex, texCoordVarying).r;
    outputcolor = mask * texture(mainTex, texCoordVarying);

}