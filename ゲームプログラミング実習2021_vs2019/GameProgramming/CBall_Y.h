#ifndef CBALL_Y_H
#define CBALL_Y_H
#include "CCharacter.h"
#include "CCollider.h"

class CBall_Y :public CCharacter {
public:
	static CBall_Y* spInstance;
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CBall_Y();
	//CBall_Y(�ʒu�A��]�A�g�k)
	CBall_Y(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);

	int mHp;	//�q�b�g�|�C���g
};

#endif
