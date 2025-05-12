#pragma once
#include "Object.h"

class Monster : public Object{
private:
	float		speed;
	float		maxDis;
	int			dir;
	Vec2		centerPos;	//중앙기준값
public:
	Monster();
	~Monster();

	virtual void Update();

	float GetSpeed() { return speed; }
	Vec2 GetCenterPos() { return centerPos; }

	void SetSpeed(float spd) { speed = spd; }
	void SetMoveDist(float dis) { maxDis = dis; }
	void SetCenterPos(Vec2 pos) { centerPos = pos; }
};

