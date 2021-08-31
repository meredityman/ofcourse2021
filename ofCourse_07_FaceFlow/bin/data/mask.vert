#version 450

uniform mat4 modelViewProjectionMatrix;
uniform vec2 size;

in vec4 texcoord;
in vec4 position;
out vec2 texCoordVarying;

void main()
{
    texCoordVarying = vec2(texcoord.x, size.y - texcoord.y);
	gl_Position = modelViewProjectionMatrix * position;
}