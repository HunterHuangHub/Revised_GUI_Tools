#include "trainerbase.h"


bool IsKeyDown(DWORD key) {
	if (GetAsyncKeyState(key)) {
		return true;
	}
	return false;
}


void UpdateHotkeys() {
	if (IsKeyDown(VK_F6)) {
		record_shot_chart_and_more = !record_shot_chart_and_more;
		// ����Ҫ����Ƿ��¼����ʾ�ı�
	}
	if (IsKeyDown(VK_F8)) {
		clear_screen = !clear_screen;
	}
}
