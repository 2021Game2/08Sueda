#ifndef CCUBE_R_H
#define CCUBE_R_H
#include "CCharacter.h"

class CCube_R :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CCube_R();
	//CCube_R(�ʒu�A��]�A�g�k)
	CCube_R(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
