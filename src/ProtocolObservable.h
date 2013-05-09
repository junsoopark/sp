#ifndef __PROTOCOLOBSERVABLE_H__
#define __PROTOCOLOBSERVABLE_H__


#include <list>
//#include "ProtocolObserver.h"
class ProtocolObserver;

using namespace std;

class ProtocolObservable{
private:
	list<ProtocolObserver>* m_oObservers;

public:
	virtual void AddProtocolObserver(ProtocolObserver* a_pObserver);
	virtual void RemoveProtocolOberver(ProtocolObserver* a_pObserver);
};

#endif //__PROTOCOLOBSERVABLE_H__
