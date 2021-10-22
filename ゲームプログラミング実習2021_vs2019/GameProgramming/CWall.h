#ifndef CWALL_H
#define CWALL_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コライダ
	CCollider mCollider;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
	//コンストラクタ
	CWall();
	//CWall(位置、回転、拡縮)
	CWall(const CVector& position, const CVector& rotation, const CVector& scale);

	void Init();

	//更新処理
	void Update();
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
	void TaskCollision();
};

#endif
