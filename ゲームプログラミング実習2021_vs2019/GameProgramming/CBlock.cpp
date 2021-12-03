#include "CBlock.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"  //���f���̃t�@�C��
#define MTL "cube.mtl"  //���f���̃}�e���A���t�@�C��

CModel CBlock::mModel;  //���f���f�[�^�쐬

//�f�t�H���g�R���X�g���N�^
CBlock::CBlock()
{
	//���f�����Ȃ��Ƃ��͓ǂݍ���
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//���f���̃|�C���^�ݒ�
	mpModel = &mModel;

	//���f���̃}�e���A���̐F(Diffuse)��ύX����...��
	mpModel->mpMaterials[0]->mDiffuse[0] = 1.0f;    //R ��
	mpModel->mpMaterials[0]->mDiffuse[1] = 1.0f;    //G ��
	mpModel->mpMaterials[0]->mDiffuse[2] = 1.0f;    //B ��

	mColliderMesh.Set(this, &mMatrix, &mModel);
}

//�R���X�g���N�^
//CBlock(�ʒu�A��]�A�g�k)
CBlock::CBlock(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBlock()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
	if (mScale.mX == 0.0f)mScale.mX = 1.0f;
	if (mScale.mY == 0.0f)mScale.mY = 1.0f;
	if (mScale.mZ == 0.0f)mScale.mZ = 1.0f;
	CTransform::Update();
}

void CBlock::Collision(CCollider* m, CCollider* o)
{
	return;
}