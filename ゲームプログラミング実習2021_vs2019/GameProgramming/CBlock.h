#ifndef CBLOCK_H
#define CBLOCK_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CBlock :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
	//コンストラクタ
	CBlock();
	//CBlock(位置、回転、拡縮)
	CBlock(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
};

#endif
