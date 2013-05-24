#ifndef __FEEDER_H__
#define __FEEDER_H__

#include "Observable.h"

class Buffer;

class Feeder : public Observable
{
protected:
	bool Feed(Buffer* a_pBuffer);
};

#endif //__FEEDER_H__
