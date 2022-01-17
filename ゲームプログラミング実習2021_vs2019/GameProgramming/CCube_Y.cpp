#include "CCube_Y.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CWall_Y.h"
#include "CSound.h"
#include "CCollisionManager.h"
#define OBJ "cube.obj"  //モデルのファイル
#define MTL "cube.mtl"  //モデルのマテリアルファイル

CModel CCube_Y::mModel;  //モデルデータ作成
extern CSound Se2;       //外部変数の参照の作成

//デフォルトコンストラクタ
CCube_Y::CCube_Y()
	:mCollider(this, &mMatrix, CVector(0.0f, 1.0f, 0.0f), 1.5f)
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
}

//コンストラクタ
//CCube_Y(位置、回転、拡縮)
CCube_Y::CCube_Y(const CVector& position, const CVector& rotation, const CVector& scale)
	:CCube_Y()
{
	//位置、回転、拡縮を設定する
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	CTransform::Update();
}

//衝突処理
void CCube_Y::TaskCollision()
{
	//コライダの優先度変更
	mCollider.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Get()->Collision(&mCollider, COLLISIONRANGE);
}

void CCube_Y::Collision(CCollider* m, CCollider* o)
{
	if (m->mType == CCollider::ESPHERE)
	{
		if (o->mType == CCollider::ESPHERE)
		{
			if (o->mpParent->mTag == EPLAYER)
			{
				if (o->mTag == CCollider::EBODY)
				{
					if (CCollider::Collision(m, o))
					{
						mEnabled = false;
						CWall_Y::spInstance->mEnabled = false;
						Se2.Play();
					}
				}
			}
		}
	}
}