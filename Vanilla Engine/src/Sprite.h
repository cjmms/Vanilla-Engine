#pragma once
class Sprite
{
public:
	Sprite();
	~Sprite();
	
	void update();
	
	GameObject* owner;

};

