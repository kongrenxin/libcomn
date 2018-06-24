#include "utils.h"

#define hprintf(fmt, args...) printf("[%s@%d]"fmt,__FILE__,__LINE__,##args)
namespace comnlibs
{
    static bool global_inited = false;
	bool GlobalInit()
	{		
		if (global_inited) return true;

#ifdef _WIN32
		WORD wVersionRequested;
		WSADATA wsaData;
		wVersionRequested = MAKEWORD(2, 2);
		(void)WSAStartup(wVersionRequested, &wsaData);
#endif
        global_inited = true;
		return true;
	}

    timer::timer(int millsec, bool persist)
    {
        _persist = persist;
        _tv.tv_sec = millsec / 1000;
        _tv.tv_usec = (millsec % 1000) * 1000;
    }

	static struct timeval lasttime;
	void timer::timeout_cb(evutil_socket_t fd, short event, void *arg)
	{
		timer *tr = (timer*)arg;
		struct timeval newtime, difference;
		struct event *timeout = &tr->_timeout;
		double elapsed;

		evutil_gettimeofday(&newtime, NULL);
		evutil_timersub(&newtime, &lasttime, &difference);
		elapsed = difference.tv_sec +
			(difference.tv_usec / 1.0e6);

		printf("timeout_cb called at %d: %.3f seconds elapsed.\n",
			(int)newtime.tv_sec, elapsed);
		lasttime = newtime;
        if(tr->_ext_callback)
            tr->_ext_callback(tr->_ext_arg);
	}

	void timer::start(timercb cb, void *arg)
	{
        if (!global_inited)
        {
            h
        }
		_ext_callback = cb;
		_ext_arg = arg;

		int flags = _persist ? EV_PERSIST : 0;
		_base = event_base_new();
		event_assign(&_timeout, _base, -1, flags, timeout_cb, this);
	
		event_add(&_timeout, &_tv);
		evutil_gettimeofday(&lasttime, NULL);
		event_base_dispatch(_base);
	}
}