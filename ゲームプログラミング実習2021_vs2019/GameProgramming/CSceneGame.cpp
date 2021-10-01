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

#include "CWall.h"

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

	//�ǂ̔z�u
	new CWall(CVector(-100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.0f));  //����
	new CWall(CVector(100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.0f));   //�E��
	new CWall(CVector(0.0f, 0.0f, 100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));   //���
	new CWall(CVector(0.0f, 0.0f, -100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));  //����
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

