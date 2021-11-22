#include "CSceneTitle.h"
#include "CUtil.h"

//次のシーンの取得
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}

CSceneTitle::CSceneTitle()
{
	//テクスチャファイルを読み込む
	//フォントの設定
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

void CSceneTitle::Render() {
	//2Dの描画開始
	CUtil::Start2D(-400, 400, -300, 300);
	//文字編集エリアの作成
	char buf[64];

	//描画色の設定(赤)
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	//文字列の描画
	mText.DrawString("R", -320, 0, 30, 30);
	//描画色の設定(橙)
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	//文字列の描画
	mText.DrawString("A", -260, 0, 30, 30);
	//描画色の設定(黄)
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	//文字列の描画
	mText.DrawString("I", -210, 0, 30, 30);
	//描画色の設定(緑)
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	//文字列の描画
	mText.DrawString("N", -160, 0, 30, 30);
	//描画色の設定(青)
	glColor4f(0.0f, 0.5f, 1.0f, 1.0f);
	//文字列の描画
	mText.DrawString("B", -100, 0, 30, 30);
	//描画色の設定(藍)
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	//文字列の描画
	mText.DrawString("O", -40, 0, 30, 30);
	//描画色の設定(紫)
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	//文字列の描画
	mText.DrawString("W", 20, 0, 30, 30);
	//描画色の設定(水色)
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	//文字列の描画
	mText.DrawString("BALL", 135, 0, 30, 30);
	//描画色の設定(黒)
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	//文字列の描画
	mText.DrawString("PUSH ENTER KEY", -210, -100, 16, 16);
	if (CKey::Once(VK_RETURN)) {
		//次のシーンはゲーム
		mScene = EGAME;
	}
	
	//2Dの描画終了
	CUtil::End2D();
}