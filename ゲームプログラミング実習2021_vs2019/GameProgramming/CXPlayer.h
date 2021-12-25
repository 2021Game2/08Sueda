#ifndef CXPLAYER_H
#define CXPLAYER_H

#include "CXCharacter.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter
{
public:
	static CXPlayer* spInstance;
	//コライダの宣言
	CCollider mColSphereBody;	//体
	CCollider mColSphereHead;	//頭
	CCollider mColSphereSword;	//剣
	CCollider mColSphereLegs_L; //左足
	CCollider mColSphereLegs_R; //右足
	CCollider mCollider;        //本体用コライダ
	
	CXPlayer();

	/*
	初期化(Xモデルクラスのポインタ)
	*/
	void Init(CModelX* model);

	void Update();
	//衝突処理
	void TaskCollision();

	//衝突処理
	//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//ジャンプフラグ
	int mJump;
	//ジャンプ用速度
	float mVj;
	//ヒットポイント
	int mHp;
};

#endif
