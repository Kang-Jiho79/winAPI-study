#pragma once
class TimeMgr
{
	SINGLE(TimeMgr);
private:
	LARGE_INTEGER curCount;
	LARGE_INTEGER prevCount;
	LARGE_INTEGER frequency;

	double		dDT;
	double		dAcc;
	UINT		iCallCount;
	UINT		iFPS;

public:
	void		init();
	void		Update();

	double		getDT() { return dDT; }
	float		getfDT() { return (float)dDT; }
};


// ���� ������ �ð��� "FPS"�� ǥ���ȴ�.

// �������� ������ == �� ������ �� �ɸ��� �ð�
// 
// LARGE_INTEGER : 64bit ������
// 1. curCount : ���� �ð�
// 2. prevCount : ���� �ð�
// 3. frequency : ���� ī���Ͱ� �ʴ� ��� �ƴ� ? (�ֱ�)
// 
// dDt : �� ������ ������ �ð� �� ( curCount - prevCount -> �ý��� ���� ī���� ���ļ��� ������ �� )
// dAcc : ���� ��� �ð� ( 1�ʸ� �ʰ��ϸ� FPS ����ϰ� �ʱ�ȭ )
// iCallCount : Update�Լ��� ȣ�� Ƚ�� ����
// iFPS : ������ �ӵ� ( = 1�ʴ� Update ȣ�� Ƚ�� )
//