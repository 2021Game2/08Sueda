#include "CBall_R.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBullet.h"
#include "CSound.h"
#define OBJ "sphere.obj"  //���f���̃t�@�C��
#define MTL "sphere.mtl"  //���f���̃}�e���A���t�@�C��
#define HP 1	//�ϋv�l

CModel CBall_R::mModel;  //���f���f�[�^�쐬
CBall_R* CBall_R::spInstance = 0;
//�O���ϐ��̎Q�Ƃ̍쐬
extern CSound Se;

//�f�t�H���g�R���X�g���N�^
CBall_R::CBall_R()
	:mCollider(this, &mMatrix, CVector(), 1.0f)
	, mHp(HP)
{
	//���f�����Ȃ��Ƃ��͓ǂݍ���
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//���f���̃|�C���^�ݒ�
	mpModel = &mModel;

	//���f���̃}�e���A���̐F(Diffuse)��ύX����...��
	mpModel->mpMaterials[0]->mDiffuse[0] = 10.0f;  //R ��
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;   //G ��
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B ��

	spInstance = this;
}

//�R���X�g���N�^
//CBall_R(�ʒu�A��]�A�g�k)
CBall_R::CBall_R(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_R()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
	CTransform::Update();
	//�D��x��1�ɕύX����
	mPriority = 1;
	CTaskManager::Get()->Remove(this); //�폜����
	CTaskManager::Get()->Add(this); //�ǉ�����
}

void CBall_R::Update() {
	//�e��k�֔��˂��܂�
//	CBullet* bullet1 = new CBullet();
//	bullet1->Set(0.1f, 1.5f);
//	bullet1->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
//	bullet1->mRotation = mRotation;
//	bullet1->mFireCount = 60;
//	bullet1->Update();
	//�e���֔��˂��܂�
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