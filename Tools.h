#ifndef _TOOLS_H_
#define _TOOLS_H_

#include "cocos2d.h"
#pragma comment(lib,"libiconv.lib")
int GBKToUTF8(std::string &gbkStr,const char *toCode,const char *fromCode);

#endif