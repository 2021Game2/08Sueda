#ifndef CBLOCK_H
#define CBLOCK_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CBlock :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
	//�R���X�g���N�^
	CBlock();
	//CBlock(�ʒu�A��]�A�g�k)
	CBlock(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
};

#endif
