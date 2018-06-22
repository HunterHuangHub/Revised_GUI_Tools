#ifndef __TRAINERBASE_H__
#define __TRAINERBASE_H__

/*
The original hackbase was not specifically designed for toggle menus or other things
like drawing on the screen. (actually it's just a demo of dxhook, but I started my project on it!)
therefore I just implement a rather verbose/inefficient snippet to achieve our drawing needs.
OMG WTH for several time i just wanted to refactor the whole piece of s**t! so convoluted!
*/
#include "hackbase.h"

// F7 was dedicated to be toggle of god mode.
extern char* F7_text;
extern char F7_text_f[];
extern char F7_text_t[];
extern bool all_players_god_mode;

// to decide the genre of ball into the rim.
extern int score_type;
extern int score_judge;
extern char* score_type_text;
extern char* score_judge_text;
extern char score_type_0[];
extern char score_type_1[];
extern char score_type_2[];
extern char score_type_3[];
extern char score_type_8[];
extern char score_type_other[];
extern char score_judge_0[];
extern char score_judge_1[];

// time related
extern char total_time_elapsed[];
extern char game_time_elapsed[];
extern char shot_triggered_time[];

// general flags for toggling.
extern bool record_shot_chart_and_more;
extern bool clear_screen;
extern bool clear_screen_already_cleared;

void onRender_clear(Renderer *renderer); 

void onRender_dashboard(Renderer *renderer);

// void onRender_F7(Renderer *renderer) {};

// ��д�ж�ֵ����д��ʾ�ַ�����ʵ�ֿ���ģʽ
bool IsKeyDown(DWORD key);
void UpdateHotkeys();
// ��ȡ�ж�ֵ����д�ڴ����ݣ�ʵ�ֶ�ȡͶ������/д���޵�ģʽ
void update_score_type(HANDLE pHandle);
void change_god_mode(HANDLE pHandle);
void UpdateDMAs(HANDLE pHandle);
void UpdateDMA_afterKeyDown(HANDLE pHandle_r, HANDLE pHandle_w);
// ��ȡ�ж�ֵ��������Ļ
void UpdateBools();
void UpdateGraphics(HackBase *mHackBase);

#endif