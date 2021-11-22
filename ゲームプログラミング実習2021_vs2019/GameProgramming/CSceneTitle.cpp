#include "CSceneTitle.h"
#include "CUtil.h"

//���̃V�[���̎擾
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}

CSceneTitle::CSceneTitle()
{
	//�e�N�X�`���t�@�C����ǂݍ���
	//�t�H���g�̐ݒ�
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

void CSceneTitle::Render() {
	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�����ҏW�G���A�̍쐬
	char buf[64];

	//�`��F�̐ݒ�(��)
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	//������̕`��
	mText.DrawString("R", -320, 0, 30, 30);
	//�`��F�̐ݒ�(��)
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	//������̕`��
	mText.DrawString("A", -260, 0, 30, 30);
	//�`��F�̐ݒ�(��)
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	//������̕`��
	mText.DrawString("I", -210, 0, 30, 30);
	//�`��F�̐ݒ�(��)
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	//������̕`��
	mText.DrawString("N", -160, 0, 30, 30);
	//�`��F�̐ݒ�(��)
	glColor4f(0.0f, 0.5f, 1.0f, 1.0f);
	//������̕`��
	mText.DrawString("B", -100, 0, 30, 30);
	//�`��F�̐ݒ�(��)
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	//������̕`��
	mText.DrawString("O", -40, 0, 30, 30);
	//�`��F�̐ݒ�(��)
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	//������̕`��
	mText.DrawString("W", 20, 0, 30, 30);
	//�`��F�̐ݒ�(���F)
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	//������̕`��
	mText.DrawString("BALL", 135, 0, 30, 30);
	//�`��F�̐ݒ�(��)
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	//������̕`��
	mText.DrawString("PUSH ENTER KEY", -210, -100, 16, 16);
	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓Q�[��
		mScene = EGAME;
	}
	
	//2D�̕`��I��
	CUtil::End2D();
}