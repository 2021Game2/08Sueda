#include "CCamera.h"
#include "CCollider.h"
#include "CTaskManager.h"
#include "glut.h"
#define RADIUS 1.0f
#define VELOCITY 0.2f

//カメラの外部変数
CCamera Camera;

//デフォルトコンストラクタ
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

//衝突処理
//Collision(コライダ1, コライダ2)
void CCamera::Collision(CCollider* m, CCollider* o) {
	switch (o->mType)
	{
	case CCollider::ETRIANGLE: //三角コライダの時
		CVector adjust;  //調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{
			//衝突しない位置まで戻す
			mPosition = mPosition + adjust;
		}
		break;
	}
}