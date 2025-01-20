#pragma once
#include "Level/Level.h"
#include "Level/MenuItem.h"
#include <vector>

class MainGameLevel : public Level
{

	RTTI_DECLARATIONS(MainGameLevel, Level)
public:
	MainGameLevel();
	virtual ~MainGameLevel();

	void Draw() override;
	void Update(float daltaTime) override;

private:
	// ���� ���õ� �޴� ��ȣ (�ε���).
	int currentSelectedIndex = 0;

	// menuItems�� ������ üũ ����.
	int menuItemsCount = 0;

private:
	// �޴��� ��� ����.
	std::vector<MenuItem*> menuItems;
};