#include "Observable.h"
#include "Observer.h"


Observable::Observable()
{
	m_Changed = false;
}
Observable::~Observable()
{
	
}

void Observable::SetChanged()
{
	m_Changed = true;
}

void Observable::AddObserver(Observer* a_pObserver)
{
	m_oObservers.push_back(a_pObserver);
}
void Observable::RemoveOberver(Observer* a_pObserver)
{
	m_oObservers.remove(a_pObserver);
}

bool Observable::NotifyObservers(void* a_pParam1, void* a_pParem2)
{
	if (m_Changed){
		for (std::list<Observer*>::iterator it = m_oObservers.begin(); it != m_oObservers.end(); ++it)
			(*it)->Update(this, a_pParam1, a_pParem2);
	}
	m_Changed = false;
}

