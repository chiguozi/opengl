#version 330 core

out vec4 FragColor;

in vec2 Texcoords;

uniform sampler2D texture1;

void main()
{
    FragColor = texture(texture1, Texcoords);
    float average = 0.2126 * FragColor.r + 0.7152 * FragColor.g + 0.0722 * FragColor.b;
    FragColor = vec4(average, average, average, 1.0);
}

//void main()
//{
//    FragColor = texture(texture1, Texcoords);
//    float average = (FragColor.r + FragColor.g + FragColor.b) / 3.0;
//    FragColor = vec4(average, average, average, 1.0);
//}