#ifndef CWALL_G_H
#define CWALL_G_H
#include "CCharacter.h"

class CWall_G :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CWall_G();
	//CWall_G(位置、回転、拡縮)
	CWall_G(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
