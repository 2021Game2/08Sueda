#ifndef CWALL_Y_H
#define CWALL_Y_H
#include "CCharacter.h"

class CWall_Y :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CWall_Y();
	//CWall_Y(�ʒu�A��]�A�g�k)
	CWall_Y(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
