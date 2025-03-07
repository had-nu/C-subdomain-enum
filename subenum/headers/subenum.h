#ifndef SUBENUM_H
#define SUBENUM_H

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>

int		ft_check_subdomains(const char *domain, const char *subdomain);

char	**ft_read_wordlist(const char *filename, int *count);

#endif
