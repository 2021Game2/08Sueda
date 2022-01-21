#ifndef CCAMERA_H
#define CCAMERA_H
#include "CVector.h"
#include "CCharacter.h"
#include "CCollider.h"
/*
�J�����N���X
*/
class CCamera : public CCharacter {
public:
	//���_
	CVector mEye;
	//�����_
	CVector mCenter;
	//�����
	CVector mUp;
	//�R���C�_
	CCollider mCollider;
	//�J�����̐ݒ�
	//Set(���_, �����_, �����)
	void Set(const CVector &eye, const CVector &center,
		const CVector &up);
	//Set(���_�A�����_)
	void Set(const CVector& eye, const CVector& center);
	//�Փˏ���
	//Collision(�R���C�_1, �R���C�_2)
	void Collision(CCollider* m, CCollider* o);
	//�J�����K�p
	void Render();
	//�f�t�H���g�R���X�g���N�^
	CCamera();
	//�X�V����
	void Update();

	void TaskCollision();
};

//�J�����̊O���Q��
extern CCamera Camera;
#endif
