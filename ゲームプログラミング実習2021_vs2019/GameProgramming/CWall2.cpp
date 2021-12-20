#include "CWall2.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"
#define MTL "cube.mtl"

CModel CWall2::mModel;  //���f���f�[�^�쐬
CWall2* CWall2::spInstance = 0;

//�f�t�H���g�R���X�g���N�^
CWall2::CWall2()
{
	//���f�����Ȃ��Ƃ��͓ǂݍ���
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//���f���̃|�C���^�ݒ�
	mpModel = &mModel;

	//���f���̃}�e���A���̐F(Diffuse)��ύX����...��
	mpModel->mpMaterials[0]->mDiffuse[0] = 0.0f;  //R ��
	mpModel->mpMaterials[0]->mDiffuse[1] = 0.0f;  //G ��
	mpModel->mpMaterials[0]->mDiffuse[2] = 0.0f;  //B ��

	mColliderMesh.Set(this, &mMatrix, &mModel);
	spInstance = this;
}

//�R���X�g���N�^
//CWall2(�ʒu�A��]�A�g�k)
CWall2::CWall2(const CVector& position, const CVector& rotation, const CVector& scale)
	:CWall2()
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

void CWall2::Collision(CCollider* m, CCollider* o)
{
	return;
}