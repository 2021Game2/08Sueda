#ifndef CCUBE_R_H
#define CCUBE_R_H
#include "CCharacter.h"
#include "CCollider.h"

class CCube_R :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CCube_R();
	//CCube_R(�ʒu�A��]�A�g�k)
	CCube_R(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
};

#endif
