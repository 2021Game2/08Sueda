#ifndef CWALL_R_H
#define CWALL_R_H
#include "CCharacter.h"

class CWall_R :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CWall_R();
	//CWall_R(位置、回転、拡縮)
	CWall_R(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
