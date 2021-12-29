#include "CWall_Y.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"  //モデルのファイル
#define MTL "cube.mtl"  //モデルのマテリアルファイル

CModel CWall_Y::mModel;  //モデルデータ作成
CWall_Y* CWall_Y::spInstance = 0;

//デフォルトコンストラクタ
CWall_Y::CWall_Y()
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...黄
	mpModel->mpMaterials[0]->mDiffuse[0] = 10.0f;  //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 10.0f;  //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B 青

	mColliderMesh.Set(this, &mMatrix, &mModel);
	spInstance = this;
}

//コンストラクタ
//CWall_Y(位置、回転、拡縮)
CWall_Y::CWall_Y(const CVector& position, const CVector& rotation, const CVector& scale)
	:CWall_Y()
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

void CWall_Y::Collision(CCollider* m, CCollider* o)
{
	return;
}