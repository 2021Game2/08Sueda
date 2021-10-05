#ifndef CBLOCK_H
#define CBLOCK_H
#include "CCharacter.h"

class CBlock :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CBlock();
	//CBlock(位置、回転、拡縮)
	CBlock(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
