#ifndef CWALL_G_H
#define CWALL_G_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall_G :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
	//コンストラクタ
	CWall_G();
	//CWall_G(位置、回転、拡縮)
	CWall_G(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
};

#endif
