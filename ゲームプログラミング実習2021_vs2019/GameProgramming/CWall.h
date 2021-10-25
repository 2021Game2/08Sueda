#ifndef CWALL_H
#define CWALL_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
	//�R���X�g���N�^
	CWall();
	//CWall(�ʒu�A��]�A�g�k)
	CWall(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
};

#endif
