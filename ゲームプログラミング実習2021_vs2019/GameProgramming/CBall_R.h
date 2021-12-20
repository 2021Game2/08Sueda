#ifndef CBALL_R_H
#define CBALL_R_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_R :public CCharacter {
public:
	static CBall_R* spInstance;
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CBall_R();
	//CBall_R(�ʒu�A��]�A�g�k)
	CBall_R(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//�q�b�g�|�C���g
	int mHp;

	int mFireCount;

	int CountFrame = 0;    //�G�̓����̔��]
};

#endif
