#ifndef CCUBE_P_H
#define CCUBE_P_H
#include "CCharacter.h"

class CCube_P :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CCube_P();
	//CCube_P(�ʒu�A��]�A�g�k)
	CCube_P(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
