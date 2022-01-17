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

//幅と奥行きの設定
//Set(幅, 奥行)
void CBullet::Set(float w, float d) {
	//スケール設定
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//三角形の頂点設定→3
	mT.SetVertex(CVector(w, 0.0f, 0.0f), CVector(0.0f, 0.0f, -d), CVector(-w, 0.0f, 0.0f));
	//三角形の法線設定
	mT.SetNormal(CVector(0.0f, 1.0f, 0.0f));
}

//更新
void CBullet::Update() {
	if (mFireCount > 0) {
		mFireCount--;
	}
	//生存時間の判定
	if (mLife-- > 0) {
		CTransform::Update();
		//位置更新
		mPosition = CVector(0.0f, 0.0f, 1.0f) * mMatrix;
	}
	else {
		//無効にする
		mEnabled = false;
	}

	//プレイヤーのHPが0になったら弾を出さなくする
	if (CXPlayer::spInstance->mHp == 0) {
		mEnabled = false;
	}
}

//描画
void CBullet::Render() {
	//DIFFUSE灰色設定
	float c[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//三角形描画→12
	mT.Render(mMatrix);
//	mCollider.Render();
}

//衝突処理
//Collision(コライダ1, コライダ2)
void CBullet::Collision(CCollider *m, CCollider *o) {
	switch (o->mType)
	{
	case CCollider::ETRIANGLE: //三角コライダの時
		CVector adjust;  //調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{
			mEnabled = false;
		}
		break;
	}

	switch (o->mTag)
	{
	case CCollider::EBODY:
		//コライダのmとyが衝突しているか判定
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

