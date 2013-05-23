#ifndef __FEEDER_H__
#define __FEEDER_H__


class Feeder : public Observable
{
private:
	bool Feed(Buffer* a_pBuffer);
};

#endif //__FEEDER_H__
