#include "Feeder.h"


Feeder::Feeder(char* a_pName)
{
	m_strName = a_pName;
}

bool Feeder::Feed(Buffer* a_pBuffer)
{
	SetChanged();
	NotifyObservers((long)a_pBuffer, 0);
}

const char* Feeder::GetName()
{
	return m_strName.data();
}
