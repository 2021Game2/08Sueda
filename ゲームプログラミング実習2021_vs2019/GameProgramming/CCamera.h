#ifndef CCAMERA_H
#define CCAMERA_H
#include "CVector.h"
#include "CCharacter.h"
#include "CCollider.h"
/*
カメラクラス
*/
class CCamera : public CCharacter {
public:
	//視点
	CVector mEye;
	//注視点
	CVector mCenter;
	//上方向
	CVector mUp;
	//コライダ
	CCollider mCollider;
	//カメラの設定
	//Set(視点, 注視点, 上方向)
	void Set(const CVector &eye, const CVector &center,
		const CVector &up);
	//衝突処理
	//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o);
	//カメラ適用
	void Render();
	//デフォルトコンストラクタ
	CCamera();

	void Update();
};

//カメラの外部参照
extern CCamera Camera;
#endif
