#include "CCamera.h"
#include "CCollider.h"
#include "CTaskManager.h"
#include "glut.h"

//カメラの外部変数
CCamera Camera;

//デフォルトコンストラクタ
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
			mPosition = mPosition + adjust;
		}
		break;
	}
}