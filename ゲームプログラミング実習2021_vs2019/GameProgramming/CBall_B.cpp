#include "CBall_B.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBall_G.h"
#include "CSound.h"
#define OBJ "sphere.obj"  //���f���̃t�@�C��
#define MTL "sphere.mtl"  //���f���̃}�e���A���t�@�C��
#define HP 1	//�ϋv�l

CModel CBall_B::mModel;  //���f���f�[�^�쐬
CBall_B* CBall_B::spInstance = 0;
//�O���ϐ��̎Q�Ƃ̍쐬
extern CSound Se;

//�f�t�H���g�R���X�g���N�^
CBall_B::CBall_B()
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
	mpModel->mpMaterials[0]->mDiffuse[0] = 0.0f;     //R ��
	mpModel->mpMaterials[0]->mDiffuse[1] = 1.0f;     //G ��
	mpModel->mpMaterials[0]->mDiffuse[2] = 10.0f;    //B ��
	
	spInstance = this;
}

//�R���X�g���N�^
//CBall_B(�ʒu�A��]�A�g�k)
CBall_B::CBall_B(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_B()
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

void CBall_B::Collision(CCollider* m, CCollider* o)
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
						if (CBall_G::spInstance->mHp <= 0)
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