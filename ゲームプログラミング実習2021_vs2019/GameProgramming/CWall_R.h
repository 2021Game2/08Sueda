#ifndef CWALL_R_H
#define CWALL_R_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall_R :public CCharacter {
public:
	static CWall_R* spInstance;
	//モデルデータ
	static CModel mModel;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
	//コンストラクタ
	CWall_R();
	//CWall_R(位置、回転、拡縮)
	CWall_R(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
};

#endif
