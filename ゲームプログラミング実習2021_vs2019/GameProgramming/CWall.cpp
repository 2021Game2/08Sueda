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

	mColliderMesh.Set(this, &mMatrix, &mModel);
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
	if (mScale.mX == 0.0f)mScale.mX = 0.3f;
	if (mScale.mY == 0.0f)mScale.mY = 0.3f;
	if (mScale.mZ == 0.0f)mScale.mZ = 0.3f;
	CTransform::Update();
}

void CWall::Collision(CCollider* m, CCollider* o)
{
	return;
}