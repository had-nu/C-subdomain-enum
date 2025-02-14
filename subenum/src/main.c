#include "subenum.h"

int ft_check_subdomains(const char *domain, const char *subdomain);

char **ft_read_wordlist(const char *filename, int *count);

int main(int argc, char *argv[])
{
	clock_t init = clock();
	if (argc != 3)
	{
		printf("Uso: %s <domain> <wordlist>\n", argv[0]);
		return (1);
	}

	int		count;
	int		valid = 0;
	char	**words = ft_read_wordlist(argv[2], &count);

	printf("[*] Verificando %d subdomains...\n", count);

	double time = (double)(clock() - init) / CLOCKS_PER_SEC;

	for (int i = 0; i < count; i++)
	{
		if (ft_check_subdomains(argv[1], words[i]))
		{
			valid++;
			printf(GREEN "[+] " RESET "%s.%s\n", words[i], argv[1]);
		}
		free(words[i]);
	}
	free(words);
	printf("\n[*] Total de subdominios validos: %d/%d", valid, count);
	printf("\n[*] Tempo de execução: %.2f segundos\n", time);
	return (0);
}