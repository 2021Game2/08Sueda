#ifndef CCUBE_Y_H
#define CCUBE_Y_H
#include "CCharacter.h"

class CCube_Y :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CCube_Y();
	//CCube_Y(�ʒu�A��]�A�g�k)
	CCube_Y(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
