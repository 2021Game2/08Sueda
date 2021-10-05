#ifndef CCUBE_I_H
#define CCUBE_I_H
#include "CCharacter.h"

class CCube_I :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CCube_I();
	//CCube_I(位置、回転、拡縮)
	CCube_I(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
