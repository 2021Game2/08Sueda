#include "CBullet.h"
#include "CCollisionManager.h"
#include "CXPlayer.h"
#define FIRECOUNT 60

CBullet::CBullet()
: mLife(50)
, mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.5f)
, mFireCount(FIRECOUNT)
{
	
}

//���Ɖ��s���̐ݒ�
//Set(��, ���s)
void CBullet::Set(float w, float d) {
	//�X�P�[���ݒ�
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//�O�p�`�̒��_�ݒ聨3
	mT.SetVertex(CVector(w, 0.0f, 0.0f), CVector(0.0f, 0.0f, -d), CVector(-w, 0.0f, 0.0f));
	//�O�p�`�̖@���ݒ�
	mT.SetNormal(CVector(0.0f, 1.0f, 0.0f));
}

//�X�V
void CBullet::Update() {
	if (mFireCount > 0) {
		mFireCount--;
	}
	//�������Ԃ̔���
	if (mLife-- > 0) {
		CTransform::Update();
		//�ʒu�X�V
		mPosition = CVector(0.0f, 0.0f, 1.0f) * mMatrix;
	}
	else {
		//�����ɂ���
		mEnabled = false;
	}

	//�v���C���[��HP��0�ɂȂ�����e���o���Ȃ�����
	if (CXPlayer::spInstance->mHp == 0) {
		mEnabled = false;
	}
}

//�`��
void CBullet::Render() {
	//DIFFUSE�D�F�ݒ�
	float c[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//�O�p�`�`�恨12
	mT.Render(mMatrix);
//	mCollider.Render();
}

//�Փˏ���
//Collision(�R���C�_1, �R���C�_2)
void CBullet::Collision(CCollider *m, CCollider *o) {
	switch (o->mType)
	{
	case CCollider::ETRIANGLE: //�O�p�R���C�_�̎�
		CVector adjust;  //�����l
		//�O�p�R���C�_�Ƌ��R���C�_�̏Փ˔���
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{
			mEnabled = false;
		}
		break;
	}

	switch (o->mTag)
	{
	case CCollider::EBODY:
		//�R���C�_��m��y���Փ˂��Ă��邩����
		if (CCollider::Collision(m, o))
		{
			CXPlayer::spInstance->mHp--;
			mEnabled = false;
		}
		break;
	}
}

void CBullet::TaskCollision()
{
	mCollider.ChangePriority();
	CCollisionManager::Get()->Collision(&mCollider, COLLISIONRANGE);
}

