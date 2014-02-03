#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform vec2 resolution;

uniform sampler2DRect backTex;



void main( void ) 
{
    float sum = 0.0;
    float size = resolution.x / 3.0;
    float g = 0.6;
    int num = 500;
    
    for (int i = 0; i < 8; i++) 
    {
        vec2 position = resolution / 2.0;
        
        position.x += sin(time*0.05 / 1.0 * float(i * 2)) * resolution.x * 0.15;
        position.y += cos(time*0.05 / 0.3 + (2.0 + sin(1.0)) * float(i)) * resolution.y * 0.25;
        
        float dist = length(gl_FragCoord.xy - position);
        
        sum += size / pow(dist, g);
    }


    vec3 backColor = texture2DRect(backTex, gl_FragCoord.xy).rgb;
    
    vec4 color = vec4(0,0,0,1);
    float val = sum / float(num);
    color = vec4(0, val * 0.8, val, 1);
    color *= vec4(backColor,1);

    //gl_FragColor = vec4(color);
    gl_FragColor = vec4(backColor,1.0);
}