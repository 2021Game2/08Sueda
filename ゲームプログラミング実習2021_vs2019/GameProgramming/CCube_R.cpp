#include "CCube_R.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CWall_R.h"
#include "CSound.h"
#define OBJ "cube.obj"  //モデルのファイル
#define MTL "cube.mtl"  //モデルのマテリアルファイル

CModel CCube_R::mModel;  //モデルデータ作成
extern CSound Se2;       //外部変数の参照の作成

//デフォルトコンストラクタ
CCube_R::CCube_R()
	:mCollider(this, &mMatrix, CVector(0.0f, 1.0f, 0.0f), 1.5f)
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...赤
	mpModel->mpMaterials[0]->mDiffuse[0] = 10.0f;  //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;   //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B 青
}

//コンストラクタ
//CCube_R(位置、回転、拡縮)
CCube_R::CCube_R(const CVector& position, const CVector& rotation, const CVector& scale)
	:CCube_R()
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

void CCube_R::Collision(CCollider* m, CCollider* o)
{
	//相手のコライダタイプの判定
	switch (o->mType)
	{
	case CCollider::ESPHERE:
		if (CCollider::Collision(m, o)) {
			mEnabled = false;
			CWall_R::spInstance->mEnabled = false;
			Se2.Play();
		}
		break;
	}
}