#include "CXPlayer.h"
#include "CKey.h"
#include "CSound.h"
#include "CCamera.h"
#define G 0.1     //重力
#define VJ0 1.5   //ジャンプ力
#define HP 10	  //耐久値

//外部変数の参照の作成
extern CSound Se3;
CXPlayer* CXPlayer::spInstance = 0;

CXPlayer::CXPlayer()
	: mColSphereBody(this, nullptr, CVector(), 0.5f)
	, mColSphereHead(this, nullptr, CVector(0.0f, 5.0f, -3.0f), 0.5f)
	, mColSphereSword(this, nullptr, CVector(-10.0f, 10.0f, 50.0f), 0.3f)
	, mColSphereLegs_L(this, nullptr, CVector(-5.0f, -5.0f, 0.0f), 0.6f)
	, mColSphereLegs_R(this, nullptr, CVector(5.0f, -5.0f, 0.0f), 0.6f)
	, mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.5f)
	, mVj(0)
	, mJump(0)
	, mHp(HP)
{
	//タグにプレイヤーを設定します
	mTag = EPLAYER;
	mColSphereBody.mTag = CCollider::EBODY;
	mColSphereSword.mTag = CCollider::ESWORD;
	mColSphereLegs_L.mTag = CCollider::ELEGS_L;
	mColSphereLegs_R.mTag = CCollider::ELEGS_R;

	spInstance = this;
}

void CXPlayer::Init(CModelX* model)
{
	CXCharacter::Init(model);
	//合成行列の設定
	mColSphereBody.mpMatrix = &mpCombinedMatrix[9];
	//頭
	mColSphereHead.mpMatrix = &mpCombinedMatrix[12];
	//剣
	mColSphereSword.mpMatrix = &mpCombinedMatrix[22];
	//左足
	mColSphereLegs_L.mpMatrix = &mpCombinedMatrix[25];
	//右足
	mColSphereLegs_R.mpMatrix = &mpCombinedMatrix[32];
}

void CXPlayer::Update()
{
	//ジャンプ攻撃
	if (mJump == 0 && CKey::Push('J'))
	{
		mVj = VJ0;   //ジャンプ力を速度に設定
		mJump++;     //フラグに1加算
		ChangeAnimation(7, true, 30);
		Se3.Play();
	}
	if (CKey::Push('W'))
	{
		mPosition += CVector(0.0f, 0.0f, 0.1f) * mMatrixRotate;
	}
	//速度に重力加速度加算
	mVj -= G;
	//速度分移動
	mPosition.mY += mVj;

	//攻撃アニメーション
	if (mAnimationIndex == 3)
	{
		if (mAnimationFrame >= mAnimationFrameSize)
		{
			ChangeAnimation(4, false, 30);
		}
	}
	else if (mAnimationIndex == 4)
	{
		if (mAnimationFrame >= mAnimationFrameSize)
		{
			ChangeAnimation(0, true, 60);
		}
	}
	//ジャンプ攻撃アニメーション
	else if (mAnimationIndex == 7)
	{
		if (mAnimationFrame >= mAnimationFrameSize)
		{
			ChangeAnimation(8, false, 30);
		}
	}
	else if (mAnimationIndex == 8)
	{
		if (mAnimationFrame >= mAnimationFrameSize)
		{
			ChangeAnimation(0, true, 60);
		}
	}
	else
	{
		//左回転
		if (CKey::Push('A'))
		{
			mRotation.mY += 2.0f;
		}
		//右回転
		if (CKey::Push('D'))
		{
			mRotation.mY -= 2.0f;
		}
		//攻撃
		if (CKey::Push(' '))
		{
			ChangeAnimation(3, true, 30);
		}
		//移動
		else if (CKey::Push('W'))
		{
			ChangeAnimation(1, true, 60);
			mPosition += CVector(0.0f, 0.0f, 0.1f) * mMatrixRotate;
		}
		//待機
		else {
			ChangeAnimation(0, true, 60);
		}
	}
	CXCharacter::Update();
}

//衝突処理
void CXPlayer::TaskCollision()
{
	//コライダの優先度変更
	mCollider.ChangePriority();
}


//衝突処理
//Collision(コライダ1, コライダ2)
void CXPlayer::Collision(CCollider* m, CCollider* o) {
	switch (o->mType)
	{
	case CCollider::ETRIANGLE: //三角コライダの時
		CVector adjust;  //調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{   //衝突しない位置まで戻す
			mPosition = mPosition + adjust;
			//着地
			mVj = 0;   //ジャンプ速度0
			//ジャンプ可能
			mJump = 0;
		}
		break;
	}
}