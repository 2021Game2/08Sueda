#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CXPlayer.h"
#include "CXEnemy.h"
#include "CMap.h"
#include "CColliderTriangle.h"
#include "CColliderMesh.h"
#include "CText.h"
/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
private:
	CMap mMap;
	//�L�����N�^�̃C���X�^���X
	CXPlayer mPlayer;
	//�G�̃C���X�^���X
//	CXEnemy mEnemy;
	//�O�p�R���C�_�̍쐬
	CColliderTriangle mColliderTriangle;
	CColliderTriangle mColliderTriangle2;
public:
	CText mText;

	static int Time;
	//�f�t�H���g�R���X�g���N�^
	CSceneGame();
	//�f�X�g���N�^
	~CSceneGame();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//�`�揈��
	void Render();
	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
