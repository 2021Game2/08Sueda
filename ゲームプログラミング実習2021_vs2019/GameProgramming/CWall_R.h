#ifndef CWALL_R_H
#define CWALL_R_H
#include "CCharacter.h"

class CWall_R :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CWall_R();
	//CWall_R(�ʒu�A��]�A�g�k)
	CWall_R(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
