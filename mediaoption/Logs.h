#pragma once
#ifndef __myLog_H_
#define __myLog_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include <iostream>
#include <ratio>
#include <chrono>
#include <mutex>
#define OS_S 1
#define CLAMPXX(a, s, m) ((a) < (s)? (s) : ((a) > (m) ? (m) : (a)))

std::string GetName(const char* fileName);

std::string getCurrentSystemTime();

long long getCurrentMs();
// 
int LOGINIT();
// 
int LOGEnd();
// 
int LOGSetMaxSpace(int mSize);

int logWrite(char* s);

#define  LOGEM(...)  {\
                        char temp[8192] = {0};      \
						sprintf(temp, "%s", getCurrentSystemTime().c_str());  \
						sprintf(temp+strlen(temp), " %s %d ", GetName(__FILE__).c_str(), __LINE__);  \
                        sprintf(temp+strlen(temp), __VA_ARGS__); \
						sprintf(temp + strlen(temp), "\n");    \
                        printf("%s", temp);   \
						logWrite(temp); \
                    }
#endif