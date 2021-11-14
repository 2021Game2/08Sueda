#ifndef CXPLAYER_H
#define CXPLAYER_H

#include "CXCharacter.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter
{
public:
	//�R���C�_�̐錾
	CCollider mColSphereBody;	//��
	CCollider mColSphereHead;	//��
	CCollider mColSphereSword;	//��
	CCollider mColSphereLegs_L; //����
	CCollider mColSphereLegs_R; //�E��
	
	CXPlayer();

	/*
	������(X���f���N���X�̃|�C���^)
	*/
	void Init(CModelX* model);

	void Update();

	//�Փˏ���
	//Collision(�R���C�_1, �R���C�_2)
	void Collision(CCollider* m, CCollider* o);
	//�W�����v�t���O
	int mJump;
	//�W�����v�p���x
	float mVj;
};

#endif
