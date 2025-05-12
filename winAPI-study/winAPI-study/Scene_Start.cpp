#include "pch.h"
#include "Scene_Start.h"

#include "Core.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "KeyMgr.h"
#include "Missile.h"

Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}



void Scene_Start::Enter()
{
	Object* obj = new Player;
	obj->setPos(Vec2(604.f, 348.f));
	obj->setScale(Vec2(100.f, 100.f));

	AddObject(obj, GROUP_TYPE::PLAYER);


	//Monster
	int monCount = 5;
	float moveDist = 25.f;
	float objScale = 50.f;
	Vec2 resoultion = Core::Instance()->getResolution();
	float term = (resoultion.x - ((moveDist + objScale / 2.f) * 2)) / (float)(monCount - 1);

	Monster* monObj = nullptr;
	for (int i = 0; i < monCount; ++i) {
		monObj = new Monster;
		monObj->SetCenterPos(Vec2((moveDist + objScale / 2.f) + (float)i * term, 50.f));
		monObj->setPos(Vec2(monObj->GetCenterPos()));
		monObj->SetMoveDist(moveDist);
		monObj->setScale(Vec2(objScale, objScale));
		AddObject(monObj, GROUP_TYPE::MONSTER);
	}
}

void Scene_Start::Update()
{
	if (KeyMgr::Instance()->GetKeyState(KEY::SPACE) == KEY_STATE::TAP) {
		Missile* obj = new Missile;
		
		obj->setScale(Vec2(10.f, 10.f));
		if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_STATE::HOLD
			&& KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_STATE::NONE
			) {
			obj->setdir(0, -1); 
			obj->setPos(Vec2(getPlayer()->getPos().x, getPlayer()->getPos().y - getPlayer()->getScale().y / 2.f));
		}
		else if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_STATE::HOLD
			&& KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_STATE::NONE
			)	{
			obj->setdir(-1, 0); 
			obj->setPos(Vec2(getPlayer()->getPos().x - getPlayer()->getScale().x / 2.f, getPlayer()->getPos().y));
		}
		else if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_STATE::HOLD
			&& KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_STATE::NONE
			)	{
			obj->setdir(0, 1); 
			obj->setPos(Vec2(getPlayer()->getPos().x, getPlayer()->getPos().y + getPlayer()->getScale().y / 2.f));
		}
		else if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_STATE::HOLD
			)	{
			obj->setdir(1, 0); 
			obj->setPos(Vec2(getPlayer()->getPos().x + getPlayer()->getScale().x / 2.f, getPlayer()->getPos().y));
		}
		else if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_STATE::HOLD
			&& KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_STATE::HOLD
			&& KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_STATE::NONE
			)	{
			obj->setdir(-1, -1); 
			obj->setPos(Vec2(getPlayer()->getPos().x - getPlayer()->getScale().x / 2.f, getPlayer()->getPos().y - getPlayer()->getScale().y / 2.f));
		}
		else if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_STATE::HOLD
			&& KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_STATE::HOLD
			)	{
			obj->setdir(1, -1); 
			obj->setPos(Vec2(getPlayer()->getPos().x + getPlayer()->getScale().x / 2.f, getPlayer()->getPos().y - getPlayer()->getScale().y / 2.f));
		}
		else if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_STATE::HOLD
			&& KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_STATE::HOLD
			&& KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_STATE::NONE
			)	{
			obj->setdir(-1, 1); 
			obj->setPos(Vec2(getPlayer()->getPos().x - getPlayer()->getScale().x / 2.f, getPlayer()->getPos().y + getPlayer()->getScale().y / 2.f));
		}
		else if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_STATE::NONE
			&& KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_STATE::HOLD
			&& KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_STATE::HOLD
			)	{
			obj->setdir(1, 1); 
			obj->setPos(Vec2(getPlayer()->getPos().x + getPlayer()->getScale().x / 2.f, getPlayer()->getPos().y + getPlayer()->getScale().y / 2.f));
		}
		else {
			obj->setdir(1, 0); 
			obj->setPos(Vec2(getPlayer()->getPos().x + getPlayer()->getScale().x / 2.f, getPlayer()->getPos().y));
		}
		AddObject(obj, GROUP_TYPE::MISSILE);
	}
	Scene::Update();
}

void Scene_Start::Exit()
{
}



// 다음주 한시간은 숙제검사
// 1) 지금까지 한 수업 + 코드관련해서 시각적으로 정리하기 (FlowChart
// 2) 플레이어를 기준으로 space를 누르면 미사일 발사하기
//