#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

void
die(const char *FMT, ...)
{
	va_list ap;

	va_start(ap, FMT);
	vfprintf(stderr, FMT, ap);
	va_end(ap);

	if (FMT[0] && FMT[strlen(FMT)-1] == ':') {
		fputc(' ', stderr);
		perror(NULL);
	} else {
		fputc('\n', stderr);
	}

	exit(1);
}

void *
ecalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!(p = calloc(nmemb, size)))
		die("calloc:");
	return p;
}
