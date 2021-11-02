#include "CWall_P.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"  //���f���̃t�@�C��
#define MTL "cube.mtl"  //���f���̃}�e���A���t�@�C��

CModel CWall_P::mModel;  //���f���f�[�^�쐬
CWall_P* CWall_P::spInstance = 0;

//�f�t�H���g�R���X�g���N�^
CWall_P::CWall_P()
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

	mColliderMesh.Set(this, &mMatrix, &mModel);
	spInstance = this;
}

//�R���X�g���N�^
//CWall_P(�ʒu�A��]�A�g�k)
CWall_P::CWall_P(const CVector& position, const CVector& rotation, const CVector& scale)
	:CWall_P()
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

void CWall_P::Collision(CCollider* m, CCollider* o)
{
	return;
}