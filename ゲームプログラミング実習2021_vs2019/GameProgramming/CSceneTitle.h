#ifndef CSCENETITLE_H
#define CSCENETITLE_H
#include "CScene.h"
#include "CKey.h"
#include "CText.h"

class CSceneTitle :public CScene {
public:
	CText mText;

	CSceneTitle();

	void Render();

	//�������̃I�[�o�[���C�h
	void Init() {
		//�V�[���̐ݒ�
		mScene = ETITLE;
	}
	//�X�V�����̃I�[�o�[���C�h
	void Update() {
		//�e�̕`�揈��
		CSceneTitle::Render();
	}
	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
