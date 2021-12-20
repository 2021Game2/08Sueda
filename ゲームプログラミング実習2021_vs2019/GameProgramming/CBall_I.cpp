#include "CBall_I.h"
#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CBall_B.h"
#include "CSound.h"
#include "CBullet.h"
#define OBJ "sphere.obj"  //���f���̃t�@�C��
#define MTL "sphere.mtl"  //���f���̃}�e���A���t�@�C��
#define HP 1	//�ϋv�l
//�O���ϐ��̎Q�Ƃ̍쐬
extern CSound Se;

CModel CBall_I::mModel;  //���f���f�[�^�쐬
CBall_I* CBall_I::spInstance = 0;

//�f�t�H���g�R���X�g���N�^
CBall_I::CBall_I()
	:mCollider(this, &mMatrix, CVector(), 1.0f)
	, mHp(HP)
	, mFireCount(60)
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

	spInstance = this;
}

//�R���X�g���N�^
//CBall_I(�ʒu�A��]�A�g�k)
CBall_I::CBall_I(const CVector& position, const CVector& rotation, const CVector& scale)
	:CBall_I()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
	CTransform::Update();
}

void CBall_I::Update() {
	//60�t���[����1�񔭎�
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//�e�𐼂֔��˂��܂�
		CBullet* bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
		bullet->mEnabled = true;
		bullet->Update();
		mFireCount = 60;
	}
}

void CBall_I::Collision(CCollider* m, CCollider* o)
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
						if (CBall_B::spInstance->mHp <= 0)
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