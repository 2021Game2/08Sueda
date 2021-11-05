#ifndef CBALL_B_H
#define CBALL_B_H
#include "CCharacter.h"
#include "CCollider.h"

class CBall_B :public CCharacter {
public:
	static CBall_B* spInstance;
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CBall_B();
	//CBall_B(位置、回転、拡縮)
	CBall_B(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);

	int mHp;	//ヒットポイント
};

#endif
