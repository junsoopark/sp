#include "Observer.h"
#include "Observable.h"

Observer::Observer(Observable* a_pObservable)
{
		m_pObservable = a_pObservable;
}

Observer::~Observer()
{
}

