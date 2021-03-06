#ifndef __OBSERVABLE_H__
#define __OBSERVABLE_H__

#include <list>
class Observer;

class Observable
{
protected:
	bool m_Changed;
	std::list<Observer*> m_oObservers;
	
public:
	Observable();
	virtual ~Observable();
	
	void SetChanged();
	void AddObserver(Observer* a_pObserver);
	void RemoveOberver(Observer* a_pObserver);
	bool NotifyObservers(long a_pParam1, long a_pParem2);	
};

#endif //__OBSERVABLE_H__
