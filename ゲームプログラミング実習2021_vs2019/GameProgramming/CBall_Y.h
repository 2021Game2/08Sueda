#ifndef CBALL_Y_H
#define CBALL_Y_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_Y :public CCharacter {
public:
	static CBall_Y* spInstance;
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CBall_Y();
	//CBall_Y(位置、回転、拡縮)
	CBall_Y(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//更新処理
	void Update();
	//衝突処理
	void TaskCollision();

	int mFireCount;

	int mHp;	//ヒットポイント
};

#endif
