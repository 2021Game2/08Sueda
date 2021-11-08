#include "CCamera.h"
#include "glut.h"

//�J�����̊O���ϐ�
CCamera Camera;

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
//			mPosition = mPosition + adjust;
		}
		break;
	}
}