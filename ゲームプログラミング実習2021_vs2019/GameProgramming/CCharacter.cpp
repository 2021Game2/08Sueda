#include "CCharacter.h"
#include "CTaskManager.h"

//描画処理
void CCharacter::Render()
{
	if (mpModel != nullptr)
	{
		mpModel->Render(mMatrix);
	}
}

CCharacter::~CCharacter() {
	//タスクリストから削除
	CTaskManager::Get()->Remove(this);
}

CCharacter::CCharacter()
:mTag(EZERO)
,mpModel(nullptr)
{
	//タスクリストに追加
	CTaskManager::Get()->Add(this);
}

