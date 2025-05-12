#include "pch.h"
#include "Object.h"

#include "KeyMgr.h";
#include "TimeMgr.h"

Object::Object()
	: vPos{}
	, vScale{}
{
}

Object::~Object()
{
}

void Object::Update()
{
	
}

void Object::Render(HDC _hdc)
{
	Rectangle(_hdc,
		(int)(vPos.x - vScale.x / 2.f),
		(int)(vPos.y - vScale.y / 2.f),
		(int)(vPos.x + vScale.x / 2.f),
		(int)(vPos.y + vScale.y / 2.f));
}
