#ifndef CWALL_H
#define CWALL_H
#include "CCharacter.h"

class CWall :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CWall();
	//CWall(�ʒu�A��]�A�g�k)
	CWall(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
