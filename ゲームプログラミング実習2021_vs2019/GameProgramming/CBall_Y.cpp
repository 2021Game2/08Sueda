#include "CBall_Y.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBall_O.h"
#include "CSound.h"
#define OBJ "sphere.obj"  //���f���̃t�@�C��
#define MTL "sphere.mtl"  //���f���̃}�e���A���t�@�C��
#define HP 1	//�ϋv�l

CModel CBall_Y::mModel;  //���f���f�[�^�쐬
CBall_Y* CBall_Y::spInstance = 0;
//�O���ϐ��̎Q�Ƃ̍쐬
extern CSound Se;

//�f�t�H���g�R���X�g���N�^
CBall_Y::CBall_Y()
	:mCollider(this, &mMatrix, CVector(), 1.0f)
	, mHp(HP)
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

	spInstance = this;
}

//�R���X�g���N�^
//CBall_Y(�ʒu�A��]�A�g�k)
CBall_Y::CBall_Y(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_Y()
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

void CBall_Y::Collision(CCollider* m, CCollider* o)
{
	if (m->mType == CCollider::ESPHERE)
	{
		if (o->mType == CCollider::ESPHERE)
		{
			if (o->mpParent->mTag == EPLAYER)
			{
				if (o->mTag == CCollider::ESWORD)
				{
					if (CCollider::Collision(m, o))
					{
						if (CBall_O::spInstance->mHp <= 0)
						{
							Se.Play();
							mHp--;
							mEnabled = false;
						}
					}
				}
			}
		}
	}
}