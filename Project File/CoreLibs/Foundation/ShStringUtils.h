#pragma once
#include "ShPrerequisites.h"

SH_NAMESPACE_BEGIN

class ShStringUtils
{
public: static void MakeString(_Out_ String& outResult, _In_ const char* format, ...);
public: static void GetFileNameWithoutPath(_Inout_ String& fullPath);
};

SH_NAMESPACE_END