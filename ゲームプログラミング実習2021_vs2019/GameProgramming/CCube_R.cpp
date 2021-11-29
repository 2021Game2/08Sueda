#include "CCube_R.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CWall_R.h"
#include "CSound.h"
#define OBJ "cube.obj"  //���f���̃t�@�C��
#define MTL "cube.mtl"  //���f���̃}�e���A���t�@�C��

CModel CCube_R::mModel;  //���f���f�[�^�쐬
extern CSound Se2;       //�O���ϐ��̎Q�Ƃ̍쐬

//�f�t�H���g�R���X�g���N�^
CCube_R::CCube_R()
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
	mpModel->mpMaterials[0]->mDiffuse[0] = 10.0f;  //R ��
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;   //G ��
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B ��
}

//�R���X�g���N�^
//CCube_R(�ʒu�A��]�A�g�k)
CCube_R::CCube_R(const CVector& position, const CVector& rotation, const CVector& scale)
	:CCube_R()
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

void CCube_R::Collision(CCollider* m, CCollider* o)
{
	//����̃R���C�_�^�C�v�̔���
	switch (o->mType)
	{
	case CCollider::ESPHERE:
		if (CCollider::Collision(m, o)) {
			mEnabled = false;
			CWall_R::spInstance->mEnabled = false;
			Se2.Play();
		}
		break;
	}
}