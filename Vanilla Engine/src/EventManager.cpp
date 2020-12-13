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


// iterate all the events inside event list and trigger them base on time
void EventManager::update(float frameTime)
{
	for (auto i = subs.begin(); i != subs.end();) {
		std::pair<Event*, GameObject*> p = *i;

		Event* e = p.first;
		GameObject* obj = p.second;

		if (obj != nullptr) obj->HandleEvent(e);
		delete e;
		i = subs.erase(i);
	}
}



void EventManager::close(void)
{}


EventManager& EventManager::getInstance(void)
{
	static EventManager pMgr;
	return pMgr;
}


void EventManager::AddEvent(Event* event)
{
	events.push_back(event);
}



void EventManager::Subscribe(Event* event, GameObject* obj)
{
	subs.push_back(std::make_pair(event, obj));
}
