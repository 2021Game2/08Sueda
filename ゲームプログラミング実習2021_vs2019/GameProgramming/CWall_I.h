#ifndef CWALL_I_H
#define CWALL_I_H
#include "CCharacter.h"

class CWall_I :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CWall_I();
	//CWall_I(�ʒu�A��]�A�g�k)
	CWall_I(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
