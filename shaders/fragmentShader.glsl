#version 100

precision mediump float;

varying vec2 Texcoord;
varying vec3 Color;

uniform sampler2D texImage;

void main()
{
    if (Texcoord.x < 0.0 && Texcoord.y < 0.0) {
        gl_FragColor = vec4(Color, 1.0);
    } else {
        gl_FragColor = texture2D(texImage, Texcoord);
    }
}
