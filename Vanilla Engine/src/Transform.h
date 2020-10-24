#pragma once


class Transform
{

public:
	Transform();
	~Transform();
	
	void update();

	float x, y;
	GameObject* owner;

};

