#pragma once

class vmt
{
public:
	template<typename T> static T getvfunc(void *base, unsigned int index)
	{
		DWORD** tablepointer = (DWORD**)base;
		DWORD* tablebase = *tablepointer;
		DWORD addr = tablebase[index];
		return (T)(addr);
	}
};
