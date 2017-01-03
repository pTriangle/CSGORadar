#include "interfaces.h"
#include <iomanip>
#include <sstream>
#include <Windows.h>

entitylist* m_entitylist;
void interfaces::getinterfaces()
{
	m_entitylist = getinterface<entitylist*>("client.dll", "VClientEntityList");
}

typedef void* (*CreateInterfaceFn)(const char* name, int* returncode);
template<typename fn> fn interfaces::getinterface(std::string modulename, std::string interfacename)
{
	CreateInterfaceFn CreateInterface;
	CreateInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandle(modulename.c_str()), "CreateInterface");

	fn pInterface = 0;
	for (int i = 100; i > 0; i--)
	{
		std::stringstream intf;
		intf << interfacename << std::setfill('0') << std::setw(3) << i;
		pInterface = (fn)(CreateInterface(intf.str().c_str(), 0));
		if (pInterface) {
			break;
		}
	}

	return pInterface;
}