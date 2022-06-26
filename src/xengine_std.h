#ifndef __xengine_std
#define __xengine_std

#include <string.h>

#include "xengine_util.h"
#include "xengine_applib.h"

updateObj xengine_std_keyboardEvent(int ch, unsigned char mode);

char* xengine_std_passthroughUpdate( updateObj obj, char* buff );

char* xengine_std_helloXengineUpdate( updateObj obj, char* buff );

#endif
