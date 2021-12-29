#include "CWall_R.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"  //���f���̃t�@�C��
#define MTL "cube.mtl"  //���f���̃}�e���A���t�@�C��

CModel CWall_R::mModel;  //���f���f�[�^�쐬
CWall_R* CWall_R::spInstance = 0;

//�f�t�H���g�R���X�g���N�^
CWall_R::CWall_R()
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

	mColliderMesh.Set(this, &mMatrix, &mModel);
	spInstance = this;
}

//�R���X�g���N�^
//CWall_R(�ʒu�A��]�A�g�k)
CWall_R::CWall_R(const CVector& position, const CVector& rotation, const CVector& scale)
	:CWall_R()
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

void CWall_R::Collision(CCollider* m, CCollider* o)
{
	return;
}