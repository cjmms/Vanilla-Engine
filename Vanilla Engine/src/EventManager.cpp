#include "EventManager.h"
#include "ObjectManager.h"

EventManager::EventManager() 
{};


EventManager::~EventManager() {};



void EventManager::BroadcastEvent(Event* event)
{
	for (GameObject* obj : ObjectManager::getInstance().GameObjects) obj->HandleEvent(event);
}



void EventManager::init(void)
{}



void EventManager::close(void)
{}


EventManager& EventManager::getInstance(void)
{
	static EventManager pMgr;
	return pMgr;
}
