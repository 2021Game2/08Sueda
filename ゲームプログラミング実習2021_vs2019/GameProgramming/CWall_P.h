#ifndef CWALL_P_H
#define CWALL_P_H
#include "CCharacter.h"

class CWall_P :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CWall_P();
	//CWall_P(位置、回転、拡縮)
	CWall_P(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
