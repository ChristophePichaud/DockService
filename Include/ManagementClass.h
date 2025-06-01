#pragma once
#include "MySharedStuff.h"

class MYSHAREDSTUFF_API ManagementClass
{
public:
	ManagementClass(const CString& adr);
	~ManagementClass();

	bool GetInstances();
	bool CallMethodOnNetworkInterface(const CString& methodName, int index);
	bool MoveNext();
	CString GetStringProperty(CString propName);
	bool GetBoolProperty(CString propName);
	int GetIntProperty(CString propName);
	long GetLongProperty(CString propName);
	bool GetSafeArrayProperty(CString propName, CComVariant& saReturned);

protected:
	CString m_wmiAdr;
	IWbemLocator *m_pLoc;
	CComPtr<IWbemServices> m_pSvc;
	CComPtr<IEnumWbemClassObject> m_pEnumerator;
	CComPtr<IWbemClassObject> m_pclsObj;
};

void MYSHAREDSTUFF_API AfxBSTR2CString(CString* pStr, _In_ BSTR bstr);
