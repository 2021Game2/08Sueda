#ifndef CBALL_I_H
#define CBALL_I_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_I :public CCharacter {
public:
	static CBall_I* spInstance;
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CBall_I();
	//CBall_I(位置、回転、拡縮)
	CBall_I(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//更新処理のオーバーライド
	void Update();
	//衝突処理
	void TaskCollision();

	int mFireCount;

	int mHp;	//ヒットポイント
};

#endif

