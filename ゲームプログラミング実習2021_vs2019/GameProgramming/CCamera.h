#ifndef CCAMERA_H
#define CCAMERA_H
#include "CVector.h"
#include "CCollider.h"
/*
�J�����N���X
*/
class CCamera {
public:
	//���_
	CVector mEye;
	//�����_
	CVector mCenter;
	//�����
	CVector mUp;
	//�J�����̐ݒ�
	//Set(���_, �����_, �����)
	void Set(const CVector &eye, const CVector &center,
		const CVector &up);
	//�J�����K�p
	void Render();
	//�Փˏ���
	//Collision(�R���C�_1, �R���C�_2)
	void Collision(CCollider* m, CCollider* o);
};

//�J�����̊O���Q��
extern CCamera Camera;
#endif
