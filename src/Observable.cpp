#include "Observable.h"
#include "Observer.h"


Observable::Observable()
{
	m_Changed = FALSE;
}
Observable::~Observable()
{
	
}

void Observable::SetChanged()
{
	m_Changed = TRUE;
}

void Observable::AddObserver(Observer* a_pObserver)
{
	m_oObservers.insert(a_pObserver);
}
void Observable::RemoveOberver(Observer* a_pObserver)
{
	m_oObservers.remove(a_pObserver);
}

bool Observable::NotifyObservers(void* a_pParam1, void* a_pParem2)
{
	if (m_Changed){
		for (list<ProtocolObserver*>::iterator it = m_oObservers.begin(); it != m_oObservers.end(); ++it)
			it.Update(this, a_pParam1, a_pParem2);
	}
	m_Changed = FALSE;
}

