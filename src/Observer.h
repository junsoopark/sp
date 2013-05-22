#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Observable;

class Observer
{
protected:
	Observable* m_pObservable;
	
public:
	Observer(Observable* a_pObservable);
	Observer();
	
	void Update(Observable* a_pObservable, void* a_pParam1, void* a_pParem2) = 0;
};

#endif //__OBSERVABLE_H__
