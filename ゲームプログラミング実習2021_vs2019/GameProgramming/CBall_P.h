#ifndef CBALL_P_H
#define CBALL_P_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_P :public CCharacter {
public:
	static CBall_P* spInstance;
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CBall_P();
	//CBall_P(位置、回転、拡縮)
	CBall_P(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
	//更新処理
	void Update();

	int mFireCount;

	int mHp;	//ヒットポイント
};

#endif
