#ifndef COMPONENT_H
#define COMPONENT_H

#include "GameObject.h"


class Component {
	Component(GameObject& associated);
	~Component();

	virtual void Update(float dt);
	virtual void Render();


};


#endif