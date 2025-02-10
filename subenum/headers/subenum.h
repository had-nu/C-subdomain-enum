#ifndef SUBENUM_H
#define SUBENUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int	check_subdomain(const char *domain, const char *subdomain);

char	**read_wordlist(const char *filename, int *count);

#endif
