#include <time.h>

static long     ft_milsec(void)
{
    long				ns;
    time_t				s;
    struct timespec		spec;

    clock_gettime(CLOCK_REALTIME, &spec);
    s = spec.tv_sec;
    ns = spec.tv_nsec;
    return (s * 1000 + ns / 1000000);
}

long            time_between_frames(void)
{
	static long ph_ms;
	long dms;
	
	if (ph_ms == 0)
		ph_ms = ft_milsec();
	dms = ft_milsec() - ph_ms;
	ph_ms = ft_milsec();
	return (dms);
}