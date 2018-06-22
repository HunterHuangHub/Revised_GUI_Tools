#include "trainerbase.h"

int border_width = 2;
int column_width = 280;
int column_height = 45;

// F6 display data and coordinates
// char* score_type_text;
int score_type = 0;
int score_judge = 0;
char* score_type_text = NULL;
char* score_judge_text = NULL;
char score_type_0[] = "����մ";
char score_type_1[] = "�ҿ�";
char score_type_2[] = "��ˢ";
char score_type_3[] = "���";
char score_type_8[] = "�����";
char score_type_other[] = "����";
char score_judge_0[] = "û��";
char score_judge_1[] = "����";


// F7 god_mode related
// char 
char* F7_text = F7_text_f;
char F7_text_f[] = "GodMode: Off";
char F7_text_t[] = "GodMode: On";


// F8 toggle dashboard on/off


bool record_shot_chart_and_more = false;
bool made_shot_prediction = false;
bool clear_screen = false;
bool clear_screen_already_cleared = false;
bool all_players_god_mode = false;

void onRender_clear(Renderer *renderer) {
	// by default we do not draw things on the screen. this is the default.
}

void onRender_dashboard(Renderer *renderer) {
	// draw rect background
	/*
	renderer->DrawRect(0, 0, 1 * column_width, column_height, GRAY(64));
	renderer->DrawRect(0, 0, 2 * column_width, column_height, GRAY(64));
	renderer->DrawRect(0, 0, 3 * column_width, column_height, GRAY(64));
	renderer->DrawRect(0, 0, 4 * column_width, column_height, GRAY(64));
	*/
	// draw border
	renderer->DrawBorder(0, 0, 1 * column_width, column_height, border_width, GREEN(255));
	renderer->DrawBorder(0, 0, 2 * column_width, column_height, border_width, GREEN(255));
	renderer->DrawBorder(0, 0, 3 * column_width, column_height, border_width, GREEN(255));
	// renderer->DrawBorder(0, 0, 4 * column_width, column_height, border_width, GREEN(255));
	// draw text
	

	renderer->DrawText(border_width, 1 + border_width, FontColor_default, F7_text);
	renderer->DrawText(border_width + column_width, 1 + border_width, FontColor_default, score_type_text);
	renderer->DrawText(border_width + 2 * column_width, 1 + border_width, FontColor_default, score_judge_text);
}

void UpdateBools() {
	// ��������ж�
	switch (score_type) {
	case 0:
		score_type_text = score_type_0;
		break;
	case 1:
		score_type_text = score_type_1;
		break;
	case 2:
		score_type_text = score_type_2;
		break;
	case 3:
		score_type_text = score_type_3;
		break;
	case 8:
		score_type_text = score_type_8;
		break;
	default:
		score_type_text = score_type_other;
		break;
	}
	// �����ж�
	switch (score_judge) {
	case 0:
		score_judge_text = score_judge_0;
		break;
	case 1:
		score_judge_text = score_judge_1;
		break;
	default:
		break;
	}
}
// only read from global flags and the render handle for graphic
void UpdateGraphics(HackBase *mHackBase) {
	UpdateBools();
	if (clear_screen && clear_screen_already_cleared) {
		return;
	}
	else if (clear_screen && !clear_screen_already_cleared) {
		mHackBase->setOnRender(onRender_clear);
		clear_screen_already_cleared = true;
	}
	else {
		if (clear_screen_already_cleared) {
			clear_screen_already_cleared = false;	// reset flag 
		}
		mHackBase->setOnRender(onRender_dashboard);
	}
}


/*samples */
/*
void onRender_F7(Renderer *renderer) {
	renderer->DrawText((int)(0.5 * renderer->GetWidth()), (int)(0.5 * renderer->GetHeight()), FontColor_default, F7_text);
}


*/

/*
void onRender(Renderer *renderer) {
// renderer->DrawBorder(0, 0, renderer->GetWidth(), renderer->GetHeight(), 5, GREEN(255));
// renderer->DrawLine(0, 0, renderer->GetWidth(), renderer->GetHeight(), 2, false, Color(255, 0, 255, 0));
// renderer->DrawText((int)(0.5 * renderer->GetWidth()), (int)(0.5 * renderer->GetHeight()), inject_text);
// renderer->DrawCircle((int)(0.5 * renderer->GetWidth()), (int)(0.5 * renderer->GetHeight()), 30, 2, 30, Color(255, 0, 255, 0));
}
*/
