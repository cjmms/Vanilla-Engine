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
	void deleteObj();
	void remove(GameObject* object);
	bool find(GameObject* object) const;
	GameObject* findEnemy(bool isHostile);

	void render( Shader& shader ) const;

	void close( void );

	int FindTerminalHealth();
	



	std::vector<GameObject *> GameObjects;
private:
	void createObj();

};

