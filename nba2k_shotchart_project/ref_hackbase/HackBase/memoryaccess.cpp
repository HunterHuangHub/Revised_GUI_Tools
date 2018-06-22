#include "trainerbase.h"

/*
���ļ���������ѭ����ȡ�ڴ��Ը�����ʾֵ
*/

// address table. might not be universal.
// will test after all wrapedup.


// 0. the followings are for all courts. 
DWORD exe_base_addr				= 0x00400000;	// nba2k11.exe��ַ����֪���᲻��仯������ĵ�ַ���ǻ�ַ+ƫ������ĵ�ַ��
// e.g. single practice, blacktop street, shooting practice, etc. 
DWORD score_type_addr			= 0x05D5FA70;	// ���������ϵ��0����մ1�ҿ�2��ˢ3��� 5��ſ�ˢ/ƫ���� 7����ҿ��/�Ұ�����8�������������Բ����
DWORD score_judge_addr			= 0x05D5FA78;	// �����ж�
DWORD coordinate_x_100_addr		= 0x05d5f720;	// �ٱ�������
DWORD coordinate_y_100_addr		= 0x05d5f728;	// �ٱ�������
DWORD absolute_dist_rim_addr	= 0x05d5f730;	// ����������Ծ���
DWORD projected_percent_addr	= 0x05d5f738;	// Ԥ��Ͷ�������ʣ��ɲο�������Ͷ��ѡ��
DWORD shot_triggered_time_addr	= 0x05db028c;	// Ͷ���ͷ�ʱ�䣬������zͶ�������̧���ʱ�䣬�������ж��Ƿ����������
DWORD total_time_elapsed_addr	= 0x05439C1C;	// ������ʱ�䣬������ͣ���ݵȣ�������esc��Ϸ��ͣ

// 1. the followings are for quartered games, e.g.
// dynasty, quick game, mplayer, jordan, etc.
DWORD game_time_elapsed_addr	= 0x05544DF4;	// ��������ʱ�䣬�������ڷֽڱ�����ģʽ������





void update_score_type(HANDLE pHandle) {
	ReadProcessMemory(pHandle, (LPVOID)score_type_addr, &score_type, sizeof(score_type), 0);
	ReadProcessMemory(pHandle, (LPVOID)score_judge_addr, &score_judge, sizeof(score_judge), 0);
}


// only read from global flags and the handle for address
void UpdateDMAs(HANDLE pHandle) {
	// aka direct memory access. manipulate the memory region.
	update_score_type(pHandle);
}