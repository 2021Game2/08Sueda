#include "CCube_I.h"
#include "CSceneGame.h"
#define OBJ "cube.obj"  //���f���̃t�@�C��
#define MTL "cube.mtl"  //���f���̃}�e���A���t�@�C��

CModel CCube_I::mModel;  //���f���f�[�^�쐬

//�f�t�H���g�R���X�g���N�^
CCube_I::CCube_I()
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
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;     //G ��
	mpModel->mpMaterials[0]->mDiffuse[2] = 10.0f;    //B ��
}

//�R���X�g���N�^
//CCube_I(�ʒu�A��]�A�g�k)
CCube_I::CCube_I(const CVector& position, const CVector& rotation, const CVector& scale)
	:CCube_I()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
	CTransform::Update();
}