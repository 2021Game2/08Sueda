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
ゲームのシーン
*/
class CSceneGame : public CScene {
private:
	CMap mMap;
	//キャラクタのインスタンス
	CXPlayer mPlayer;
	//敵のインスタンス
//	CXEnemy mEnemy;
	//三角コライダの作成
	CColliderTriangle mColliderTriangle;
	CColliderTriangle mColliderTriangle2;
public:
	CText mText;

	static int Time;
	//デフォルトコンストラクタ
	CSceneGame();
	//デストラクタ
	~CSceneGame();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//描画処理
	void Render();
	//次のシーンの取得
	EScene GetNextScene();
};

#endif
