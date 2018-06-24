#pragma once

#include <comn.h>

namespace comnlibs
{
	typedef void(*timercb)(void *arg);

	bool GlobalInit();

	class timer
	{
	public:
        timer(int millsec, bool persist = false);
		void start(timercb cb, void *arg);

    public:
        static void timeout_cb(evutil_socket_t fd, short event, void *arg);
	private:
		bool _persist;
		struct event _timeout;
		struct timeval _tv;
		struct event_base *_base;

		timercb _ext_callback;
		void *_ext_arg;
	};
}
