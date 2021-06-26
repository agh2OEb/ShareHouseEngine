#pragma once
#include "ShPrerequisites.h"
#include "ShLog.h"
#include "ShString.h"

SH_NAMESPACE_BEGIN

class LogOutputDevice;

struct Message
{
	template <typename FmtType, typename... Types>
	static void Log(const String& category, const String& funcName, const size_t line, EAlarm alarm, const FmtType& fmt, Types... args)
	{
		static auto Logger = LogOutputDevice::GetLogger();
		if (Logger.IsValid())
		{
			Logger.GetSerializer()->Serialize(category, funcName, line, Print(fmt, args...), alarm);
		}
	}

private:
	
	static inline int32 GetVarArgs(char* dest, size_t destSize, const char*& fmt, va_list argPtr);
	static String Print(const char* fmt, ...);
};

SH_NAMESPACE_END