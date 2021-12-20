#ifndef CWALL2_H
#define CWALL2_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall2 :public CCharacter {
public:
	static CWall2* spInstance;
	//���f���f�[�^
	static CModel mModel;
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
	//�R���X�g���N�^
	CWall2();
	//CWall2(�ʒu�A��]�A�g�k)
	CWall2(const CVector& position, const CVector& rotation, const CVector& scale);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
};

#endif
