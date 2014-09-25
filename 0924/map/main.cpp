#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif

#include <inttypes.h>
#include "map.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdexcept>

using namespace std;

int64_t getTime();

int main(int argc, const char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s Dict stopList", argv[0]);
        exit(EXIT_FAILURE);
    }

    TEST wf(argv[1], argv[2]);

    int64_t time1 = getTime();

    wf.readStopFile();
    wf.readFile();

    int64_t time2 = getTime();
    
    wf.copyWord();
    wf.sortFile();

    int64_t time3 = getTime();

    printf("读取文件: %"PRId64" ms \n", (time2 - time1) / 1000);
    printf("排序: %"PRId64" ms \n", (time3 - time2) / 1000);
    
    wf.printFile();

    return 0;
}


int64_t getTime()
{
    struct timeval tm;
    ::memset(&tm, 0, sizeof tm);
    if(::gettimeofday(&tm, NULL) == -1)
        throw runtime_error("gettimeofday");
    int64_t t = tm.tv_sec * 1000 * 1000;
    t += tm.tv_usec;
    return t;
}
