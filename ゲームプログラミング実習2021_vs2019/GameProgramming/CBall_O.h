#ifndef CBALL_O_H
#define CBALL_O_H
#include "CCharacter.h"
#include "CCollider.h"

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
	void Collision(CCollider* m, CCollider* o);

	int mHp;	//ヒットポイント
};

#endif
