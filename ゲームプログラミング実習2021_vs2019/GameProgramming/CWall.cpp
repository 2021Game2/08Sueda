#include "CWall.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#define OBJ "cube.obj"
#define MTL "cube.mtl"

CModel CWall::mModel;  //���f���f�[�^�쐬

//�f�t�H���g�R���X�g���N�^
CWall::CWall()
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
}

//�R���X�g���N�^
//CWall(�ʒu�A��]�A�g�k)
CWall::CWall(const CVector& position, const CVector& rotation, const CVector& scale)
:CWall()
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

void CWall::Init() {
	mColliderMesh.Set(, , &mModel);
}

//�X�V����
void CWall::Update() {

}

void CWall::Collision(CCollider* m, CCollider* o)
{
	//����̃R���C�_�^�C�v�̔���
	switch (o->mType)
	{
	case CCollider::ETRIANGLE: //�O�p�R���C�_�̎�
		CVector adjust;  //�����l
		//�O�p�R���C�_�Ƌ��R���C�_�̏Փ˔���
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{   //�Փ˂��Ȃ��ʒu�܂Ŗ߂�
			mPosition = mPosition + adjust;
		}
		break;
	}
}

void CWall::TaskCollision() {

}