#pragma once
#include "MySharedStuff.h"

class WorkerItemHandler
{
public:
	WorkerItemHandler();
	~WorkerItemHandler();

	bool GetNetworkAdapterInformation();

public:
	DataHandler m_data;
};

