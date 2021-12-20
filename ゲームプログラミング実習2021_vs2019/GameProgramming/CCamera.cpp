#include "CCamera.h"
#include "CCollider.h"
#include "CTaskManager.h"
#include "glut.h"
#define RADIUS 1.0f
#define VELOCITY 0.2f

//�J�����̊O���ϐ�
CCamera Camera;

//�f�t�H���g�R���X�g���N�^
CCamera::CCamera()
	: mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), RADIUS)
{
	mScale = CVector(1.0f, 1.0f, 1.0f);
	mPriority = 1;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);
}

void CCamera::Set(const CVector &eye, const CVector &center,
	const CVector &up) {
	mEye = eye;
	mCenter = center;
	mUp = up;
	mPosition = eye;
}

void CCamera::Set(const CVector& eye, const CVector& center) {
	mEye = eye;
	mCenter = center;
}

void CCamera::Render() {
	gluLookAt(mPosition.mX, mPosition.mY, mPosition.mZ,
		mCenter.mX, mCenter.mY, mCenter.mZ,
		mUp.mX, mUp.mY, mUp.mZ);
}

void CCamera::Update() {
	CVector dir = mEye - mPosition;
	float len = dir.Length();
	if (len > RADIUS)
	{
		mPosition = mPosition + dir.Normalize() * VELOCITY;
	}
	CTransform::Update();
}

//�Փˏ���
//Collision(�R���C�_1, �R���C�_2)
void CCamera::Collision(CCollider* m, CCollider* o) {
	switch (o->mType)
	{
	case CCollider::ETRIANGLE: //�O�p�R���C�_�̎�
		CVector adjust;  //�����l
		//�O�p�R���C�_�Ƌ��R���C�_�̏Փ˔���
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{
			//�Փ˂��Ȃ��ʒu�܂Ŗ߂�
			mPosition = mPosition + adjust;
		}
		break;
	}
}