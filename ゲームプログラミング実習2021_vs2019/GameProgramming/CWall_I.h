#ifndef CWALL_I_H
#define CWALL_I_H
#include "CCharacter.h"

class CWall_I :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CWall_I();
	//CWall_I(位置、回転、拡縮)
	CWall_I(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
