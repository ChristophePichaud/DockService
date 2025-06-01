#pragma once
#include "MySharedStuff.h"
#include "DataHandler.h"

class MYSHAREDSTUFF_API WorkerItemHandler
{
public:
	WorkerItemHandler();
	~WorkerItemHandler();

	bool GetNetworkAdapterInformation();

public:
	DataHandler m_data;
};

