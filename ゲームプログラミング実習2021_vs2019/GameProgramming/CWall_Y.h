#ifndef CWALL_Y_H
#define CWALL_Y_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall_Y :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
	//コンストラクタ
	CWall_Y();
	//CWall_Y(位置、回転、拡縮)
	CWall_Y(const CVector& position, const CVector& rotation, const CVector& scale);
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
};

#endif
