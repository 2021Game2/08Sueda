#ifndef CWALL_O_H
#define CWALL_O_H
#include "CCharacter.h"

class CWall_O :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CWall_O();
	//CWall_O(位置、回転、拡縮)
	CWall_O(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
