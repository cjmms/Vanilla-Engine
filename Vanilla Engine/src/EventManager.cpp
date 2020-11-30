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



void EventManager::update(float frameTime)
{
	for (auto i = events.begin(); i != events.end();) {
		Event* e = *i;
		e->timer -= frameTime;		// decrease time for each event

		if (e->timer <= 0.0f)		// trigger the event when timer reachs 0
		{
			BroadcastEvent(e);
			delete e;
			i = events.erase(i);
		}
		else ++i;
	}
}



void EventManager::close(void)
{}


EventManager& EventManager::getInstance(void)
{
	static EventManager pMgr;
	return pMgr;
}


void EventManager::AddDelayedEvent(Event* event)
{
	events.push_back(event);

}