#version 450

// this is how we receive the texture
uniform sampler2DRect tex0;
uniform vec2 mousePosition;
uniform float myTime;


in vec2 texCoordVarying;

out vec4 outputColor;
 
void main()
{
    vec2 coord = texCoordVarying;
    coord.x += 50 * sin((coord.y / 20) + (myTime / 100));
    outputColor = texture(tex0, coord);
}