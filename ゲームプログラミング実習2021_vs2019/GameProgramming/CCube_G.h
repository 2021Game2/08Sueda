#ifndef CCUBE_G_H
#define CCUBE_G_H
#include "CCharacter.h"
#include "CCollider.h"

class CCube_G :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CCube_G();
	//CWall_G(位置、回転、拡縮)
	CCube_G(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
};

#endif
