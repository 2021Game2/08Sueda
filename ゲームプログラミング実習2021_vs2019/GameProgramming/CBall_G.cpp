#include "CBall_G.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBall_Y.h"
#include "CSound.h"
#include "CCollisionManager.h"
#define OBJ "sphere.obj"  //���f���̃t�@�C��
#define MTL "sphere.mtl"  //���f���̃}�e���A���t�@�C��
#define HP 1	//�ϋv�l
//�O���ϐ��̎Q�Ƃ̍쐬
extern CSound Se;

CModel CBall_G::mModel;  //���f���f�[�^�쐬
CBall_G* CBall_G::spInstance = 0;

//�f�t�H���g�R���X�g���N�^
CBall_G::CBall_G()
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
	mpModel->mpMaterials[0]->mDiffuse[0] = 0.0f;   //R ��
	mpModel->mpMaterials[0]->mDiffuse[1] = 10.0f;  //G ��
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B ��

	spInstance = this;
}

//�R���X�g���N�^
//CBall_G(�ʒu�A��]�A�g�k)
CBall_G::CBall_G(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_G()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
	CTransform::Update();
}

//�Փˏ���
void CBall_G::TaskCollision()
{
	//�R���C�_�̗D��x�ύX
	mCollider.ChangePriority();
	//�Փˏ��������s
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