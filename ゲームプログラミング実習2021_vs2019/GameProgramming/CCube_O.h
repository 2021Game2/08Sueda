#ifndef CCUBE_O_H
#define CCUBE_O_H
#include "CCharacter.h"

class CCube_O :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CCube_O();
	//CWall_O(�ʒu�A��]�A�g�k)
	CCube_O(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
