#ifndef CBALL_P_H
#define CBALL_P_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_P :public CCharacter {
public:
	static CBall_P* spInstance;
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CBall_P();
	//CBall_P(�ʒu�A��]�A�g�k)
	CBall_P(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
	//�X�V����
	void Update();

	int mFireCount;

	int mHp;	//�q�b�g�|�C���g
};

#endif
