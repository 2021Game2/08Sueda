#ifndef CBALL_B_H
#define CBALL_B_H
#include "CCharacter.h"
#include "CCollider.h"

class CBall_B :public CCharacter {
public:
	static CBall_B* spInstance;
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CBall_B();
	//CBall_B(�ʒu�A��]�A�g�k)
	CBall_B(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);

	int mHp;	//�q�b�g�|�C���g
};

#endif
