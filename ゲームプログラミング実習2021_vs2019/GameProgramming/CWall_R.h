#ifndef CWALL_R_H
#define CWALL_R_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall_R :public CCharacter {
public:
	static CWall_R* spInstance;
	//���f���f�[�^
	static CModel mModel;
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
	//�R���X�g���N�^
	CWall_R();
	//CWall_R(�ʒu�A��]�A�g�k)
	CWall_R(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
};

#endif
