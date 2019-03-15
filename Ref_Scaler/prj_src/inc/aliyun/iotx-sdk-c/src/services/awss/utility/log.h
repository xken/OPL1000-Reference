/*
 * Copyright (c) 2014-2016 Alibaba Group. All rights reserved.
 *
 * Alibaba Group retains all right, title and interest (including all
 * intellectual property rights) in and to this computer program, which is
 * protected by applicable intellectual property laws.  Unless you have
 * obtained a separate written license from Alibaba Group., you are not
 * authorized to utilize all or a part of this computer program for any
 * purpose (including reproduction, distribution, modification, and
 * compilation into object code), and you must immediately destroy or
 * return to Alibaba Group all copies of this computer program.  If you
 * are licensed by Alibaba Group, your rights to utilize this computer
 * program are limited by the terms of that license.  To obtain a license,
 * please contact Alibaba Group.
 *
 * This computer program contains trade secrets owned by Alibaba Group.
 * and, unless unauthorized by Alibaba Group in writing, you agree to
 * maintain the confidentiality of this computer program and related
 * information and to not disclose this computer program and related
 * information to any other person or entity.
 *
 * THIS COMPUTER PROGRAM IS PROVIDED AS IS WITHOUT ANY WARRANTIES, AND
 * Alibaba Group EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED,
 * INCLUDING THE WARRANTIES OF MERCHANTIBILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE, AND NONINFRINGEMENT.
 */

#ifndef LOG_H
#define LOG_H
#include <stdio.h>
#include "os.h"
#include "iotx_log.h"
extern unsigned int log_level;
static inline unsigned int log_get_level(void)
{
    return log_level;
}

static inline void log_set_level(int level)
{
    log_level = level;
}

enum LOGLEVEL_BIT {
    LL_NONE_BIT = -1,
    LL_FATAL_BIT,
    LL_ERROR_BIT,
    LL_WARN_BIT,
    LL_INFO_BIT,
    LL_DEBUG_BIT,
    LL_TRACE_BIT,
    LL_MAX_BIT
};

#define LOG_LEVEL  log_get_level()

#define LL_NONE  0
#define LL_ALL  0XFF
#define LL_FATAL (1 << LL_FATAL_BIT)
#define LL_ERROR (1 << LL_ERROR_BIT)
#define LL_WARN  (1 << LL_WARN_BIT)
#define LL_INFO  (1 << LL_INFO_BIT)
#define LL_DEBUG (1 << LL_DEBUG_BIT)
#define LL_TRACE (1 << LL_TRACE_BIT)


/*
 * color def.
 * see http://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix
 */
#define COL_DEF "\x1B[0m"   //white
#define COL_RED "\x1B[31m"  //red
#define COL_GRE "\x1B[32m"  //green
#define COL_BLU "\x1B[34m"  //blue
#define COL_YEL "\x1B[33m"  //yellow
#define COL_WHE "\x1B[37m"  //white
#define COL_CYN "\x1B[36m"


#define log_print(CON, MOD, COLOR, LVL, FMT, ...) \
do {\
    if (CON) {\
        os_printf(COLOR"<%s> [%s#%d] : ",\
			LVL, __FUNCTION__, __LINE__);\
        os_printf(FMT COL_DEF"\r\n", ##__VA_ARGS__);\
    }\
}while(0)

#undef log_fatal
#undef log_error
#undef log_warn
#undef log_info
#undef log_debug
#undef log_trace

#define log_fatal(FMT, ...) \
    log_print(LOG_LEVEL & LL_FATAL, "iLop", COL_RED, "FATAL", FMT, ##__VA_ARGS__)
#define log_error(FMT, ...) \
    log_print(LOG_LEVEL & LL_ERROR, "iLop", COL_YEL, "ERROR", FMT, ##__VA_ARGS__)
#define log_warn(FMT, ...) \
    log_print(LOG_LEVEL & LL_WARN, "iLop", COL_BLU, "WARN", FMT, ##__VA_ARGS__)
#define log_info(FMT, ...) \
    log_print(LOG_LEVEL & LL_INFO, "iLop", COL_GRE, "INFO", FMT, ##__VA_ARGS__)
#define log_debug(FMT, ...) \
    log_print(LOG_LEVEL & LL_DEBUG, "iLop", COL_WHE, "DEBUG", FMT, ##__VA_ARGS__)
#define log_trace(FMT, ...) \
    log_print(LOG_LEVEL & LL_TRACE, "iLop", COL_CYN, "TRACE", FMT, ##__VA_ARGS__)

#endif
