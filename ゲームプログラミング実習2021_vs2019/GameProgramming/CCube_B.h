#ifndef CCUBE_B_H
#define CCUBE_B_H
#include "CCharacter.h"

class CCube_B :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CCube_B();
	//CCube_B(�ʒu�A��]�A�g�k)
	CCube_B(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
