#ifndef CCUBE_O_H
#define CCUBE_O_H
#include "CCharacter.h"

class CCube_O :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CCube_O();
	//CWall_O(位置、回転、拡縮)
	CCube_O(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
