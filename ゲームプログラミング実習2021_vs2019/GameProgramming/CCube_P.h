#ifndef CCUBE_P_H
#define CCUBE_P_H
#include "CCharacter.h"

class CCube_P :public CCharacter {
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CCube_P();
	//CCube_P(位置、回転、拡縮)
	CCube_P(const CVector& position, const CVector& rotation, const CVector& scale);
};

#endif
