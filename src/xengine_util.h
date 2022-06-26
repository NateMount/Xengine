#ifndef __XENGINE_UTIL
#define __XENGINE_UTIL

#ifdef DEBUG

#include <stdio.h>

FILE* log;

#define DEBUG(x) printf("%s\n", x);

#define LOG(x) { log = fopen("XengineRuntime.log", "w+"); fprintf(log, "[%s](%d)::%s: %s\n", __FILE__, __LINE__, __TIME__, x); fclose(log); }

#endif

#endif
