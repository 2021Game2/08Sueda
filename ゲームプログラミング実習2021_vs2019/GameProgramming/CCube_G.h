#ifndef CCUBE_G_H
#define CCUBE_G_H
#include "CCharacter.h"

class CCube_G :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CCube_G();
	//CWall_G(�ʒu�A��]�A�g�k)
	CCube_G(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
