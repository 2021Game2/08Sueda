#ifndef CWALL_P_H
#define CWALL_P_H
#include "CCharacter.h"

class CWall_P :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CWall_P();
	//CWall_P(�ʒu�A��]�A�g�k)
	CWall_P(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
