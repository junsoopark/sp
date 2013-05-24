#include "Feeder.h"

bool Feeder::Feed(Buffer* a_pBuffer)
{
	SetChanged();
	NotifyObservers((long)a_pBuffer, 0);
}

