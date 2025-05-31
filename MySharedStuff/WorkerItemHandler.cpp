#include "stdafx.h"
#include "DataHandler.h"
#include "WorkerItemHandler.h"
#include "ManagementClass.h"

WorkerItemHandler::WorkerItemHandler()
{
}


WorkerItemHandler::~WorkerItemHandler()
{
}

bool WorkerItemHandler::GetNetworkAdapterInformation()
{
	ManagementClass mc(_TEXT("Win32_NetworkAdapter"));
	bool result = mc.GetInstances();
	while (mc.MoveNext())
	{
		CNetworkCard card;
		card.m_Index = mc.GetIntProperty(_TEXT("Index"));
		card.m_Name = mc.GetStringProperty(_TEXT("Name"));
		card.m_AdapterType = mc.GetStringProperty(_TEXT("AdapterType"));
		card.m_MACAddress = mc.GetStringProperty(_TEXT("MACAddress"));
		card.m_Speed = mc.GetStringProperty(_TEXT("Speed"));
		card.m_NetConnectionStatus = mc.GetIntProperty(_TEXT("NetConnectionStatus"));
		card.m_NetEnabled = mc.GetBoolProperty(_TEXT("NetEnabled"));
		card.m_PhysicalAdapter = mc.GetBoolProperty(_TEXT("PhysicalAdapter"));
		m_data.m_NetworkCards.Add(card);
	}

	ManagementClass mc2(_TEXT("Win32_NetworkAdapterConfiguration"));
	result = mc2.GetInstances();
	while (mc2.MoveNext())
	{
		COleSafeArray sa;
		if (mc2.GetSafeArrayProperty(_TEXT("IPAddress"), sa) == false)
		{
			continue;
		}
		else
		{
			//DWORD dwDim = sa.GetDim();
			//LONG lBound = 0;
			//sa.GetLBound(1, &lBound);
			//LONG uBound = 0;
			//sa.GetUBound(1, &uBound);
			//long index[1];
			//index[0] = lBound;
			//COleVariant vData;
			//sa.GetElement(index, (void *)&vData);
			m_data.m_IPV4 = (((wchar_t* *)(*(((tagVARIANT*)(&(sa)))->parray)).pvData))[0];
			m_data.m_IPV6 = (((wchar_t* *)(*(((tagVARIANT*)(&(sa)))->parray)).pvData))[1];
		}
	}

	return true;
}

