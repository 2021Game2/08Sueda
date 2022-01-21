#ifndef CBALL_G_H
#define CBALL_G_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_G :public CCharacter {
public:
	static CBall_G* spInstance;
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CBall_G();
	//CBall_G(�ʒu�A��]�A�g�k)
	CBall_G(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	//Collision(�R���C�_1, �R���C�_2)
	void Collision(CCollider* m, CCollider* o);
	//�Փˏ���
	void TaskCollision();

	int mFireCount;

	int mHp;	//�q�b�g�|�C���g
};

#endif
