#shader vertex
#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;


void main()
{
	gl_Position =  Projection * View *  Model * vec4(aPos , 0.0F, 1.0);
	TexCoord = aTexCoord;
}




#shader fragment
#version 330 core

in vec2 TexCoord;

uniform sampler2D diffuse;

out vec4 FragColor;
void main()
{
	FragColor = texture(diffuse, TexCoord);
	if (FragColor.a < 0.2) discard;
	//FragColor = vec4(texture(diffuse, TexCoord).rgb, 1.0f);
}