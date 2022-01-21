#ifndef CBALL_R_H
#define CBALL_R_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_R :public CCharacter {
public:
	static CBall_R* spInstance;
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CBall_R();
	//CBall_R(位置、回転、拡縮)
	CBall_R(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//ヒットポイント
	int mHp;
	//衝突処理
	void TaskCollision();
	int mFireCount;

	int CountFrame = 0;    //敵の動きの反転
};

#endif
