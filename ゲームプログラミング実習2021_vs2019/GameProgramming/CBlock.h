#ifndef CBLOCK_H
#define CBLOCK_H
#include "CCharacter.h"

class CBlock :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CBlock();
	//CBlock(�ʒu�A��]�A�g�k)
	CBlock(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
