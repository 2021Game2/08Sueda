#ifndef CWALL_G_H
#define CWALL_G_H
#include "CCharacter.h"

class CWall_G :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CWall_G();
	//CWall_G(�ʒu�A��]�A�g�k)
	CWall_G(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
