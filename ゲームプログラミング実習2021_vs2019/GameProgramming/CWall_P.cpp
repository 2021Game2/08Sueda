#include "CWall_P.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"  //モデルのファイル
#define MTL "cube.mtl"  //モデルのマテリアルファイル

CModel CWall_P::mModel;  //モデルデータ作成
CWall_P* CWall_P::spInstance = 0;

//デフォルトコンストラクタ
CWall_P::CWall_P()
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...紫
	mpModel->mpMaterials[0]->mDiffuse[0] = 10.0f;    //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;     //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 10.0f;    //B 青

	mColliderMesh.Set(this, &mMatrix, &mModel);
	spInstance = this;
}

//コンストラクタ
//CWall_P(位置、回転、拡縮)
CWall_P::CWall_P(const CVector& position, const CVector& rotation, const CVector& scale)
	:CWall_P()
{
	//位置、回転、拡縮を設定する
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	if (mScale.mX == 0.0f)mScale.mX = 1.0f;
	if (mScale.mY == 0.0f)mScale.mY = 1.0f;
	if (mScale.mZ == 0.0f)mScale.mZ = 1.0f;
	CTransform::Update();
	//優先度を1に変更する
	mPriority = 1;
	CTaskManager::Get()->Remove(this); //削除して
	CTaskManager::Get()->Add(this); //追加する
}

void CWall_P::Collision(CCollider* m, CCollider* o)
{
	return;
}