#shader vertex
#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform vec2 position;
void main()
{
	gl_Position = vec4(aPos.x + position.x, aPos.y + position.y, 0.0F, 1.0);
	TexCoord = aTexCoord;
}




#shader fragment
#version 330 core

in vec2 TexCoord;

uniform sampler2D diffuse;

out vec4 FragColor;
void main()
{
	FragColor = vec4(texture(diffuse, TexCoord).rgb, 1.0f);
}