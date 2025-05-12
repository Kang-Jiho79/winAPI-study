#include "pch.h"
#include "Missile.h"
#include "TimeMgr.h"


void Missile::Update()
{
	Vec2 curPos = getPos();
	curPos.x += fDT * 100.f * dir.x;
	curPos.y += fDT * 100.f * dir.y;
	setPos(curPos);
}
