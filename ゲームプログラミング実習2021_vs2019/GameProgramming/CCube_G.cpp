#include "CCube_G.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CWall_G.h"
#include "CSound.h"
#include "CCollisionManager.h"
#define OBJ "cube.obj"  //���f���̃t�@�C��
#define MTL "cube.mtl"  //���f���̃}�e���A���t�@�C��

CModel CCube_G::mModel;  //���f���f�[�^�쐬
extern CSound Se2;       //�O���ϐ��̎Q�Ƃ̍쐬

//�f�t�H���g�R���X�g���N�^
CCube_G::CCube_G()
	:mCollider(this, &mMatrix, CVector(0.0f, 1.0f, 0.0f), 1.5f)
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
}

//�R���X�g���N�^
//CCube_G(�ʒu�A��]�A�g�k)
CCube_G::CCube_G(const CVector& position, const CVector& rotation, const CVector& scale)
	:CCube_G()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
	CTransform::Update();
}

//�Փˏ���
void CCube_G::TaskCollision()
{
	//�R���C�_�̗D��x�ύX
	mCollider.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Get()->Collision(&mCollider, COLLISIONRANGE);
}

void CCube_G::Collision(CCollider* m, CCollider* o)
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
						CWall_G::spInstance->mEnabled = false;
						Se2.Play();
					}
				}
			}
		}
	}
}