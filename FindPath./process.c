#include <windows.h>
#include <tlhelp32.h>	//进程快照函数头文件
#include <stdio.h>
#include<direct.h>
#include<string.h>
#include <xkeycheck.h>


//int getPath()
//{
//	char szPath[512] = { 0 };
//	GetModuleFileName(NULL, szPath, sizeof(szPath) - 1);
//	printf("path:%s\n", szPath);
//	return 0;
//}
//int getLibraryPath()
//{
//
//	char szPath[512] = { 0 };
//	HMODULE hMod = GetModuleHandle(_T("demo.dll"));
//	GetModuleFileName(hMod, szPath, sizeof(szPath) - 1);
//	printf("path:%s\n", szPath);
//	return 0;
//}
//char* GetProcessInfo(HANDLE hProcess, char* processName)
//{
//	PROCESSENTRY32* pinfo = malloc(sizeof(PROCESSENTRY32)); //进程信息 （pinfo->dwSize = sizeof(PROCESSENTRY32);）
//	MODULEENTRY32* minfo = malloc(sizeof(MODULEENTRY32)); //模块信息 （minfo->dwSize = sizeof(MODULEENTRY32);）
//	char shortpath[MAX_PATH];				//保存路径变量
//
//	int flag = Process32First(hProcess, pinfo);	// 从第一个进程开始
//	while (flag) {
//		// 如果是 QQMusic.exe 这个进程
//		if (strcmp(pinfo->szExeFile, processName) == 0) {
//
//			// 创建进程快照
//			HANDLE hModule = CreateToolhelp32Snapshot(
//				TH32CS_SNAPMODULE,		//（DWORD） 快照返回的对象，TH32CS_SNAPMODULE 是指 "特定进程的使用模块的列表"
//				pinfo->th32ProcessID	//（DWORD） 要获取快照进程的PID，当前进程/系统列表 快照时设为0
//			);
//
//			// 把第一个模块信息给 minfo
//			Module32First(
//				hModule,  //（HANDLE） CreateToolhelp32Snapshot 的返回句柄
//				minfo	 // （LPMODULEENTRY32）  接收模块信息
//			);
//
//			// 把文件路径给 shortpath
//			GetShortPathName(
//				minfo->szExePath,	//  文件路径（但最好不要用这个，因为这个碰到中文会出现乱码）
//				shortpath,		// 用来接收 minfo->szExePath 兼容中文的值
//				256			// 缓冲区大小
//			);
//			return shortpath;
//		}
//		// 下一个进程
//		flag = Process32Next(hProcess, pinfo);
//	}
//	return NULL;
//}



int main()
{
	int countProcess = 0;									//当前进程数量计数变量
	PROCESSENTRY32 currentProcess;						//存放快照进程信息的一个结构体
	PROCESSENTRY32* info = &currentProcess;
	info->dwSize = sizeof(currentProcess);		//在使用这个结构之前，先设置它的大小
	HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);	//创建进程快照

	if (hProcess == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot()调用失败!\n");
		return -1;
	}
	BOOL bMore = Process32First(hProcess, info);	//获取第一个进程信息
	while (bMore)
	{
		int processID = info->th32ProcessID;
		PROCESSENTRY32* pinfo = malloc(sizeof(PROCESSENTRY32)); //进程信息 （pinfo->dwSize = sizeof(PROCESSENTRY32);）
		MODULEENTRY32* minfo = malloc(sizeof(MODULEENTRY32)); //模块信息 （minfo->dwSize = sizeof(MODULEENTRY32);）
		char shortpath[MAX_PATH];				//保存路径变量
		int flag = Process32First(hProcess, pinfo);	// 从第一个进程开始
		while (flag) {
			if (pinfo->th32ProcessID == processID) {

				// 创建进程快照
				HANDLE hModule = CreateToolhelp32Snapshot(
					TH32CS_SNAPMODULE,		//（DWORD） 快照返回的对象，TH32CS_SNAPMODULE 是指 "特定进程的使用模块的列表"
					pinfo->th32ProcessID	//（DWORD） 要获取快照进程的PID，当前进程/系统列表 快照时设为0
				);

				// 把第一个模块信息给 minfo
				Module32First(
					hModule,  //（HANDLE） CreateToolhelp32Snapshot 的返回句柄
					minfo	 // （LPMODULEENTRY32）  接收模块信息
				);

				//把文件路径给 shortpath
				GetShortPathName(
					minfo->szExePath,	//  文件路径（但最好不要用这个，因为这个碰到中文会出现乱码）
					shortpath,		// 用来接收 minfo->szExePath 兼容中文的值
					256			// 缓冲区大小
				);
				printf("PID=%5u    PName= %s\n", info->th32ProcessID, info->szExeFile);	//遍历进程快照，轮流显示每个进程信息
				printf("ExecutablePath = %s\n", shortpath);
				break;
			}
			flag = Process32Next(hProcess, pinfo);
			
		}
		
		bMore = Process32Next(hProcess, info);	//遍历下一个
		countProcess++;
	}

	CloseHandle(hProcess);	//清除hProcess句柄
	printf("共有以上%d个进程在运行\n", countProcess);
	system("pause");
	return 0;

}
