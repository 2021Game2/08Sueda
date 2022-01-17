#ifndef CCUBE_Y_H
#define CCUBE_Y_H
#include "CCharacter.h"
#include "CCollider.h"

class CCube_Y :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CCube_Y();
	//CCube_Y(位置、回転、拡縮)
	CCube_Y(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//衝突処理
	void TaskCollision();
};

#endif
