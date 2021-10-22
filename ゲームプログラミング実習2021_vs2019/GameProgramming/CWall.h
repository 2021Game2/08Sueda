#ifndef CWALL_H
#define CWALL_H
#include "CCharacter.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CWall :public CCharacter {
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���C�_
	CCollider mCollider;
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
	//�R���X�g���N�^
	CWall();
	//CWall(�ʒu�A��]�A�g�k)
	CWall(const CVector& position, const CVector& rotation, const CVector& scale);

	void Init();

	//�X�V����
	void Update();
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
	void TaskCollision();
};

#endif
