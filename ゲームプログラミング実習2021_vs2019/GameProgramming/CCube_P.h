#ifndef CCUBE_P_H
#define CCUBE_P_H
#include "CCharacter.h"
#include "CCollider.h"

class CCube_P :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CCube_P();
	//CCube_P(位置、回転、拡縮)
	CCube_P(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//衝突処理
	void TaskCollision();
};

#endif
