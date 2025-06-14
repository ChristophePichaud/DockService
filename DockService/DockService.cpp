// DockService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CServiceModule.h"

CServiceModule _Module;
CSWMRGuard g_Guard;
//CLogger g_Logger;
BasicLogger g_Logger;

int wmain(int argc, wchar_t *argv[])
{
	_Module.m_bService = TRUE;
	std::wstring mode;

	if (argc == 2)
	{
		mode = argv[1];
	}

	if (mode == _T("-console"))
	{
		std::wcout << _T("Running in console mode.") << std::endl;
		_Module.m_bService = FALSE;
		_Module.Start();
		return 0;
	}

	if (mode == _T("-createservice"))
	{
		std::wcout << _T("Creating the service...") << std::endl;

		CServiceModule sm;
		sm.Install();
		return 0;
	}

	::CreateDirectoryA("C:\\TEMP", NULL);

	_Module.m_bService = TRUE;
	_Module.Start();

	// When we get here, the service has been stopped
	return _Module.m_status.dwWin32ExitCode;
}

