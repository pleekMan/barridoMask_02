// fragment shader

uniform vec2 scaling;
uniform vec2 mouse;
uniform float nearThreshold;
uniform float farThreshold;

uniform sampler2DRect backTex;
uniform sampler2DRect depthTex;

//varying vec2 coordes;

varying vec4 gl_TexCoord[];


void main()
{   

            
//FragCoord return ScreenSpace. Using scaling to correctly read pixels off the smaller kinect fbo
// cannot make TexCoords[0] work.. 

vec2 depthPoint = vec2(gl_FragCoord.x * scaling.x, gl_FragCoord.y * scaling.y);

//vec3 depthColors = texture2DRect(depthTex, depthPoint).rgb;
float whiteMask = texture2DRect(depthTex, depthPoint).r;
    //backColors = texture2DRect(backTex, gl_TexCoord[0].st).rgba;
vec3 backColors = texture2DRect(backTex, gl_FragCoord.xy).rgb;

/*
if (depthColors.r > nearThreshold && depthColors.r < farThreshold)
{
    gl_FragColor = vec4(backColors,1.0);
} else {
    gl_FragColor =  vec4(0.0,0.0,0.0,1.0);
}
 */
    
    gl_FragColor =  vec4(backColors * vec3(whiteMask,whiteMask,whiteMask),1);


}