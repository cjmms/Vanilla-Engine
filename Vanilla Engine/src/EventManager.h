#pragma once



enum EventType
{
	COLLISION,
	PLAYER_HIT,

	NUM
};




class Event
{
public:
	Event(EventType ptype) : type(ptype) {};
	virtual ~Event() {};

	
public:
	EventType type;
};




class EventManager
{
private:
	EventManager();

public:
	~EventManager();
	void BroadcastEvent(Event* event);

	void init(void);
	void close(void);

	EventManager(EventManager const&) = delete;
	void operator=(EventManager const&) = delete;

	static EventManager& getInstance(void);

};
