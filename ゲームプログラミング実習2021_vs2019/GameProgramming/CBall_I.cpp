#include "CBall_I.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBall_B.h"
#define OBJ "sphere.obj"  //モデルのファイル
#define MTL "sphere.mtl"  //モデルのマテリアルファイル
#define HP 1	//耐久値

CModel CBall_I::mModel;  //モデルデータ作成
CBall_I* CBall_I::spInstance = 0;

//デフォルトコンストラクタ
CBall_I::CBall_I()
	:mCollider(this, &mMatrix, CVector(), 1.0f)
	, mHp(HP)
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...藍
	mpModel->mpMaterials[0]->mDiffuse[0] = 0.0f;     //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;     //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 10.0f;    //B 青

	spInstance = this;
}

//コンストラクタ
//CBall_I(位置、回転、拡縮)
CBall_I::CBall_I(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_I()
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

void CBall_I::Collision(CCollider* m, CCollider* o)
{
	if (m->mType == CCollider::ESPHERE)
	{
		if (o->mType == CCollider::ESPHERE)
		{
			if (o->mpParent->mTag == EPLAYER)
			{
				if (o->mTag == CCollider::ESWORD)
				{
					if (CCollider::Collision(m, o))
					{
						if (CBall_B::spInstance->mHp <= 0)
						{
							mHp--;
							mEnabled = false;
						}
					}
				}
			}
		}
	}
}