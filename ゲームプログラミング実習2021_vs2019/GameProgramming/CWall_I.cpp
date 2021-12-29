#include "CWall_I.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"  //���f���̃t�@�C��
#define MTL "cube.mtl"  //���f���̃}�e���A���t�@�C��

CModel CWall_I::mModel;  //���f���f�[�^�쐬
CWall_I* CWall_I::spInstance = 0;

//�f�t�H���g�R���X�g���N�^
CWall_I::CWall_I()
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

	mColliderMesh.Set(this, &mMatrix, &mModel);
	spInstance = this;
}

//�R���X�g���N�^
//CWall_I(�ʒu�A��]�A�g�k)
CWall_I::CWall_I(const CVector& position, const CVector& rotation, const CVector& scale)
	:CWall_I()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
	if (mScale.mX == 0.0f)mScale.mX = 0.3f;
	if (mScale.mY == 0.0f)mScale.mY = 0.3f;
	if (mScale.mZ == 0.0f)mScale.mZ = 0.3f;
	CTransform::Update();
}

void CWall_I::Collision(CCollider* m, CCollider* o)
{
	return;
}