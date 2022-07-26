//
////
////#pragma comment(lib, "wbemuuid.lib")
////
////int main(int argc, char** argv)
////{
////    HRESULT hres;
////
////    // Step 1: --------------------------------------------------
////    // Initialize COM. ------------------------------------------
////
////    hres = CoInitializeEx(0, COINIT_MULTITHREADED);
////    if (FAILED(hres))
////    {
////        cout << "Failed to initialize COM library. Error code = 0x"
////            << hex << hres << endl;
////        return 1;                  // Program has failed.
////    }
////
////    // Step 2: --------------------------------------------------
////    // Set general COM security levels --------------------------
////
////    hres = CoInitializeSecurity(
////        NULL,
////        -1,                          // COM authentication
////        NULL,                        // Authentication services
////        NULL,                        // Reserved
////        RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication 
////        RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation  
////        NULL,                        // Authentication info
////        EOAC_NONE,                   // Additional capabilities 
////        NULL                         // Reserved
////    );
////
////
////    if (FAILED(hres))
////    {
////        cout << "Failed to initialize security. Error code = 0x"
////            << hex << hres << endl;
////        CoUninitialize();
////        return 1;                    // Program has failed.
////    }
////
////    // Step 3: ---------------------------------------------------
////    // Obtain the initial locator to WMI -------------------------
////
////    IWbemLocator* pLoc = NULL;
////
////    hres = CoCreateInstance(
////        CLSID_WbemLocator,
////        0,
////        CLSCTX_INPROC_SERVER,
////        IID_IWbemLocator, (LPVOID*)&pLoc);
////
////    if (FAILED(hres))
////    {
////        cout << "Failed to create IWbemLocator object."
////            << " Err code = 0x"
////            << hex << hres << endl;
////        CoUninitialize();
////        return 1;                 // Program has failed.
////    }
////
////    // Step 4: -----------------------------------------------------
////    // Connect to WMI through the IWbemLocator::ConnectServer method
////
////    IWbemServices* pSvc = NULL;
////
////    // Connect to the root\cimv2 namespace with
////    // the current user and obtain pointer pSvc
////    // to make IWbemServices calls.
////    hres = pLoc->ConnectServer(
////        _bstr_t(L"ROOT\\CIMV2"), // Object path of WMI namespace
////        NULL,                    // User name. NULL = current user
////        NULL,                    // User password. NULL = current
////        0,                       // Locale. NULL indicates current
////        NULL,                    // Security flags.
////        0,                       // Authority (for example, Kerberos)
////        0,                       // Context object 
////        &pSvc                    // pointer to IWbemServices proxy
////    );
////
////    if (FAILED(hres))
////    {
////        cout << "Could not connect. Error code = 0x"
////            << hex << hres << endl;
////        pLoc->Release();
////        CoUninitialize();
////        return 1;                // Program has failed.
////    }
////
////    cout << "Connected to ROOT\\CIMV2 WMI namespace" << endl;
////
////
////    // Step 5: --------------------------------------------------
////    // Set security levels on the proxy -------------------------
////
////    hres = CoSetProxyBlanket(
////        pSvc,                        // Indicates the proxy to set
////        RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
////        RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
////        NULL,                        // Server principal name 
////        RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx 
////        RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
////        NULL,                        // client identity
////        EOAC_NONE                    // proxy capabilities 
////    );
////
////    if (FAILED(hres))
////    {
////        cout << "Could not set proxy blanket. Error code = 0x"
////            << hex << hres << endl;
////        pSvc->Release();
////        pLoc->Release();
////        CoUninitialize();
////        return 1;               // Program has failed.
////    }
////
////    // Step 6: --------------------------------------------------
////    // Use the IWbemServices pointer to make requests of WMI ----
////
////    // For example, get the name of the operating system
////    IEnumWbemClassObject* pEnumerator = NULL;
////    hres = pSvc->ExecQuery(
////        bstr_t("WQL"),
////        bstr_t("SELECT * FROM Win32_OperatingSystem"),
////        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
////        NULL,
////        &pEnumerator);
////
////    if (FAILED(hres))
////    {
////        cout << "Query for operating system name failed."
////            << " Error code = 0x"
////            << hex << hres << endl;
////        pSvc->Release();
////        pLoc->Release();
////        CoUninitialize();
////        return 1;               // Program has failed.
////    }
////
////    // Step 7: -------------------------------------------------
////    // Get the data from the query in step 6 -------------------
////
////    IWbemClassObject* pclsObj = NULL;
////    ULONG uReturn = 0;
////
////    while (pEnumerator)
////    {
////        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
////            &pclsObj, &uReturn);
////
////        if (0 == uReturn)
////        {
////            break;
////        }
////
////        VARIANT vtProp;
////
////        VariantInit(&vtProp);
////        // Get the value of the Name property
////        hr = pclsObj->Get(L"Name", 0, &vtProp, 0, 0);
////        wcout << " OS Name : " << vtProp.bstrVal << endl;
////        VariantClear(&vtProp);
////
////        pclsObj->Release();
////    }
////
////    // Cleanup
////    // ========
////
////    pSvc->Release();
////    pLoc->Release();
////    pEnumerator->Release();
////    CoUninitialize();
////
////    return 0;   // Program successfully completed.
////
////}
//#define _WIN32_DCOM
//#include <iostream>
//using namespace std;
//#include <comdef.h>
//#include<string>
//#include <tlhelp32.h>
//
//
//
//string GetProcessInfo(HANDLE hProcess, char* processName)
//{
//	PROCESSENTRY32* pinfo = new PROCESSENTRY32; //进程信息 （pinfo->dwSize = sizeof(PROCESSENTRY32);）
//	MODULEENTRY32* minfo = new MODULEENTRY32; //模块信息 （minfo->dwSize = sizeof(MODULEENTRY32);）
//	char shortpath[MAX_PATH];				//保存路径变量
//
//	int flag = Process32First(hProcess, pinfo);	// 从第一个进程开始
//	while (flag) {
//
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
//
//			return shortpath;
//		}
//
//		// 下一个进程
//		flag = Process32Next(hProcess, pinfo);
//	}
//
//	return NULL;
//}
//
//int main()
//{
//	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // 创建进程快照
//	PROCESSENTRY32 process = { sizeof(PROCESSENTRY32) };	// 用来接收 hProcessSnap 的信息
//
//	// 遍历进程快照
//	while (Process32Next(hProcessSnap, &process)) {
//		// 找到 QQMusic.exe 进程
//		string processName = process.szExeFile; // char* 转 string
//		if (processName == "WechatBrowser.exe") {
//			char p[] = "WechatBrowser.exe";
//			string s_exePath = GetProcessInfo(hProcessSnap,p); // 进程的全路径 
//			cout << s_exePath << endl;
//			break;
//		}
//	}
//
//	return 0;
//}
