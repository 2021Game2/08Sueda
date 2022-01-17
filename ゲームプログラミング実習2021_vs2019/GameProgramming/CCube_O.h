#ifndef CCUBE_O_H
#define CCUBE_O_H
#include "CCharacter.h"
#include "CCollider.h"

class CCube_O :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CCube_O();
	//CWall_O(�ʒu�A��]�A�g�k)
	CCube_O(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	//Collision(�R���C�_1, �R���C�_2)
	void Collision(CCollider* m, CCollider* o);
	//�Փˏ���
	void TaskCollision();
};

#endif
