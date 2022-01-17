#include "CBall_G.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBall_Y.h"
#include "CSound.h"
#include "CBullet.h"
#include "CCollisionManager.h"
#define OBJ "sphere.obj"  //モデルのファイル
#define MTL "sphere.mtl"  //モデルのマテリアルファイル
#define HP 1	//耐久値
//外部変数の参照の作成
extern CSound Se;

CModel CBall_G::mModel;  //モデルデータ作成
CBall_G* CBall_G::spInstance = 0;

//デフォルトコンストラクタ
CBall_G::CBall_G()
	:mCollider(this, &mMatrix, CVector(), 1.0f)
	, mHp(HP)
	, mFireCount(60)
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;

	//モデルのマテリアルの色(Diffuse)を変更する...緑
	mpModel->mpMaterials[0]->mDiffuse[0] = 0.0f;   //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 10.0f;  //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B 青

	spInstance = this;
}

//コンストラクタ
//CBall_G(位置、回転、拡縮)
CBall_G::CBall_G(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_G()
{
	//位置、回転、拡縮を設定する
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	CTransform::Update();
}

void CBall_G::Update() {
	//60フレームに1回発射
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//弾を発射します(前)
		CBullet* bullet1 = new CBullet();
		bullet1->Set(1.1f, 1.5f);
		bullet1->mPosition = CVector(0.0f, 0.0f, 2.0f) * mMatrix;
		bullet1->mRotation = mRotation;
		bullet1->mEnabled = true;
		bullet1->Update();
		mFireCount = 60;

		//弾を発射します(後)
		CBullet* bullet2 = new CBullet();
		bullet2->Set(1.1f, 1.5f);
		bullet2->mPosition = CVector(0.0f, 0.0f, -2.0f) * mMatrix;
		bullet2->mRotation = CVector(-180.0f, 0.0f, 0.0f);
		bullet2->mEnabled = true;
		bullet2->Update();
		mFireCount = 60;

		//弾を発射します(右)
		CBullet* bullet3 = new CBullet();
		bullet3->Set(1.1f, 1.5f);
		bullet3->mPosition = CVector(-2.0f, 0.0f, 0.0f) * mMatrix;
		bullet3->mRotation = CVector(0.0f, -90.0f, 0.0f);
		bullet3->mEnabled = true;
		bullet3->Update();
		mFireCount = 60;

		//弾を発射します(左)
		CBullet* bullet4 = new CBullet();
		bullet4->Set(1.1f, 1.5f);
		bullet4->mPosition = CVector(2.0f, 0.0f, 0.0f) * mMatrix;
		bullet4->mRotation = CVector(0.0f, 90.0f, 0.0f);
		bullet4->mEnabled = true;
		bullet4->Update();
		mFireCount = 60;
	}
}

//衝突処理
void CBall_G::TaskCollision()
{
	//コライダの優先度変更
	mCollider.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Get()->Collision(&mCollider, COLLISIONRANGE);
}

void CBall_G::Collision(CCollider* m, CCollider* o)
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
						if (CBall_Y::spInstance->mHp <= 0)
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
}