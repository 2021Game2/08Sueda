#ifndef CWALL_B_H
#define CWALL_B_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall_B :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
	//�R���X�g���N�^
	CWall_B();
	//CWall_B(�ʒu�A��]�A�g�k)
	CWall_B(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
};

#endif
