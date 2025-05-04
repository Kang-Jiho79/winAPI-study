#pragma once

// Ű �Է� �̺�Ʈ ����
enum class KEY_STATE {
	NONE,		/*���� �����ӿ��� ������ �ʰ� ���� �����ӿ��� ������ ����*/
	TAP,		/*���� �����ӿ��� ������ �ʰ� ���� �����ӿ��� ����*/
	HOLD,		/*���� �����ӿ��� ���� ���� �����ӿ��� ����*/
	AWAY,		/*���� �����ӿ� ���� ���� �����ӿ� ������ ����(�� ��)*/
};

// ������ Ű ����
enum class KEY {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,
	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LAST,
};


// Ű ���� ����ü
struct KeyInfo
{
	KEY_STATE	state;
	bool		perv;
};

class KeyMgr
{
	SINGLE(KeyMgr);
private:
	vector<KeyInfo>		vecKey;			// Ű ���� ������ �����ϴ� ����


public:
	void Init();
	void Update();

public:
	KEY_STATE GetKeyState(KEY key) { return vecKey[(int)key].state; };
};

