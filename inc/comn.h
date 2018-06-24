#pragma once

#include <sys/types.h>

#include <event2/event-config.h>

#include <sys/stat.h>

#ifndef _WIN32
#include <sys/queue.h>
#include <unistd.h>
#endif

#include <time.h>
#ifdef EVENT__HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/util.h>

#ifdef _WIN32
#include <winsock2.h>
#endif
