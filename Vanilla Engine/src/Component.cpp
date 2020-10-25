#include "Component.h"


Component::Component(ComponentType cType)
	: type(cType), owner(nullptr)
{
}


Component::~Component(){}