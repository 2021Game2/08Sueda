#include "CBall_O.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBall_R.h"
#include "CSound.h"
#include "CBullet.h"
#define OBJ "sphere.obj"  //モデルのファイル
#define MTL "sphere.mtl"  //モデルのマテリアルファイル
#define HP 1	//耐久値

CModel CBall_O::mModel;  //モデルデータ作成
CBall_O* CBall_O::spInstance = 0;
//外部変数の参照の作成
extern CSound Se;

//デフォルトコンストラクタ
CBall_O::CBall_O()
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

	//モデルのマテリアルの色(Diffuse)を変更する...橙
	mpModel->mpMaterials[0]->mDiffuse[0] = 10.0f;  //R 赤
	mpModel->mpMaterials[0]->mDiffuse[1] = 2.0f;   //G 緑
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B 青

	spInstance = this;
}

//コンストラクタ
//CBall_O(位置、回転、拡縮)
CBall_O::CBall_O(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_O()
{
	//位置、回転、拡縮を設定する
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	CTransform::Update();
}

void CBall_O::Update() {
	//60フレームに1回発射
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//弾を東へ発射します
		CBullet* bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
		bullet->mEnabled = true;
		bullet->Update();
		mFireCount = 60;
	}
	CountFrame++;
	if (CountFrame > 120) {
		CountFrame = 0;
	}
	if (CountFrame <= 60) {
		mPosition.mZ -= 0.1f;
	}
	else {
		mPosition.mZ += 0.1f;
	}
	CTransform::Update();
}

void CBall_O::Collision(CCollider* m, CCollider* o)
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
						if (CBall_R::spInstance->mHp <= 0)
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