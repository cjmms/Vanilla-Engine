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
	for (auto i = events.begin(); i != events.end();) {
		Event* e = *i;
		e->timer -= frameTime;		// decrease time for each event

		if (e->timer <= 0.0f)		// trigger the event when timer reachs 0
		{
			//BroadcastEvent(e);
			BroadcastEventToSubs(e);
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


void EventManager::AddEvent(Event* event)
{
	events.push_back(event);

}



void EventManager::Subscribe(EventType type, GameObject* obj)
{
	std::vector<GameObject*>& listOfSubs = subs[type];

	for (auto p : listOfSubs)	// check if it's subscribed already
		if (p == obj) return;
	
	listOfSubs.push_back(obj);
}

void EventManager::BroadcastEventToSubs(Event* event)
{
	std::vector<GameObject*>& listOfSubs = subs[event->type];

	for (auto p : listOfSubs) if (p != nullptr) p->HandleEvent(event);

	subs.erase(event->type);
}