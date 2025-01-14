#pragma once
#include <Actor/DrawableActor.h>

class PlayerBullet : public DrawableActor
{
	RTTI_DECLARATIONS(PlayerBullet, DrawableActor)
public:
	// ź���� ������ �� ��ġ�� ���� �޾ƾ� ��.
	PlayerBullet(const Vector2& position);

	virtual void Update(float deltaTime) override;
private:

	// �̵� ���� ����.
	// �̵� �ӷ�(���� : ĭ/��)
	float speed = 5.0f;

	// y��
	float yPosition = 0.0f;
};