#pragma once
#include <list>
#include <unordered_map>

class GameObject;


enum EventType
{
	COLLISION,
	PLAYER_HIT,

	NUM
};




class Event
{
public:
	Event(EventType ptype, float t) : type(ptype), timer(t) {};
	Event(EventType ptype) : type(ptype), timer(0.0f) {};
	virtual ~Event() {};

	
public:
	EventType type;
	float timer;
};




class EventManager
{
private:
	EventManager();

public:
	// not used
	std::list<Event*> events;
	std::list<std::pair<Event*, GameObject*>> subs;

	~EventManager();
	void BroadcastEvent(Event* event);
	// not used
	void AddEvent(Event* event);

	void init(void);
	void close(void);

	EventManager(EventManager const&) = delete;
	void operator=(EventManager const&) = delete;

	static EventManager& getInstance(void);

	void update(float frameTime);

	void Subscribe(Event* event, GameObject* obj);

	

};
