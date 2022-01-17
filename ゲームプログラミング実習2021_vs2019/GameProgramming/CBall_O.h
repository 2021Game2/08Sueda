#ifndef CBALL_O_H
#define CBALL_O_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_O :public CCharacter {
public:
	static CBall_O* spInstance;
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CBall_O();
	//CBall_O(位置、回転、拡縮)
	CBall_O(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//更新処理
	void Update();
	//衝突処理
	void TaskCollision();

	int mFireCount;

	int CountFrame = 0;    //敵の動きの反転
	int mHp;	//ヒットポイント
};

#endif
