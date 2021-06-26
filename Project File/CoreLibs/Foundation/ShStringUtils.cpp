#pragma once
#include "ShStringUtils.h"

SH_NAMESPACE_BEGIN

#define STRING_DEFAULT_LENGTH   512
void ShStringUtils::MakeString(String& outResult, const char* format, ...)
{
	va_list ap;
	char buf[STRING_DEFAULT_LENGTH];
	std::memset(buf, 0, sizeof(char) * STRING_DEFAULT_LENGTH);

	va_start(ap, format);
	vsprintf(buf, format, ap);
	va_end(ap);

	outResult = buf;
}

void ShStringUtils::GetFileNameWithoutPath(String& fullPath)
{
	char* ptr = nullptr;
	char filename[STRING_DEFAULT_LENGTH];
	std::memset(filename, 0, sizeof(char) * STRING_DEFAULT_LENGTH);

	ptr = strrchr(fullPath.c_str(), '\\');
	if (ptr == nullptr)
		strcpy(filename, fullPath.c_str());
	else
		strcpy(filename, ptr + 1);

	fullPath = filename;
}

SH_NAMESPACE_END