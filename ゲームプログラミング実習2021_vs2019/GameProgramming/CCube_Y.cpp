#include "CCube_Y.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"  //���f���̃t�@�C��
#define MTL "cube.mtl"  //���f���̃}�e���A���t�@�C��

CModel CCube_Y::mModel;  //���f���f�[�^�쐬

//�f�t�H���g�R���X�g���N�^
CCube_Y::CCube_Y()
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
	mpModel->mpMaterials[0]->mDiffuse[1] = 10.0f;  //G ��
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;   //B ��
}

//�R���X�g���N�^
//CCube_Y(�ʒu�A��]�A�g�k)
CCube_Y::CCube_Y(const CVector& position, const CVector& rotation, const CVector& scale)
	:CCube_Y()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
	if (mScale.mX == 0.0f)mScale.mX = 1.0f;
	if (mScale.mY == 0.0f)mScale.mY = 1.0f;
	if (mScale.mZ == 0.0f)mScale.mZ = 1.0f;
	CTransform::Update();
	//�D��x��1�ɕύX����
	mPriority = 1;
	CTaskManager::Get()->Remove(this); //�폜����
	CTaskManager::Get()->Add(this); //�ǉ�����
}

void CCube_Y::Collision(CCollider* m, CCollider* o)
{
	//����̃R���C�_�^�C�v�̔���
	switch (o->mTag)
	{
	case CCollider::ESPHERE:
		if (CCollider::Collision(m, o)) {
			mEnabled = false;
		}
		break;
	}
}