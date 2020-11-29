#pragma once
class EventManager
{
};


enum EventType
{
	COLLISION,

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


