#include "CWall_I.h"
#include "CSceneGame.h"
#define OBJ "cube.obj"  //モデルのファイル
#define MTL "cube.mtl"  //モデルのマテリアルファイル

CModel CWall_I::mModel;  //モデルデータ作成

//デフォルトコンストラクタ
CWall_I::CWall_I()
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...藍
	mpModel->mpMaterials[0]->mDiffuse[0] = 0.0f;    //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;    //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 1.0f;    //B 青
}

//コンストラクタ
//CWall_I(位置、回転、拡縮)
CWall_I::CWall_I(const CVector& position, const CVector& rotation, const CVector& scale)
	:CWall_I()
{
	//位置、回転、拡縮を設定する
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	CTransform::Update();
}