#ifndef CCUBE_R_H
#define CCUBE_R_H
#include "CCharacter.h"
#include "CCollider.h"

class CCube_R :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CCube_R();
	//CCube_R(位置、回転、拡縮)
	CCube_R(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
};

#endif
