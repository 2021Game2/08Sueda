#include "CCube_O.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"  //モデルのファイル
#define MTL "cube.mtl"  //モデルのマテリアルファイル

CModel CCube_O::mModel;  //モデルデータ作成

//デフォルトコンストラクタ
CCube_O::CCube_O()
	:mCollider(this, &mMatrix, CVector(0.0f, 1.0f, 0.0f), 1.5f)
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...橙
	mpModel->mpMaterials[0]->mDiffuse[0] = 10.0f;  //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 2.0f;   //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B 青
}

//コンストラクタ
//CCube_O(位置、回転、拡縮)
CCube_O::CCube_O(const CVector& position, const CVector& rotation, const CVector& scale)
	:CCube_O()
{
	//位置、回転、拡縮を設定する
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	CTransform::Update();
}

void CCube_O::Collision(CCollider* m, CCollider* o)
{
	//相手のコライダタイプの判定
	switch (o->mType)
	{
	case CCollider::ESPHERE:
		if (CCollider::Collision(m, o)) {
			mEnabled = false;
		}
		break;
	}
}