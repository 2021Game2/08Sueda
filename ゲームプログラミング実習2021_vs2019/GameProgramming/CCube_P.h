#ifndef CCUBE_P_H
#define CCUBE_P_H
#include "CCharacter.h"
#include "CCollider.h"

class CCube_P :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CCube_P();
	//CCube_P(�ʒu�A��]�A�g�k)
	CCube_P(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	//Collision(�R���C�_1, �R���C�_2)
	void Collision(CCollider* m, CCollider* o);
	//�Փˏ���
	void TaskCollision();
};

#endif
