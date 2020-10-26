#include "UpDown.h"
#include "GameObject.h"


UpDown::UpDown()
	: Component(UP_DOWN), timer(1000.0f), movingUp(true), timerLimit(1000)
{}


UpDown::~UpDown() {}


void UpDown::update()
{
	timer -= FPSController::getInstance().getFrameTime();

	if ( timer < 0.0f )
	{
		timer = timerLimit;
		movingUp = !movingUp;
	}
	
	if (movingUp) owner->transform->moveUp();
	else owner->transform->moveDown();

}

void UpDown::Serialize(std::ifstream& stream)
{
	int up;

	stream >> up;
	stream >> timerLimit;

	timer = timerLimit;
	movingUp = (bool)up;
}