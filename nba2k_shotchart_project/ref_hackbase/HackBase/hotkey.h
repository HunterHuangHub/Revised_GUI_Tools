#pragma once

#include "hackbase.h"

char F7_text[] = "F7 toggled.";

bool all_players_god_mode = false;
bool record_shot_chart_and_more = false;
bool made_shot_prediction = false;

// not as cool as scripthook which is well polished code.
bool IsKeyDown(DWORD key) {
	if (GetAsyncKeyState(key)) {
		return true;
	}
	return false;
}

void UpdateHotkey(HackBase *mHackBase) {
	if (IsKeyDown(VK_F7)) {
		made_shot_prediction = !made_shot_prediction;
		// renderer�Ǹ���ÿһ֡ˢ�½���hook�ģ������Ҫ��ʱ��������Ļ�ϣ�Ҫô��render��ס��Ҫô�ظ���ÿһ֡дֱ����֡
		mHackBase->getRenderer()->DrawText((int)(0.5 * mHackBase->getRenderer()->GetWidth()), (int)(0.5 * mHackBase->getRenderer()->GetHeight()), FontColor_default, F7_text);
	}
}