#include "Observer.h"
#include "Observable.h"

Observer::Observer()
{
	m_pObservable = 0;
}

Observer::Observer(Observable* a_pObservable)
{
		m_pObservable = a_pObservable;
}

Observer::~Observer()
{
}

