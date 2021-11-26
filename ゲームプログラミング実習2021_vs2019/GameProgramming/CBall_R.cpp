#include "CBall_R.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBullet.h"
#include "CSound.h"
#define OBJ "sphere.obj"  //モデルのファイル
#define MTL "sphere.mtl"  //モデルのマテリアルファイル
#define HP 1	//耐久値

CModel CBall_R::mModel;  //モデルデータ作成
CBall_R* CBall_R::spInstance = 0;
//外部変数の参照の作成
extern CSound Se;

//デフォルトコンストラクタ
CBall_R::CBall_R()
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

	//モデルのマテリアルの色(Diffuse)を変更する...赤
	mpModel->mpMaterials[0]->mDiffuse[0] = 10.0f;  //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;   //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B 青

	spInstance = this;
}

//コンストラクタ
//CBall_R(位置、回転、拡縮)
CBall_R::CBall_R(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_R()
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

void CBall_R::Update() {
	//弾を北へ発射します
//	CBullet* bullet1 = new CBullet();
//	bullet1->Set(0.1f, 1.5f);
//	bullet1->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
//	bullet1->mRotation = mRotation;
//	bullet1->mFireCount = 60;
//	bullet1->Update();
	//弾を南へ発射します
//	CBullet* bullet2 = new CBullet();
//	bullet2->Set(0.1f, 1.5f);
//	bullet2->mPosition = CVector(0.0f, 0.0f, -10.0f) * mMatrix;
//	bullet2->mRotation = mRotation;
//	bullet2->mFireCount = 60;
//	bullet2->Update();
}

void CBall_R::Collision(CCollider* m, CCollider* o)
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
						Se.Play();
						mHp--;
						mEnabled = false;
					}
				}
			}
		}
	}
}