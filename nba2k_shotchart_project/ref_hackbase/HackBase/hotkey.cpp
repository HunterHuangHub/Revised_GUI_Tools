#include "trainerbase.h"

bool made_shot_Z_down = false;

bool IsKeyDown(DWORD key) {
	if (GetAsyncKeyState(key)) {
		return true;
	}
	return false;
}

void SaveDataFileHeader() {

}


void UpdateHotkeys() {
	// made_shot_Z_down = false;
	if (IsKeyDown(VK_F6)) {
		record_shot_chart_and_more = !record_shot_chart_and_more;
		SaveDataFileHeader();
		// ��ʾ����ǰ�����Ѽ�¼����graphic�� update bool��
		// 
	}
	if (IsKeyDown(VK_F8)) {
		clear_screen = !clear_screen;
	}
	IsKeyDown('Z') ? made_shot_Z_down = true : made_shot_Z_down = false;
}
