#pragma once
#include "Object.h"

class Missile : public Object{
private:
	POINT	dir;
public:
	void setdir(int x, int y) { dir.x = x; dir.y = y; };
	virtual void Update();
};

