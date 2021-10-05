#ifndef CCUBE_Y_H
#define CCUBE_Y_H
#include "CCharacter.h"

class CCube_Y :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CCube_Y();
	//CCube_Y(位置、回転、拡縮)
	CCube_Y(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
