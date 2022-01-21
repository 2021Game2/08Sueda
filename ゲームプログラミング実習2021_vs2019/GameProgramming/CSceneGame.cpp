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
	//テキストフォントの読み込みと設定
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

CSceneGame::~CSceneGame() {
	CTaskManager::Get()->Delete();
}

void CSceneGame::Init() {
	//サウンドファイルの読み込み
	Se.Load("Explosion.wav");
	Se2.Load("se_enemy_dead03 (online-audio-converter.com).wav");
	Se3.Load("jump.wav");

	Time = 0 * 60;

//	CRes::sModelX.Load(MODEL_FILE);
//	CRes::sKnight.Load("knight\\knight_low.x");
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:移動
//	CRes::sKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:待機
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//3:ダミー
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//4:ダミー
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//5:ダミー
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//6:ダミー
//	CRes::sKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7:Attack1
//	CRes::sKnight.SeparateAnimationSet(0, 520, 615, "attack2");//8:Attack2
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//9:ダミー
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//10:ダミー
//	CRes::sKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:ダウン

	//キャラクターにモデルを設定
	mPlayer.Init(&CRes::sModelX);

	//敵の初期設定
//	mEnemy.Init(&CRes::sKnight);
//	mEnemy.mAnimationFrameSize = 1024;
	//敵の配置
//	mEnemy.mPosition = CVector(7.0f, 0.0f, 0.0f);
//	mEnemy.ChangeAnimation(2, true, 200);

	//三角コライダの確認
	mColliderTriangle.Set(NULL, NULL, CVector(-100.0f, 0.0f, -100.0f), CVector(-100.0f, 0.0f, 100.0f), CVector(100.0f, 0.0f, -100.0f));
	mColliderTriangle2.Set(NULL, NULL, CVector(100.0f, 0.0f, -100.0f), CVector(-100.0f, 0.0f, 100.0f), CVector(100.0f, 0.0f, 100.0f));

	//外壁の配置
	new CWall(CVector(-100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.3f));   //左壁
	new CWall(CVector(100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.3f));    //右壁
	new CWall(CVector(0.0f, 0.0f, 100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));    //上壁
	new CWall(CVector(0.0f, 0.0f, -100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));   //下壁
	//内壁(左下)の配置
	new CWall(CVector(10.0f, 0.0f, -70.0f), CVector(), CVector(0.0f, 10.0f, 30.0f));
	new CWall(CVector(30.0f, 0.0f, -40.3f), CVector(), CVector(20.0f, 10.0f, 0.0f));    //特殊な壁(赤)の近辺の壁
	new CWall(CVector(90.0f, 0.0f, -40.3f), CVector(), CVector(10.0f, 10.0f, 0.0f));    //特殊な壁(赤)の近辺の壁
	new CWall_R(CVector(65.0f, 0.0f, -40.3f), CVector(), CVector(15.0f, 10.0f, 0.0f));  //特殊な壁(赤)
	//内壁(左上)の配置
	new CWall(CVector(55.0f, 0.0f, -29.7f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(10.0f, 0.0f, 10.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(20.0f, 0.0f, 15.0f), CVector(), CVector(0.0f, 10.0f, 45.0f));
	new CWall(CVector(15.0f, 0.0f, 59.7f), CVector(), CVector(5.0f, 10.0f, 0.0f));
	new CWall(CVector(80.0f, 0.0f, 15.0f), CVector(), CVector(0.0f, 10.0f, 25.0f));
	new CWall(CVector(50.0f, 0.0f, 39.7f), CVector(), CVector(30.0f, 10.0f, 0.0f));
	new CWall(CVector(60.0f, 0.0f, -9.7f), CVector(), CVector(20.0f, 10.0f, 0.0f));     //特殊な壁(藍)の近辺の壁
	new CWall(CVector(55.0f, 0.0f, 60.3f), CVector(), CVector(25.0f, 10.0f, 0.0f));     //特殊な壁(緑)の近辺の壁
	new CWall(CVector(30.0f, 0.0f, 80.0f), CVector(), CVector(0.0f, 10.0f, 20.0f));
	new CWall_G(CVector(90.0f, 0.0f, 60.3f), CVector(), CVector(10.0f, 10.0f, 0.0f));   //特殊な壁(緑)
	new CWall_I(CVector(30.0f, 0.0f, -9.7f), CVector(), CVector(10.0f, 10.0f, 0.0f));   //特殊な壁(藍)
	//内壁(右下)の配置
	new CWall(CVector(-10.0f, 0.0f, -90.0f), CVector(), CVector(0.0f, 10.0f, 10.0f));
	new CWall(CVector(-30.0f, 0.0f, -80.3f), CVector(), CVector(20.0f, 10.0f, 0.0f));   //特殊な壁(橙)の近辺の壁
	new CWall(CVector(-85.0f, 0.0f, -80.3f), CVector(), CVector(15.0f, 10.0f, 0.0f));   //特殊な壁(橙)の近辺の壁
	new CWall_O(CVector(-60.0f, 0.0f, -80.3f), CVector(), CVector(10.0f, 10.0f, 0.0f)); //特殊な壁(橙)
	//内壁(右中心)の配置
	new CWall(CVector(-55.0f, 0.0f, -69.7f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(-10.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-30.0f, 0.0f, 9.7f), CVector(), CVector(20.0f, 10.0f, 0.0f));
	new CWall(CVector(-50.0f, 0.0f, -5.0f), CVector(), CVector(0.0f, 10.0f, 15.0f));    //特殊な壁(青)の近辺の壁
	new CWall(CVector(-50.0f, 0.0f, -55.0f), CVector(), CVector(0.0f, 10.0f, 15.0f));   //特殊な壁(青)の近辺の壁
	new CWall(CVector(-60.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-70.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-80.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));   //特殊な壁(紫)の近辺の壁
	new CWall(CVector(-90.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));   //特殊な壁(紫)の近辺の壁
	new CWall_B(CVector(-50.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 10.0f)); //特殊な壁(青)
	new CWall_P(CVector(-85.0f, 0.0f, 9.7f), CVector(), CVector(4.7f, 10.0f, 0.0f));    //特殊な壁(紫)
	//内壁(右上)の配置
	new CWall(CVector(-50.0f, 0.0f, 20.3f), CVector(), CVector(40.0f, 10.0f, 0.0f));
	new CWall(CVector(-10.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-20.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
//	new CWall(CVector(-30.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
//	new CWall(CVector(-40.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
//	new CWall(CVector(-50.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
//	new CWall(CVector(-60.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-70.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-80.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-90.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));    //特殊な壁(黄)の近辺の壁
	new CWall2(CVector(-95.0f, 0.0f, 20.3f), CVector(), CVector(5.0f, 10.0f, 0.0f));    //特殊な壁(黄)の近辺の壁
	new CWall_Y(CVector(-90.0f, 0.0f, 95.0f), CVector(), CVector(0.0f, 10.0f, 5.0f));   //特殊な壁(黄)
	//障害物の配置
	new CBlock(CVector(60.0f, 0.0f, -70.0f), CVector(), CVector(30.0f, 1.0f, 15.0f));   //左下の1段目
	new CBlock(CVector(60.0f, 2.0f, -70.0f), CVector(), CVector(20.0f, 1.0f, 5.0f));    //左下の2段目
	new CBlock(CVector(55.0f, 0.0f, 80.0f), CVector(), CVector(10.0f, 1.0f, 10.0f));    //左上のボール(緑)の1段目
	new CBlock(CVector(40.0f, 0.0f, 15.0f), CVector(), CVector(10.0f, 2.0f, 15.0f));    //左上のボール(藍)の2段目
	new CBlock(CVector(55.0f, 0.0f, 15.0f), CVector(), CVector(5.0f, 1.0f, 10.0f));     //左上のボール(藍)の1段目
	new CBlock(CVector(-30.0f, 0.0f, -10.0f), CVector(), CVector(15.0f, 2.0f, 10.0f));  //右中心のボール(青)の2段目
	new CBlock(CVector(-30.0f, 0.0f, -25.0f), CVector(), CVector(10.0f, 1.0f, 5.0f));   //右中心のボール(青)の1段目
	//四角形のスイッチの配置
	new CCube_R(CVector(-95.0f, 0.0f, -75.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //赤
//	new CCube_R(CVector(5.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));       //赤(仮)
	new CCube_O(CVector(15.0f, 0.0f, -25.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //橙
//	new CCube_O(CVector(5.0f, 1.0f, -5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));      //橙(仮)
	new CCube_Y(CVector(90.0f, 0.0f, 15.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));     //黄
//	new CCube_Y(CVector(5.0f, 1.0f, -10.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));     //黄(仮)
	new CCube_G(CVector(-95.0f, 0.0f, -95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //緑
//	new CCube_G(CVector(0.0f, 1.0f, 5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));       //緑(仮)
	new CCube_B(CVector(-45.0f, 10.0f, 95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //青
//	new CCube_B(CVector(0.0f, 1.0f, -5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));      //青(仮)
	new CCube_I(CVector(-65.0f, 0.0f, -65.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //藍
//	new CCube_I(CVector(-5.0f, 1.0f, 5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));      //藍(仮)
	new CCube_P(CVector(95.0f, 0.0f, -95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //紫
//	new CCube_P(CVector(-5.0f, 1.0f, -5.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));     //紫(仮)
	//ボールの配置
	new CBall_R(CVector(60.0f, 6.0f, -70.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));    //赤
//	new CBall_R(CVector(5.0f, 1.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));       //赤(仮)
	new CBall_O(CVector(-15.0f, 2.0f, -90.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));   //橙
//	new CBall_O(CVector(5.0f, 1.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));      //橙(仮)
	new CBall_Y(CVector(-95.0f, 2.0f, 25.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));    //黄
//	new CBall_Y(CVector(5.0f, 1.0f, -10.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));     //黄(仮)
	new CBall_G(CVector(55.0f, 4.0f, 80.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));     //緑
//	new CBall_G(CVector(0.0f, 1.0f, 5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));       //緑(仮)
	new CBall_B(CVector(-30.0f, 6.0f, -10.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));   //青
//	new CBall_B(CVector(0.0f, 1.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));      //青(仮)
	new CBall_I(CVector(40.0f, 6.0f, 15.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));     //藍
//	new CBall_I(CVector(-5.0f, 1.0f, 5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));      //藍(仮)
	new CBall_P(CVector(-85.0f, 2.0f, -65.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));   //紫
//	new CBall_P(CVector(-5.0f, 1.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f));     //紫(仮)

	//シーンの設定
	mScene = EGAME;

	//カメラのパラメータを作成する
	CVector e, c, u;  //視点、注視点、上方向
	//視点を求める
	e = CVector(0.0f, 5.0f, -10.0f) * mPlayer.mMatrix;
	//注視点を求める
	c = mPlayer.mPosition;
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;

	//カメラクラスの設定
	Camera.Set(e, c, u);
}


void CSceneGame::Update() {

	//キャラクタークラスの更新
//	mPlayer.Update();
	//敵の更新
//	mEnemy.Update();
	CTaskManager::Get()->Update();

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = CVector(0.0f, 5.0f, -10.0f) * mPlayer.mMatrix;
	//注視点を求める
	c = mPlayer.mPosition;
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;

	//カメラクラスの設定
//	Camera.Set(e, c, u);
	Camera.Set(e, c);
	//衝突処理
//	CCollisionManager::Get()->Collision();
	CTaskManager::Get()->TaskCollision();
//	Camera.Render();

	//X軸＋回転
//	if (CKey::Push('K')) {
//		Matrix = Matrix * CMatrix().RotateX(1);
//	}
//	if (CKey::Push('I')) {
//		Matrix = Matrix * CMatrix().RotateX(-1);
//	}
	//Y軸＋回転
//	if (CKey::Push('L')) {
//		Matrix = Matrix * CMatrix().RotateY(1);
//	}
//	if (CKey::Push('J')) {
//		Matrix = Matrix * CMatrix().RotateY(-1);
//	}

	//行列設定
	glMultMatrixf(Matrix.mF);

	//モデル描画
//	CRes::sModelX.Render();
//	mPlayer.Render();
	//敵描画
//	mEnemy.Render();
	//マップ描画
//	mMap.Render();

	CTaskManager::Get()->Delete();

	CTaskManager::Get()->Render();

	//コライダの描画
	CCollisionManager::Get()->Render();

	//親の描画処理
	CSceneGame::Render();

	return;
}

void CSceneGame::Render() {
	//2D描画開始
	CUtil::Start2D(0, 800, 0, 600);
	//文字編集エリアの作成
	char buf[64];
	//描画色の設定(白)
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	//時間の表示
	sprintf(buf, "TIME %d", Time / 60);
	if (Time > -1) {
		Time++;
	}
	mText.DrawString(buf, 550, 20, 16, 16);

	//全てのボールを破壊するとゲームクリア
	if (CBall_P::spInstance->mHp <= 0) {
		//描画色の設定(白)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("GAME CLEAR!!", 70, 300, 30, 30);
		mText.DrawString("PUSH ENTER KEY", 180, 200, 16, 16);
		Time--;
		if (CKey::Once(VK_RETURN)) {
			mScene = ETITLE;
		}
	}

	//紫→クリア!
	else if (CBall_I::spInstance->mHp <= 0) {
		//描画色の設定(紫)
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		mText.DrawString("PURPLE", 20, 20, 16, 16);
		//描画色の設定(白)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 215, 18, 10, 10);
		mText.DrawString("CLEAR!", 305, 20, 16, 16);
	}
	//藍→紫
	else if (CBall_B::spInstance->mHp <= 0) {
		//描画色の設定(藍)
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		mText.DrawString("INDIGO", 20, 20, 16, 16);
		//描画色の設定(白)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 215, 18, 10, 10);
		//描画色の設定(紫)
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		mText.DrawString("PURPLE", 305, 20, 16, 16);
	}
	//青→藍
	else if (CBall_G::spInstance->mHp <= 0) {
		//描画色の設定(青)
		glColor4f(0.0f, 0.5f, 1.0f, 1.0f);
		mText.DrawString("BRUE", 20, 20, 16, 16);
		//描画色の設定(白)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 150, 18, 10, 10);
		//描画色の設定(藍)
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		mText.DrawString("INDIGO", 235, 20, 16, 16);
	}
	//緑→青
	else if (CBall_Y::spInstance->mHp <= 0) {
		//描画色の設定(緑)
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		mText.DrawString("GREEN", 20, 20, 16, 16);
		//描画色の設定(白)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 180, 18, 10, 10);
		//描画色の設定(青)
		glColor4f(0.0f, 0.5f, 1.0f, 1.0f);
		mText.DrawString("BRUE", 270, 20, 16, 16);
	}
	//黄→緑
	else if (CBall_O::spInstance->mHp <= 0) {
		//描画色の設定(黄)
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		mText.DrawString("YELLOW", 20, 20, 16, 16);
		//描画色の設定(白)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 215, 18, 10, 10);
		//描画色の設定(緑)
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		mText.DrawString("GREEN", 305, 20, 16, 16);
	}
	//橙→黄
	else if (CBall_R::spInstance->mHp <= 0) {
		//描画色の設定(橙)
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		mText.DrawString("ORANGE", 20, 20, 16, 16);
		//描画色の設定(白)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 215, 18, 10, 10);
		//描画色の設定(黄)
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		mText.DrawString("YELLOW", 300, 20, 16, 16);
	}
	else {
		//赤→橙
		//描画色の設定(赤)
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		mText.DrawString("RED", 20, 20, 16, 16);
		//描画色の設定(白)
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mText.DrawString("NEXT", 120, 18, 10, 10);
		//描画色の設定(橙)
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		mText.DrawString("ORANGE", 210, 20, 16, 16);
	}
	//2Dの描画終了
	CUtil::End2D();
}

//次のシーンの取得
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}