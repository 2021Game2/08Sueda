#ifndef CWALL_H
#define CWALL_H
#include "CCharacter.h"
#include "CColliderMesh.h"

class CWall :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CWall();
	//CWall(位置、回転、拡縮)
	CWall(const CVector& position, const CVector& rotation, const CVector& scale);
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
	//初期化処理のオーバーライド
	void Init();
};

#endif
