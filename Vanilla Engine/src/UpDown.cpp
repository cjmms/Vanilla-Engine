#include "UpDown.h"
#include "GameObject.h"


UpDown::UpDown() 
	: Component(UP_DOWN), timer(1000.0f), movingUp(true)
{}


UpDown::~UpDown() {}


void UpDown::update()
{
	timer -= FPSController::getInstance().getFrameTime();

	if ( timer < 0.0f )
	{
		timer = 1000.0f;
		movingUp = !movingUp;
	}
	
	if (movingUp) owner->transform->moveUp();
	else owner->transform->moveDown();

}