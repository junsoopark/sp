#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Observable;

class Observer
{
protected:
	Observable* m_pObservable;
	
public:
	Observer();
	Observer(Observable* a_pObservable);
	virtual ~Observer();
	
	virtual void Update(Observable* a_pObservable, long a_pParam1, long a_pParem2) = 0;
};

#endif //__OBSERVABLE_H__
