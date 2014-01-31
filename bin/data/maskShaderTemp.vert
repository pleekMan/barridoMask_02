uniform mat4 modelViewProjectionMatrix;
vec4 position;
 
void main(){
    gl_Position = modelViewProjectionMatrix * position;
}