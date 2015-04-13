// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <assert.h>

#if defined( _DEBUG )
extern bool CustomAssertFunction(bool, char*, int, char*, bool*);

#define Assert( exp, description ) \
{  static bool ignoreAlways = false; \
if (!ignoreAlways) {\
if (CustomAssertFunction((int)(exp), description, \
	__LINE__, __FILE__, &ignoreAlways)) ) \
{ _asm { int 3 } } \
} \
}

#else
#define Assert( exp, description )
#endif

bool CustomAssertFunction(bool, char*, int, char*, bool*)
{

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

