#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CUtil.h"
//
#include "CRes.h"

#include "CKey.h"
//
#include "CMaterial.h"
//
#include "CCollisionManager.h"
//
#include "CTask.h"
//
#include "CSound.h"
//
#include "CWall.h"
#include "CWall2.h"
#include "CWall_R.h"
#include "CWall_O.h"
#include "CWall_Y.h"
#include "CWall_G.h"
#include "CWall_B.h"
#include "CWall_I.h"
#include "CWall_P.h"
//
#include "CBlock.h"
//
#include "CCube_R.h"
#include "CCube_O.h"
#include "CCube_Y.h"
#include "CCube_G.h"
#include "CCube_B.h"
#include "CCube_I.h"
#include "CCube_P.h"
//
#include "CBall_R.h"
#include "CBall_O.h"
#include "CBall_Y.h"
#include "CBall_G.h"
#include "CBall_B.h"
#include "CBall_I.h"
#include "CBall_P.h"

CMatrix Matrix;
int CSceneGame::Time = 0 * 60;
CSound Se;
CSound Se2;
CSound Se3;

CSceneGame::CSceneGame()
{
	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

CSceneGame::~CSceneGame() {
	CTaskManager::Get()->Delete();
}

void CSceneGame::Init() {
	//�T�E���h�t�@�C���̓ǂݍ���
	Se.Load("Explosion.wav");
	Se2.Load("se_enemy_dead03 (online-audio-converter.com).wav");
	Se3.Load("jump.wav");

	Time = 0 * 60;

//	CRes::sModelX.Load(MODEL_FILE);
//	CRes::sKnight.Load("knight\\knight_low.x");
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:�ړ�
//	CRes::sKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:�ҋ@
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//3:�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//4:�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//5:�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//6:�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7:Attack1
//	CRes::sKnight.SeparateAnimationSet(0, 520, 615, "attack2");//8:Attack2
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//9:�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//10:�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:�_�E��

	//�L�����N�^�[�Ƀ��f����ݒ�
	mPlayer.Init(&CRes::sModelX);

	//�G�̏����ݒ�
//	mEnemy.Init(&CRes::sKnight);
//	mEnemy.mAnimationFrameSize = 1024;
	//�G�̔z�u
//	mEnemy.mPosition = CVector(7.0f, 0.0f, 0.0f);
//	mEnemy.ChangeAnimation(2, true, 200);

	//�O�p�R���C�_�̊m�F
	mColliderTriangle.Set(NULL, NULL, CVector(-100.0f, 0.0f, -100.0f), CVector(-100.0f, 0.0f, 100.0f), CVector(100.0f, 0.0f, -100.0f));
	mColliderTriangle2.Set(NULL, NULL, CVector(100.0f, 0.0f, -100.0f), CVector(-100.0f, 0.0f, 100.0f), CVector(100.0f, 0.0f, 100.0f));

	//�O�ǂ̔z�u
	new CWall(CVector(-100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.3f));   //����
	new CWall(CVector(100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.3f));    //�E��
	new CWall(CVector(0.0f, 0.0f, 100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));    //���
	new CWall(CVector(0.0f, 0.0f, -100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));   //����
	//����(����)�̔z�u
	new CWall(CVector(10.0f, 0.0f, -70.0f), CVector(), CVector(0.0f, 10.0f, 30.0f));
	new CWall(CVector(30.0f, 0.0f, -40.3f), CVector(), CVector(20.0f, 10.0f, 0.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(90.0f, 0.0f, -40.3f), CVector(), CVector(10.0f, 10.0f, 0.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall_R(CVector(65.0f, 0.0f, -40.3f), CVector(), CVector(15.0f, 10.0f, 0.0f));  //����ȕ�(��)
	//����(����)�̔z�u
	new CWall(CVector(55.0f, 0.0f, -29.7f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(10.0f, 0.0f, 10.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(20.0f, 0.0f, 15.0f), CVector(), CVector(0.0f, 10.0f, 45.0f));
	new CWall(CVector(15.0f, 0.0f, 59.7f), CVector(), CVector(5.0f, 10.0f, 0.0f));
	new CWall(CVector(80.0f, 0.0f, 15.0f), CVector(), CVector(0.0f, 10.0f, 25.0f));
	new CWall(CVector(50.0f, 0.0f, 39.7f), CVector(), CVector(30.0f, 10.0f, 0.0f));
	new CWall(CVector(60.0f, 0.0f, -9.7f), CVector(), CVector(20.0f, 10.0f, 0.0f));     //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(55.0f, 0.0f, 60.3f), CVector(), CVector(25.0f, 10.0f, 0.0f));     //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(30.0f, 0.0f, 80.0f), CVector(), CVector(0.0f, 10.0f, 20.0f));
	new CWall_G(CVector(90.0f, 0.0f, 60.3f), CVector(), CVector(10.0f, 10.0f, 0.0f));   //����ȕ�(��)
	new CWall_I(CVector(30.0f, 0.0f, -9.7f), CVector(), CVector(10.0f, 10.0f, 0.0f));   //����ȕ�(��)
	//����(�E��)�̔z�u
	new CWall(CVector(-10.0f, 0.0f, -90.0f), CVector(), CVector(0.0f, 10.0f, 10.0f));
	new CWall(CVector(-30.0f, 0.0f, -80.3f), CVector(), CVector(20.0f, 10.0f, 0.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(-85.0f, 0.0f, -80.3f), CVector(), CVector(15.0f, 10.0f, 0.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall_O(CVector(-60.0f, 0.0f, -80.3f), CVector(), CVector(10.0f, 10.0f, 0.0f)); //����ȕ�(��)
	//����(�E���S)�̔z�u
	new CWall(CVector(-55.0f, 0.0f, -69.7f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(-10.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-30.0f, 0.0f, 9.7f), CVector(), CVector(20.0f, 10.0f, 0.0f));
	new CWall(CVector(-50.0f, 0.0f, -5.0f), CVector(), CVector(0.0f, 10.0f, 15.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(-50.0f, 0.0f, -55.0f), CVector(), CVector(0.0f, 10.0f, 15.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(-60.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-70.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-80.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(-90.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall_B(CVector(-50.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 10.0f)); //����ȕ�(��)
	new CWall_P(CVector(-85.0f, 0.0f, 9.7f), CVector(), CVector(4.7f, 10.0f, 0.0f));    //����ȕ�(��)
	//����(�E��)�̔z�u
	new CWall(CVector(-50.0f, 0.0f, 20.3f), CVector(), CVector(40.0f, 10.0f, 0.0f));
	new CWall(CVector(-10.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-20.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
//	new CWall(CVector(-30.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
//	new CWall(CVector(-40.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
//	new CWall(CVector(-50.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
//	new CWall(CVector(-60.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-70.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-80.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-90.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall2(CVector(-95.0f, 0.0f, 20.3f), CVector(), CVector(5.0f, 10.0f, 0.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall_Y(CVector(-90.0f, 0.0f, 95.0f), CVector(), CVector(0.0f, 10.0f, 5.0f));   //����ȕ�(��)
	//��Q���̔z�u
	new CBlock(CVector(60.0f, 0.0f, -70.0f), CVector(), CVector(30.0f, 1.0f, 15.0f));   //������1�i��
	new CBlock(CVector(60.0f, 2.0f, -70.0f), CVector(), CVector(20.0f, 1.0f, 5.0f));    //������2�i��
	new CBlock(CVector(55.0f, 0.0f, 80.0f), CVector(), CVector(10.0f, 1.0f, 10.0f));    //����̃{�[��(��)��1�i��
	new CBlock(CVector(40.0f, 0.0f, 15.0f), CVector(), CVector(10.0f, 2.0f, 15.0f));    //����̃{�[��(��)��2�i��
	new CBlock(CVector(55.0f, 0.0f, 15.0f), CVector(), CVector(5.0f, 1.0f, 10.0f));     //����̃{�[��(��)��1�i��
	new CBlock(CVector(-30.0f, 0.0f, -10.0f), CVector(), CVector(15.0f, 2.0f, 10.0f));  //�E���S�̃{�[��(��)��2�i��
	new CBlock(CVector(-30.0f, 0.0f, -25.0f), CVector(), CVector(10.0f, 1.0f, 5.0f));   //�E���S�̃{�[��(��)��1�i��
	//�l�p�`�̃X�C�b�`�̔z�u
	new CCube_R(CVector(-95.0f, 0.0f, -75.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //��
//	new CCube_R(CVector(5.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));       //��(��)
	new CCube_O(CVector(15.0f, 0.0f, -25.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //��
//	new CCube_O(CVector(5.0f, 1.0f, -5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));      //��(��)
	new CCube_Y(CVector(90.0f, 0.0f, 15.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));     //��
//	new CCube_Y(CVector(5.0f, 1.0f, -10.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));     //��(��)
	new CCube_G(CVector(-95.0f, 0.0f, -95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //��
//	new CCube_G(CVector(0.0f, 1.0f, 5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));       //��(��)
	new CCube_B(CVector(-45.0f, 10.0f, 95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //��
//	new CCube_B(CVector(0.0f, 1.0f, -5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));      //��(��)
	new CCube_I(CVector(-65.0f, 0.0f, -65.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //��
//	new CCube_I(CVector(-5.0f, 1.0f, 5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));      //��(��)
	new CCube_P(CVector(95.0f, 0.0f, -95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //��
//	new CCube_P(CVector(-5.0f, 1.0f, -5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));     //��(��)
	//�{�[���̔z�u
	new CBall_R(CVector(60.0f, 6.0f, -70.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));    //��
//	new CBall_R(CVector(5.0f, 1.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));       //��(��)
	new CBall_O(CVector(-15.0f, 2.0f, -90.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));   //��
//	new CBall_O(CVector(5.0f, 1.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));      //��(��)
	new CBall_Y(CVector(-95.0f, 2.0f, 25.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));    //��
//	new CBall_Y(CVector(5.0f, 1.0f, -10.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));     //��(��)
	new CBall_G(CVector(55.0f, 4.0f, 80.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));     //��
//	new CBall_G(CVector(0.0f, 1.0f, 5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));       //��(��)
	new CBall_B(CVector(-30.0f, 6.0f, -10.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));   //��
//	new CBall_B(CVector(0.0f, 1.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));      //��(��)
	new CBall_I(CVector(40.0f, 6.0f, 15.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));     //��
//	new CBall_I(CVector(-5.0f, 1.0f, 5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));      //��(��)
	new CBall_P(CVector(-85.0f, 2.0f, -65.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));   //��
//	new CBall_P(CVector(-5.0f, 1.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));     //��(��)

	//�V�[���̐ݒ�
	mScene = EGAME;

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;  //���_�A�����_�A�����
	//���_�����߂�
	e = CVector(0.0f, 5.0f, -10.0f) * mPlayer.mMatrix;
	//�����_�����߂�
	c = mPlayer.mPosition;
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;

	//�J�����N���X�̐ݒ�
	Camera.Set(e, c, u);
}


void CSceneGame::Update() {

	//�L�����N�^�[�N���X�̍X�V
//	mPlayer.Update();
	//�G�̍X�V
//	mEnemy.Update();
	CTaskManager::Get()->Update();

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = CVector(0.0f, 5.0f, -10.0f) * mPlayer.mMatrix;
	//�����_�����߂�
	c = mPlayer.mPosition;
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;

	//�J�����N���X�̐ݒ�
//	Camera.Set(e, c, u);
	Camera.Set(e, c);
	//�Փˏ���
//	CCollisionManager::Get()->Collision();
	CTaskManager::Get()->TaskCollision();
//	Camera.Render();

	//X���{��]
//	if (CKey::Push('K')) {
//		Matrix = Matrix * CMatrix().RotateX(1);
//	}
//	if (CKey::Push('I')) {
//		Matrix = Matrix * CMatrix().RotateX(-1);
//	}
	//Y���{��]
//	if (CKey::Push('L')) {
//		Matrix = Matrix * CMatrix().RotateY(1);
//	}
//	if (CKey::Push('J')) {
//		Matrix = Matrix * CMatrix().RotateY(-1);
//	}

	//�s��ݒ�
	glMultMatrixf(Matrix.mF);

	//���f���`��
//	CRes::sModelX.Render();
//	mPlayer.Render();
	//�G�`��
//	mEnemy.Render();
	//�}�b�v�`��
//	mMap.Render();

	CTaskManager::Get()->Delete();

	CTaskManager::Get()->Render();

	//�R���C�_�̕`��
	CCollisionManager::Get()->Render();

	//�e�̕`�揈��
	CSceneGame::Render();

	return;
}

void CSceneGame::Render() {
	//2D�`��J�n
	CUtil::Start2D(0, 800, 0, 600);
	//�����ҏW�G���A�̍쐬
	char buf[64];
	//�`��F�̐ݒ�(��)
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	//���Ԃ̕\��
	sprintf(buf, "TIME %d", Time / 60);
	if (Time > -1) {
		Time++;
	}
	mText.DrawString(buf, 550, 20, 16, 16);

	//�S�Ẵ{�[����j�󂷂�ƃQ�[���N���A
	if (CBall_P::spInstance->mHp <= 0) {
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("GAME CLEAR!!", 70, 300, 30, 30);
		mText.DrawString("PUSH ENTER KEY", 180, 200, 16, 16);
		Time--;
		if (CKey::Once(VK_RETURN)) {
			mScene = ETITLE;
		}
	}

	//�����N���A!
	else if (CBall_I::spInstance->mHp <= 0) {
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		mText.DrawString("PURPLE", 20, 20, 16, 16);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 215, 18, 10, 10);
		mText.DrawString("CLEAR!", 305, 20, 16, 16);
	}
	//������
	else if (CBall_B::spInstance->mHp <= 0) {
		//�`��F�̐ݒ�(��)
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		mText.DrawString("INDIGO", 20, 20, 16, 16);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 215, 18, 10, 10);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		mText.DrawString("PURPLE", 305, 20, 16, 16);
	}
	//����
	else if (CBall_G::spInstance->mHp <= 0) {
		//�`��F�̐ݒ�(��)
		glColor4f(0.0f, 0.5f, 1.0f, 1.0f);
		mText.DrawString("BRUE", 20, 20, 16, 16);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 150, 18, 10, 10);
		//�`��F�̐ݒ�(��)
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		mText.DrawString("INDIGO", 235, 20, 16, 16);
	}
	//�΁���
	else if (CBall_Y::spInstance->mHp <= 0) {
		//�`��F�̐ݒ�(��)
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		mText.DrawString("GREEN", 20, 20, 16, 16);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 180, 18, 10, 10);
		//�`��F�̐ݒ�(��)
		glColor4f(0.0f, 0.5f, 1.0f, 1.0f);
		mText.DrawString("BRUE", 270, 20, 16, 16);
	}
	//������
	else if (CBall_O::spInstance->mHp <= 0) {
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		mText.DrawString("YELLOW", 20, 20, 16, 16);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 215, 18, 10, 10);
		//�`��F�̐ݒ�(��)
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		mText.DrawString("GREEN", 305, 20, 16, 16);
	}
	//�򁨉�
	else if (CBall_R::spInstance->mHp <= 0) {
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		mText.DrawString("ORANGE", 20, 20, 16, 16);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 215, 18, 10, 10);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		mText.DrawString("YELLOW", 300, 20, 16, 16);
	}
	else {
		//�ԁ���
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		mText.DrawString("RED", 20, 20, 16, 16);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 120, 18, 10, 10);
		//�`��F�̐ݒ�(��)
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		mText.DrawString("ORANGE", 210, 20, 16, 16);
	}
	//2D�̕`��I��
	CUtil::End2D();
}

//���̃V�[���̎擾
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}