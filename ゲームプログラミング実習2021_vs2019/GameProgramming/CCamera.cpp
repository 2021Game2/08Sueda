#include "CCamera.h"
#include "CCollider.h"
#include "CTaskManager.h"
#include "glut.h"

//�J�����̊O���ϐ�
CCamera Camera;

//�f�t�H���g�R���X�g���N�^
CCamera::CCamera()
	: mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 1.0f)
{
	
}

void CCamera::Set(const CVector &eye, const CVector &center,
	const CVector &up) {
	mEye = eye;
	mCenter = center;
	mUp = up;
}

void CCamera::Render() {
	gluLookAt(mEye.mX, mEye.mY, mEye.mZ,
		mCenter.mX, mCenter.mY, mCenter.mZ,
		mUp.mX, mUp.mY, mUp.mZ);

//	mPriority = 1;
//	CTaskManager::Get()->Remove(this);
//	CTaskManager::Get()->Add(this);
}

void CCamera::Update() {
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
		{   //�Փ˂��Ȃ��ʒu�܂Ŗ߂�
			mPosition = mPosition + adjust;
		}
		break;
	}
}