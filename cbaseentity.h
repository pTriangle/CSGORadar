#pragma once

class cbaseentity
{
public:
	bool* getspotted()
	{
		return (bool*)(this + 0x939);
	}
};
