#ifndef CCUBE_I_H
#define CCUBE_I_H
#include "CCharacter.h"
#include "CCollider.h"

class CCube_I :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CCube_I();
	//CCube_I(�ʒu�A��]�A�g�k)
	CCube_I(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
};

#endif
