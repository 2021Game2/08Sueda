#include "CBlock.h"
#include "CSceneGame.h"
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
	CTransform::Update();
}