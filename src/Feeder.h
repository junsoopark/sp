#ifndef __FEEDER_H__
#define __FEEDER_H__

#include "Observable.h"
#include <string>

class Buffer;

class Feeder : public Observable
{
public:
	std::string m_strName;
public:
	Feeder(char* a_pName);
	const char* GetName();
protected:
	bool Feed(Buffer* a_pBuffer);
};

#endif //__FEEDER_H__
