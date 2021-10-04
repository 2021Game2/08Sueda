#include "CWall_B.h"
#include "CSceneGame.h"
#define OBJ "cube.obj"  //モデルのファイル
#define MTL "cube.mtl"  //モデルのマテリアルファイル

CModel CWall_B::mModel;  //モデルデータ作成

//デフォルトコンストラクタ
CWall_B::CWall_B()
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...青
	mpModel->mpMaterials[0]->mDiffuse[0] = 0.0f;    //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;    //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 10.0f;   //B 青
}

//コンストラクタ
//CWall_B(位置、回転、拡縮)
CWall_B::CWall_B(const CVector& position, const CVector& rotation, const CVector& scale)
	:CWall_B()
{
	//位置、回転、拡縮を設定する
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	CTransform::Update();
}