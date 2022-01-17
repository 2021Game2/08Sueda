#ifndef CBALL_O_H
#define CBALL_O_H
#include "CCharacter.h"
#include "CCollider.h"
#include "CBullet.h"

class CBall_O :public CCharacter {
public:
	static CBall_O* spInstance;
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_�𐶐�
	CCollider mCollider;
	//�R���X�g���N�^
	CBall_O();
	//CBall_O(�ʒu�A��]�A�g�k)
	CBall_O(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	//Collision(�R���C�_1, �R���C�_2)
	void Collision(CCollider* m, CCollider* o);
	//�X�V����
	void Update();
	//�Փˏ���
	void TaskCollision();

	int mFireCount;

	int CountFrame = 0;    //�G�̓����̔��]
	int mHp;	//�q�b�g�|�C���g
};

#endif
