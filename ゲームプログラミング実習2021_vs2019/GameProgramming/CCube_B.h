#ifndef CCUBE_B_H
#define CCUBE_B_H
#include "CCharacter.h"
#include "CCollider.h"

class CCube_B :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CCube_B();
	//CCube_B(�ʒu�A��]�A�g�k)
	CCube_B(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
};

#endif
