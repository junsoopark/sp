#ifndef __BUS_H__
#define __BUS_H__


class Bus : public Observable
{
public:
	void PostMessage(Message* a_pMessage);
};

#endif //__BUS_H__
