#ifndef CWALL_B_H
#define CWALL_B_H
#include "CCharacter.h"

class CWall_B :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CWall_B();
	//CWall_B(位置、回転、拡縮)
	CWall_B(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
