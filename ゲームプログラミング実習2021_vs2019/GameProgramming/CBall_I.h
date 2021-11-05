#ifndef CBALL_I_H
#define CBALL_I_H
#include "CCharacter.h"
#include "CCollider.h"

class CBall_I :public CCharacter {
public:
	static CBall_I* spInstance;
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CBall_I();
	//CBall_I(�ʒu�A��]�A�g�k)
	CBall_I(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);

	int mHp;	//�q�b�g�|�C���g
};

#endif

