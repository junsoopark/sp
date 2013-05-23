#include "Feeder.h"

bool Feeder::Feed(Buffer* a_pBuffer)
{
	SetChanged();
	NotifyObservers((void*)a_pBuffer, NULL);
}

