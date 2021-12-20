#ifndef CWALL2_H
#define CWALL2_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall2 :public CCharacter {
public:
	static CWall2* spInstance;
	//モデルデータ
	static CModel mModel;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
	//コンストラクタ
	CWall2();
	//CWall2(位置、回転、拡縮)
	CWall2(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
};

#endif
