#ifndef CCUBE_B_H
#define CCUBE_B_H
#include "CCharacter.h"

class CCube_B :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CCube_B();
	//CCube_B(位置、回転、拡縮)
	CCube_B(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
