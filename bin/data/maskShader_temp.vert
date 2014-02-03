attribute vec4 position;

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;

attribute vec2 texcoord;

varying vec2 coordes;
 
void main(){
    //vec4 pos = projectionMatrix * modelViewMatrix * position;
    vec4 pos = modelViewProjectionMatrix * position;

	coordes = texcoord;
	gl_Position = pos;

}