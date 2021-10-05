#ifndef CCUBE_R_H
#define CCUBE_R_H
#include "CCharacter.h"

class CCube_R :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CCube_R();
	//CCube_R(位置、回転、拡縮)
	CCube_R(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
