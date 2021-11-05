#ifndef CBALL_Y_H
#define CBALL_Y_H
#include "CCharacter.h"
#include "CCollider.h"

class CBall_Y :public CCharacter {
public:
	static CBall_Y* spInstance;
	//モデルデータ
	static CModel mModel;
	//コライダを生成
	CCollider mCollider;
	//コンストラクタ
	CBall_Y();
	//CBall_Y(位置、回転、拡縮)
	CBall_Y(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);

	int mHp;	//ヒットポイント
};

#endif
