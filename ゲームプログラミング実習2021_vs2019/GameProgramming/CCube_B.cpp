#include "CCube_B.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CWall_B.h"
#include "CSound.h"
#include "CCollisionManager.h"
#define OBJ "cube.obj"  //モデルのファイル
#define MTL "cube.mtl"  //モデルのマテリアルファイル

CModel CCube_B::mModel;  //モデルデータ作成
extern CSound Se2;       //外部変数の参照の作成

//デフォルトコンストラクタ
CCube_B::CCube_B()
	:mCollider(this, &mMatrix, CVector(0.0f, 1.0f, 0.0f), 1.5f)
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...青
	mpModel->mpMaterials[0]->mDiffuse[0] = 0.0f;     //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 1.0f;     //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 10.0f;    //B 青
}

//コンストラクタ
//CCube_B(位置、回転、拡縮)
CCube_B::CCube_B(const CVector& position, const CVector& rotation, const CVector& scale)
	:CCube_B()
{
	//位置、回転、拡縮を設定する
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	CTransform::Update();
}

//衝突処理
void CCube_B::TaskCollision()
{
	//コライダの優先度変更
	mCollider.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Get()->Collision(&mCollider, COLLISIONRANGE);
}

void CCube_B::Collision(CCollider* m, CCollider* o)
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
						CWall_B::spInstance->mEnabled = false;
						Se2.Play();
					}
				}
			}
		}
	}
}