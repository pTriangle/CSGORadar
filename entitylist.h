#pragma once
#include "cbaseentity.h"
#include "vmt.h"

class entitylist
{
public:
	cbaseentity* getcliententity(int index)
	{
		return vmt::getvfunc<cbaseentity*(__thiscall*)(void*, int)>(this, 3)(this, index);
	}
};