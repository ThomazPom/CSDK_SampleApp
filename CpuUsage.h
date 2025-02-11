// Ref: http://www.philosophicalgeek.com/2009/01/03/determine-cpu-usage-of-current-process-c-and-c/

#pragma once
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

class CpuUsage
{
public:
	CpuUsage(void);
	
	short  GetUsage();
private:
	ULONGLONG SubtractTimes(const FILETIME& ftA, const FILETIME& ftB);
	bool EnoughTimePassed();
	inline bool IsFirstRun() const { return (m_dwLastRun == 0); }
	
	//system total times
	FILETIME m_ftPrevSysKernel;
	FILETIME m_ftPrevSysUser;

	//process times
	FILETIME m_ftPrevProcKernel;
	FILETIME m_ftPrevProcUser;

	short m_nCpuUsage;
	ULONGLONG m_dwLastRun;
	
	volatile LONG m_lRunCount;
};
