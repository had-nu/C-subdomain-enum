#include "subenum.h"

int check_subdomains(const char *domain, const char *subdomain)
{
	struct 	addrinfo hints, *res;
	char	full_domain[256];
	int		result;

	snprintf(full_domain, sizeof(full_domain), "%s.%s", subdomain, domain);

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((result = getaddrinfo(full_domain, NULL, &hints, &res)) == 0)
	{
		freeaddrinfo(res);
		return (1);
	}
	printf("Falha na resolução: %s (%d)\n", full_domain, result);
	return (0);
}

char **read_wordlist(const char *filename, int *count)
{
	FILE *file = fopen(filename, "r");
	if (!file)
	{
		perror("Erro ao abrir arquivo");
		exit(EXIT_FAILURE);
	}

	char	**words = NULL;
	char	buffer[256];
	*count = 0;

	while (fgets(buffer, sizeof(buffer), file))
	{
		buffer[strcspn(buffer, "\n")] = 0;

		words = realloc(words, (*count + 1) * sizeof(char *));
		words[*count] = malloc(strlen(buffer) + 1);
		strcpy(words[*count], buffer);

		(*count)++;
	}
	fclose(file);
	return (words);
}
