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
	//テキストフォントの読み込みと設定
	mFont.LoadTexture("FontG.png", 1, 4096 / 64);

	CRes::sModelX.Load(MODEL_FILE);
	CRes::sKnight.Load("knight\\knight_low.x");
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:移動
	CRes::sKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:待機
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//3:ダミー
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//4:ダミー
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//5:ダミー
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//6:ダミー
	CRes::sKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7:Attack1
	CRes::sKnight.SeparateAnimationSet(0, 520, 615, "attack2");//8:Attack2
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//9:ダミー
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//10:ダミー
	CRes::sKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:ダウン

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
	new CWall(CVector(-100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.0f));   //左壁
	new CWall(CVector(100.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 10.0f, 100.0f));    //右壁
	new CWall(CVector(0.0f, 0.0f, 100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));    //上壁
	new CWall(CVector(0.0f, 0.0f, -100.0f), CVector(), CVector(100.0f, 10.0f, 0.0f));   //下壁
	//内壁(左下)の配置
	new CWall(CVector(10.0f, 0.0f, -70.0f), CVector(), CVector(0.0f, 10.0f, 30.0f));
	new CWall(CVector(30.0f, 0.0f, -40.0f), CVector(), CVector(20.0f, 10.0f, 0.0f));    //特殊な壁(赤)の近辺の壁
	new CWall(CVector(90.0f, 0.0f, -40.0f), CVector(), CVector(10.0f, 10.0f, 0.0f));    //特殊な壁(赤)の近辺の壁
	new CWall_R(CVector(65.0f, 0.0f, -40.0f), CVector(), CVector(15.0f, 10.0f, 0.0f));  //特殊な壁(赤)
	//内壁(左上)の配置
	new CWall(CVector(55.0f, 0.0f, -30.0f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(10.0f, 0.0f, 10.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(20.0f, 0.0f, 15.0f), CVector(), CVector(0.0f, 10.0f, 45.0f));
	new CWall(CVector(15.0f, 0.0f, 60.0f), CVector(), CVector(5.0f, 10.0f, 0.0f));
	new CWall(CVector(80.0f, 0.0f, 15.0f), CVector(), CVector(0.0f, 10.0f, 25.0f));
	new CWall(CVector(50.0f, 0.0f, 40.0f), CVector(), CVector(30.0f, 10.0f, 0.0f));
	new CWall(CVector(60.0f, 0.0f, -10.0f), CVector(), CVector(20.0f, 10.0f, 0.0f));    //特殊な壁(藍)の近辺の壁
	new CWall(CVector(55.0f, 0.0f, 60.0f), CVector(), CVector(25.0f, 10.0f, 0.0f));     //特殊な壁(緑)の近辺の壁
	new CWall(CVector(30.0f, 0.0f, 80.0f), CVector(), CVector(0.0f, 10.0f, 20.0f));
	new CWall_G(CVector(90.0f, 0.0f, 60.0f), CVector(), CVector(10.0f, 10.0f, 0.0f));   //特殊な壁(緑)
	new CWall_I(CVector(30.0f, 0.0f, -10.0f), CVector(), CVector(10.0f, 10.0f, 0.0f));  //特殊な壁(藍)
	//内壁(右下)の配置
	new CWall(CVector(-10.0f, 0.0f, -90.0f), CVector(), CVector(0.0f, 10.0f, 10.0f));
	new CWall(CVector(-30.0f, 0.0f, -80.0f), CVector(), CVector(20.0f, 10.0f, 0.0f));   //特殊な壁(黄)の近辺の壁
	new CWall(CVector(-85.0f, 0.0f, -80.0f), CVector(), CVector(15.0f, 10.0f, 0.0f));   //特殊な壁(黄)の近辺の壁
	new CWall_Y(CVector(-60.0f, 0.0f, -80.0f), CVector(), CVector(10.0f, 10.0f, 0.0f)); //特殊な壁(黄)
	//内壁(右中心)の配置
	new CWall(CVector(-55.0f, 0.0f, -70.0f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(-10.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-30.0f, 0.0f, 10.0f), CVector(), CVector(20.0f, 10.0f, 0.0f));
	new CWall(CVector(-50.0f, 0.0f, -5.0f), CVector(), CVector(0.0f, 10.0f, 15.0f));    //特殊な壁(青)の近辺の壁
	new CWall(CVector(-50.0f, 0.0f, -55.0f), CVector(), CVector(0.0f, 10.0f, 15.0f));   //特殊な壁(青)の近辺の壁
	new CWall(CVector(-60.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-70.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));
	new CWall(CVector(-80.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));   //特殊な壁(紫)の近辺の壁
	new CWall(CVector(-90.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 40.0f));   //特殊な壁(紫)の近辺の壁
	new CWall_B(CVector(-50.0f, 0.0f, -30.0f), CVector(), CVector(0.0f, 10.0f, 10.0f)); //特殊な壁(青)
	new CWall_P(CVector(-85.0f, 0.0f, 10.0f), CVector(), CVector(5.0f, 10.0f, 0.0f));   //特殊な壁(紫)
	//内壁(右上)の配置
	new CWall(CVector(-55.0f, 0.0f, 20.0f), CVector(), CVector(45.0f, 10.0f, 0.0f));
	new CWall(CVector(-10.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-20.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-30.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-40.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-50.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-60.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-70.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-80.0f, 0.0f, 65.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));
	new CWall(CVector(-90.0f, 0.0f, 55.0f), CVector(), CVector(0.0f, 10.0f, 35.0f));    //特殊な壁(橙)の近辺の壁
	new CWall_O(CVector(-90.0f, 0.0f, 95.0f), CVector(), CVector(0.0f, 10.0f, 5.0f));   //特殊な壁(橙)
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
	new CCube_O(CVector(90.0f, 0.0f, 15.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));     //橙
	new CCube_Y(CVector(15.0f, 0.0f, -25.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //黄
	new CCube_G(CVector(-95.0f, 0.0f, -90.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //緑
	new CCube_B(CVector(-75.0f, 0.0f, 95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //青
	new CCube_I(CVector(-65.0f, 0.0f, -65.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));   //藍
	new CCube_P(CVector(95.0f, 0.0f, -95.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));    //紫
}


void CSceneGame::Update() {

	//キャラクタークラスの更新
//	mPlayer.Update();
	//敵の更新
//	mEnemy.Update();
	CTaskManager::Get()->Update();

	//衝突処理
	CCollisionManager::Get()->Collision();

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = CVector(0.0f, 5.0f, -10.0f) * mPlayer.mMatrix;
	//注視点を求める
	c = mPlayer.mPosition;
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;

	//カメラクラスの設定
	Camera.Set(e, c, u);
	Camera.Render();

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
	CTaskManager::Get()->Render();

	//コライダの描画
	CCollisionManager::Get()->Render();

	//2D描画開始
	CUtil::Start2D(0, 800, 0, 600);

	mFont.DrawString("3D PROGRAMMING", 20, 20, 10, 12);

	//2Dの描画終了
	CUtil::End2D();

	return;
}

