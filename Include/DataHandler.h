#pragma once
#include "MySharedStuff.h"

class MYSHAREDSTUFF_API CNetworkCard
{
public:
	int m_Index;
	CString m_Name;
	CString m_AdapterType;
	CString m_MACAddress;
	CString m_Speed;
	int m_NetConnectionStatus;
	bool m_NetEnabled;
	bool m_PhysicalAdapter;
};

class MYSHAREDSTUFF_API DataHandler
{
public:
	DataHandler();
	~DataHandler();

public:
	std::vector<std::shared_ptr<CNetworkCard>> m_NetworkCards;
	CString m_IPV4;
	CString m_IPV6;
};

