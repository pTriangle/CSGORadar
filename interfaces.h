#pragma once
#include <string>
#include "entitylist.h"
extern entitylist* m_entitylist;
class interfaces
{
public:
	static void getinterfaces();
	template<typename fn> static fn getinterface(std::string modulename, std::string interfacename);


};
