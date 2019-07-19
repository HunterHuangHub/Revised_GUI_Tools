#pragma once

#ifndef LOG_H    
#define LOG_H    
// log file path 
#define LOG_FILE_NAME "CLRlog.txt"  
// log toggle
#define LOG_ENABLE  

#include <fstream>    
#include <string>    
#include <ctime> 
#include <direct.h>

using namespace std;

class CLog
{
public:
	static string GetLogFilePath()
	{
		char szPath[MAX_PATH];
		GetModuleFileNameA(NULL, szPath, MAX_PATH);
		// _getcwd(szPath, MAX_PATH);  // for working directory instead of executable file path
		string::size_type pos = string(szPath).find_last_of("\\/");
		string s = string(szPath).substr(0, pos);
		s += "\\";
		s += LOG_FILE_NAME;
		return s;
	}
	// ���һ�����ݣ��������ַ���(ascii)����������������������ö��  
	// ��ʽΪ��[2011-11-11 11:11:11] aaaaaaa������  
	template <class T>
	static void WriteLog(T x)
	{
		ofstream fout(GetLogFilePath(), ios::app);
		fout.seekp(ios::end);
		fout << GetSystemTime() << x << endl;
		fout.close();
	}

	// ���2�����ݣ��ԵȺ����ӡ�һ������ǰ����һ�������������ַ�������������������ֵ  
	template<class T1, class T2>
	static void WriteLog2(T1 x1, T2 x2)
	{
		ofstream fout(GetLogFilePath(), ios::app);
		fout.seekp(ios::end);  // for ios::app
		fout << GetSystemTime() << x1 << " = " << x2 << endl;
		fout.close();
	}

	// ���һ�е�ǰ������ʼ�ı�־,�괫��__FUNCTION__  
	template <class T>
	static void WriteFuncBegin(T x)
	{
		ofstream fout(GetLogFilePath(), ios::out);
		// fout.seekp(ios::end);
		fout << GetSystemTime() << "--------------------" << x << "  Begin--------------------" << endl;
		fout.close();
	}

	// ���һ�е�ǰ���������ı�־���괫��__FUNCTION__  
	template <class T>
	static void WriteFuncEnd(T x)
	{
		ofstream fout(GetLogFilePath(), ios::app);
		fout.seekp(ios::end);
		fout << GetSystemTime() << "--------------------" << x << "  End  --------------------" << endl;
		fout.close();
	}


private:
	//��ȡ����ʱ�䣬��ʽ��"[2011-11-11 11:11:11] ";   
	static string GetSystemTime()
	{
		time_t tNowTime;
		time(&tNowTime);

		tm tLocalTime{};
		localtime_s(&tLocalTime, &tNowTime);
		char szTime[30] = { '\0' };
		strftime(szTime, 30, "[%Y-%m-%d %H:%M:%S] ", &tLocalTime);
		string strTime = szTime;
		return strTime;
	}

};

#ifdef LOG_ENABLE  

//��������Щ����ʹ�ñ��ļ�  
#define LOG(x)          CLog::WriteLog(x);						//�����ڿ������ַ���(ascii)����������������bool��  
#define LOG2(x1,x2)     CLog::WriteLog2(x1,x2);  
#define LOG_FUNC        LOG(__FUNCTION__)						//�����ǰ���ں�����  
#define LOG_LINE        LOG(__LINE__)							//�����ǰ�к�  
#define LOG_FUNC_BEGIN  CLog::WriteFuncBegin(__FUNCTION__);     //��ʽ�磺[ʱ��]"------------FuncName  Begin------------"  
#define LOG_FUNC_END    CLog::WriteFuncEnd(__FUNCTION__);		//��ʽ�磺[ʱ��]"------------FuncName  End------------"  

#else  

#define LOG(x)                
#define LOG2(x1,x2)       
#define LOG_FUNC          
#define LOG_LINE          
#define LOG_FUNC_BEGIN    
#define LOG_FUNC_END      

#endif  

#endif