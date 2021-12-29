#include "CXPlayer.h"
#include "CKey.h"
#include "CSound.h"
#include "CCamera.h"
#define G 0.1     //�d��
#define VJ0 1.5   //�W�����v��
#define HP 10	  //�ϋv�l

//�O���ϐ��̎Q�Ƃ̍쐬
extern CSound Se3;
CXPlayer* CXPlayer::spInstance = 0;

CXPlayer::CXPlayer()
	: mColSphereBody(this, nullptr, CVector(), 0.5f)
	, mColSphereHead(this, nullptr, CVector(0.0f, 5.0f, -3.0f), 0.5f)
	, mColSphereSword(this, nullptr, CVector(-10.0f, 10.0f, 50.0f), 0.3f)
	, mColSphereLegs_L(this, nullptr, CVector(-5.0f, -5.0f, 0.0f), 0.6f)
	, mColSphereLegs_R(this, nullptr, CVector(5.0f, -5.0f, 0.0f), 0.6f)
	, mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.5f)
	, mVj(0)
	, mJump(0)
	, mHp(HP)
{
	//�^�O�Ƀv���C���[��ݒ肵�܂�
	mTag = EPLAYER;
	mColSphereBody.mTag = CCollider::EBODY;
	mColSphereSword.mTag = CCollider::ESWORD;
	mColSphereLegs_L.mTag = CCollider::ELEGS_L;
	mColSphereLegs_R.mTag = CCollider::ELEGS_R;

	spInstance = this;
}

void CXPlayer::Init(CModelX* model)
{
	CXCharacter::Init(model);
	//�����s��̐ݒ�
	mColSphereBody.mpMatrix = &mpCombinedMatrix[9];
	//��
	mColSphereHead.mpMatrix = &mpCombinedMatrix[12];
	//��
	mColSphereSword.mpMatrix = &mpCombinedMatrix[22];
	//����
	mColSphereLegs_L.mpMatrix = &mpCombinedMatrix[25];
	//�E��
	mColSphereLegs_R.mpMatrix = &mpCombinedMatrix[32];
}

void CXPlayer::Update()
{
	//�W�����v�U��
	if (mJump == 0 && CKey::Push('J'))
	{
		mVj = VJ0;   //�W�����v�͂𑬓x�ɐݒ�
		mJump++;     //�t���O��1���Z
		ChangeAnimation(7, true, 30);
		Se3.Play();
	}
	if (CKey::Push('W'))
	{
		mPosition += CVector(0.0f, 0.0f, 0.1f) * mMatrixRotate;
	}
	//���x�ɏd�͉����x���Z
	mVj -= G;
	//���x���ړ�
	mPosition.mY += mVj;

	//�U���A�j���[�V����
	if (mAnimationIndex == 3)
	{
		if (mAnimationFrame >= mAnimationFrameSize)
		{
			ChangeAnimation(4, false, 30);
		}
	}
	else if (mAnimationIndex == 4)
	{
		if (mAnimationFrame >= mAnimationFrameSize)
		{
			ChangeAnimation(0, true, 60);
		}
	}
	//�W�����v�U���A�j���[�V����
	else if (mAnimationIndex == 7)
	{
		if (mAnimationFrame >= mAnimationFrameSize)
		{
			ChangeAnimation(8, false, 30);
		}
	}
	else if (mAnimationIndex == 8)
	{
		if (mAnimationFrame >= mAnimationFrameSize)
		{
			ChangeAnimation(0, true, 60);
		}
	}
	else
	{
		//����]
		if (CKey::Push('A'))
		{
			mRotation.mY += 2.0f;
		}
		//�E��]
		if (CKey::Push('D'))
		{
			mRotation.mY -= 2.0f;
		}
		//�U��
		if (CKey::Push(' '))
		{
			ChangeAnimation(3, true, 30);
		}
		//�ړ�
		else if (CKey::Push('W'))
		{
			ChangeAnimation(1, true, 60);
			mPosition += CVector(0.0f, 0.0f, 0.1f) * mMatrixRotate;
		}
		//�ҋ@
		else {
			ChangeAnimation(0, true, 60);
		}
	}
	CXCharacter::Update();
}

//�Փˏ���
void CXPlayer::TaskCollision()
{
	//�R���C�_�̗D��x�ύX
	mCollider.ChangePriority();
}


//�Փˏ���
//Collision(�R���C�_1, �R���C�_2)
void CXPlayer::Collision(CCollider* m, CCollider* o) {
	switch (o->mType)
	{
	case CCollider::ETRIANGLE: //�O�p�R���C�_�̎�
		CVector adjust;  //�����l
		//�O�p�R���C�_�Ƌ��R���C�_�̏Փ˔���
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{   //�Փ˂��Ȃ��ʒu�܂Ŗ߂�
			mPosition = mPosition + adjust;
			//���n
			mVj = 0;   //�W�����v���x0
			//�W�����v�\
			mJump = 0;
		}
		break;
	}
}