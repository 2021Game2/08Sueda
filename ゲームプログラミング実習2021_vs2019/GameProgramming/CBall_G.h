#ifndef CBALL_G_H
#define CBALL_G_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_G :public CCharacter {
public:
	static CBall_G* spInstance;
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CBall_G();
	//CBall_G(位置、回転、拡縮)
	CBall_G(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//衝突処理
	void TaskCollision();

	int mFireCount;

	int mHp;	//ヒットポイント
};

#endif
