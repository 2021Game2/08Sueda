#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CUtil.h"
//
#include "CRes.h"

#include "Ckey.h"
//
#include "CMaterial.h"
//
#include "CCollisionManager.h"
//
#include "CWall.h"
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

CMatrix Matrix;

CSceneGame::~CSceneGame() {

}

void CSceneGame::Init() {
	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
	mFont.LoadTexture("FontG.png", 1, 4096 / 64);

	CRes::sModelX.Load(MODEL_FILE);
	CRes::sKnight.Load("knight\\knight_low.x");
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:�ړ�
	CRes::sKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:�ҋ@
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//3:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//4:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//5:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//6:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7:Attack1
	CRes::sKnight.SeparateAnimationSet(0, 520, 615, "attack2");//8:Attack2
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//9:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//10:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:�_�E��

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
	new CWall(CVector(-100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.0f));   //����
	new CWall(CVector(100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.0f));    //�E��
	new CWall(CVector(0.0f, 0.0f, 100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));    //���
	new CWall(CVector(0.0f, 0.0f, -100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));   //����
	//����(����)�̔z�u
	new CWall(CVector(10.0f, 0.0f, -70.0f), CVector(), CVector(0.0f, 10.0f, 30.0f));
	new CWall(CVector(30.0f, 0.0f, -40.0f), CVector(), CVector(20.0f, 10.0f, 0.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(90.0f, 0.0f, -40.0f), CVector(), CVector(10.0f, 10.0f, 0.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall_R(CVector(65.0f, 0.0f, -40.0f), CVector(), CVector(15.0f, 10.0f, 0.0f));  //����ȕ�(��)
	//����(����)�̔z�u
	new CWall(CVector(55.0f, 0.0f, -30.0f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(10.0f, 0.0f, 10.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(20.0f, 0.0f, 15.0f), CVector(), CVector(0.0f, 10.0f, 45.0f));
	new CWall(CVector(15.0f, 0.0f, 60.0f), CVector(), CVector(5.0f, 10.0f, 0.0f));
	new CWall(CVector(80.0f, 0.0f, 15.0f), CVector(), CVector(0.0f, 10.0f, 25.0f));
	new CWall(CVector(50.0f, 0.0f, 40.0f), CVector(), CVector(30.0f, 10.0f, 0.0f));
	new CWall(CVector(60.0f, 0.0f, -10.0f), CVector(), CVector(20.0f, 10.0f, 0.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(55.0f, 0.0f, 60.0f), CVector(), CVector(25.0f, 10.0f, 0.0f));     //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(30.0f, 0.0f, 80.0f), CVector(), CVector(0.0f, 10.0f, 20.0f));
	new CWall_G(CVector(90.0f, 0.0f, 60.0f), CVector(), CVector(10.0f, 10.0f, 0.0f));   //����ȕ�(��)
	new CWall_I(CVector(30.0f, 0.0f, -10.0f), CVector(), CVector(10.0f, 10.0f, 0.0f));  //����ȕ�(��)
	//����(�E��)�̔z�u
	new CWall(CVector(-10.0f, 0.0f, -90.0f), CVector(), CVector(0.0f, 10.0f, 10.0f));
	new CWall(CVector(-30.0f, 0.0f, -80.0f), CVector(), CVector(20.0f, 10.0f, 0.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(-85.0f, 0.0f, -80.0f), CVector(), CVector(15.0f, 10.0f, 0.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall_Y(CVector(-60.0f, 0.0f, -80.0f), CVector(), CVector(10.0f, 10.0f, 0.0f)); //����ȕ�(��)
	//����(�E���S)�̔z�u
	new CWall(CVector(-55.0f, 0.0f, -70.0f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(-10.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-30.0f, 0.0f, 10.0f), CVector(), CVector(20.0f, 10.0f, 0.0f));
	new CWall(CVector(-50.0f, 0.0f, -5.0f), CVector(), CVector(0.0f, 10.0f, 15.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(-50.0f, 0.0f, -55.0f), CVector(), CVector(0.0f, 10.0f, 15.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(-60.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-70.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-80.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall(CVector(-90.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));   //����ȕ�(��)�̋ߕӂ̕�
	new CWall_B(CVector(-50.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 10.0f)); //����ȕ�(��)
	new CWall_P(CVector(-85.0f, 0.0f, 10.0f), CVector(), CVector(5.0f, 10.0f, 0.0f));   //����ȕ�(��)
	//����(�E��)�̔z�u
	new CWall(CVector(-55.0f, 0.0f, 20.0f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(-10.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-20.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-30.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-40.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-50.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-60.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-70.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-80.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-90.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));    //����ȕ�(��)�̋ߕӂ̕�
	new CWall_O(CVector(-90.0f, 0.0f, 95.0f), CVector(), CVector(0.0f, 10.0f, 5.0f));   //����ȕ�(��)
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
	new CCube_O(CVector(90.0f, 0.0f, 15.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));     //��
	new CCube_Y(CVector(15.0f, 0.0f, -25.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //��
	new CCube_G(CVector(-95.0f, 0.0f, -90.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //��
	new CCube_B(CVector(-75.0f, 0.0f, 95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //��
	new CCube_I(CVector(-65.0f, 0.0f, -65.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //��
	new CCube_P(CVector(95.0f, 0.0f, -95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //��
}


void CSceneGame::Update() {

	//�L�����N�^�[�N���X�̍X�V
//	mPlayer.Update();
	//�G�̍X�V
//	mEnemy.Update();
	CTaskManager::Get()->Update();

	//�Փˏ���
	CCollisionManager::Get()->Collision();

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = CVector(0.0f, 5.0f, -10.0f) * mPlayer.mMatrix;
	//�����_�����߂�
	c = mPlayer.mPosition;
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;

	//�J�����N���X�̐ݒ�
	Camera.Set(e, c, u);
	Camera.Render();

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
	CTaskManager::Get()->Render();

	//�R���C�_�̕`��
	CCollisionManager::Get()->Render();

	//2D�`��J�n
	CUtil::Start2D(0, 800, 0, 600);

	mFont.DrawString("3D PROGRAMMING", 20, 20, 10, 12);

	//2D�̕`��I��
	CUtil::End2D();

	return;
}

