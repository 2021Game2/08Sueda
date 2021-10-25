#ifndef CWALL_O_H
#define CWALL_O_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall_O :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
	//�R���X�g���N�^
	CWall_O();
	//CWall_O(�ʒu�A��]�A�g�k)
	CWall_O(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
};

#endif
