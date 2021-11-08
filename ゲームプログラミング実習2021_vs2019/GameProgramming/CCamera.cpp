#include "CCamera.h"
#include "glut.h"

//カメラの外部変数
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

//衝突処理
//Collision(コライダ1, コライダ2)
void CCamera::Collision(CCollider* m, CCollider* o) {
	switch (o->mType)
	{
	case CCollider::ETRIANGLE: //三角コライダの時
		CVector adjust;  //調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{   //衝突しない位置まで戻す
//			mPosition = mPosition + adjust;
		}
		break;
	}
}