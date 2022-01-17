#include "CBall_P.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBall_I.h"
#include "CSound.h"
#include "CBullet.h"
#define OBJ "sphere.obj"  //���f���̃t�@�C��
#define MTL "sphere.mtl"  //���f���̃}�e���A���t�@�C��
#define HP 1	//�ϋv�l

CModel CBall_P::mModel;  //���f���f�[�^�쐬
CBall_P* CBall_P::spInstance = 0;
//�O���ϐ��̎Q�Ƃ̍쐬
extern CSound Se;

//�f�t�H���g�R���X�g���N�^
CBall_P::CBall_P()
	:mCollider(this, &mMatrix, CVector(), 1.0f)
	, mHp(HP)
	, mFireCount(60)
{
	//���f�����Ȃ��Ƃ��͓ǂݍ���
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//���f���̃|�C���^�ݒ�
	mpModel = &mModel;

	//���f���̃}�e���A���̐F(Diffuse)��ύX����...��
	mpModel->mpMaterials[0]->mDiffuse[0] = 10.0f;    //R ��
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;     //G ��
	mpModel->mpMaterials[0]->mDiffuse[2] = 10.0f;    //B ��

	spInstance = this;
}

//�R���X�g���N�^
//CBall_P(�ʒu�A��]�A�g�k)
CBall_P::CBall_P(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_P()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
	CTransform::Update();
}

void CBall_P::Update() {
	//60�t���[����1�񔭎�
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//�e�𔭎˂��܂�(�O)
		CBullet* bullet1 = new CBullet();
		bullet1->Set(1.1f, 1.5f);
		bullet1->mPosition = CVector(0.0f, 0.0f, 2.0f) * mMatrix;
		bullet1->mRotation = mRotation;
		bullet1->mEnabled = true;
		bullet1->Update();
		mFireCount = 60;

		//�e�𔭎˂��܂�(��)
		CBullet* bullet2 = new CBullet();
		bullet2->Set(1.1f, 1.5f);
		bullet2->mPosition = CVector(0.0f, 0.0f, -2.0f) * mMatrix;
		bullet2->mRotation = CVector(-180.0f, 0.0f, 0.0f);
		bullet2->mEnabled = true;
		bullet2->Update();
		mFireCount = 60;

		//�e�𔭎˂��܂�(�E)
		CBullet* bullet3 = new CBullet();
		bullet3->Set(1.1f, 1.5f);
		bullet3->mPosition = CVector(-2.0f, 0.0f, 0.0f) * mMatrix;
		bullet3->mRotation = CVector(0.0f, -90.0f, 0.0f);
		bullet3->mEnabled = true;
		bullet3->Update();
		mFireCount = 60;

		//�e�𔭎˂��܂�(��)
		CBullet* bullet4 = new CBullet();
		bullet4->Set(1.1f, 1.5f);
		bullet4->mPosition = CVector(2.0f, 0.0f, 0.0f) * mMatrix;
		bullet4->mRotation = CVector(0.0f, 90.0f, 0.0f);
		bullet4->mEnabled = true;
		bullet4->Update();
		mFireCount = 60;
	}
}

void CBall_P::Collision(CCollider* m, CCollider* o)
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
						if (CBall_I::spInstance->mHp <= 0)
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