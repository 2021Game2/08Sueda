#include "CWall.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"
#define MTL "cube.mtl"

CModel CWall::mModel;  //モデルデータ作成

//デフォルトコンストラクタ
CWall::CWall()
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...黒
	mpModel->mpMaterials[0]->mDiffuse[0] = 0.0f;  //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;  //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;  //B 青
}

//コンストラクタ
//CWall(位置、回転、拡縮)
CWall::CWall(const CVector& position, const CVector& rotation, const CVector& scale)
:CWall()
{
	//位置、回転、拡縮を設定する
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	CTransform::Update();
	//優先度を1に変更する
	mPriority = 1;
	CTaskManager::Get()->Remove(this); //削除して
	CTaskManager::Get()->Add(this); //追加する
}

void CWall::Init() {
	mColliderMesh.Set(, , &mModel);
}

//更新処理
void CWall::Update() {

}

void CWall::Collision(CCollider* m, CCollider* o)
{
	//相手のコライダタイプの判定
	switch (o->mType)
	{
	case CCollider::ETRIANGLE: //三角コライダの時
		CVector adjust;  //調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{   //衝突しない位置まで戻す
			mPosition = mPosition + adjust;
		}
		break;
	}
}

void CWall::TaskCollision() {

}