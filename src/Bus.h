#ifndef __BUS_H__
#define __BUS_H__

#include "Observable.h"
#include "Message.h"

class Bus : public Observable
{
public:
	bool PostMessage(Message* a_pMessage);
};

#endif //__BUS_H__
