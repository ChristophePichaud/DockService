// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <tchar.h>

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <random>
#include <memory>
#include <map>

#include <atlstr.h>
#include <atlbase.h>
#include <atlcom.h>
#include <atlcomcli.h>
#include <atlsync.h>

//#include <Windows.h>
#include <winsvc.h>

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")

#include <Wbemidl.h>
#pragma comment(lib, "wbemuuid.lib")

#include "CSWMRGuard.h"
extern CSWMRGuard g_Guard;

#include "Logger.h"
#include "BasicLogger.h"
//extern CLogger g_Logger;
extern BasicLogger g_Logger;

// TODO: reference additional headers your program requires here

#ifdef _WIN64
	#ifdef _DEBUG
		#pragma comment (lib, "..\\Lib\\MySharedStuffD64.lib")
	#else
		#pragma comment (lib, "..\\Lib\\MySharedStuff64.lib")
	#endif
#else
	#ifdef _DEBUG
	#else
	#endif
#endif
