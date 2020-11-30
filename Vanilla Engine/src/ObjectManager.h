#pragma once

#include "GameObject.h"



class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void add(GameObject *object);
	static ObjectManager& getInstance(void);
	void update( void );
	//void HandleEvent(Event* event);
	void render( Shader& shader ) const;

	void close( void );


	std::vector<GameObject *> GameObjects;

};

