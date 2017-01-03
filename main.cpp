#include <Windows.h>
#include "interfaces.h"

DWORD mainthread()
{
	interfaces::getinterfaces();
	while (1) {
		for (int i = 0; i < 32; i++)
		{
			cbaseentity* ent = m_entitylist->getcliententity(i);
			if (!ent) continue;
			if (*ent->getspotted() == 0)
				*ent->getspotted() = 1;
		}
		Sleep(500); //xd
	}
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE inst, DWORD reason, void* reserverd)
{
	if (reason == 1)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)mainthread, 0, 0, 0);
	}
	return 1;
}