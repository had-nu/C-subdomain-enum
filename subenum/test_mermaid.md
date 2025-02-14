::: mermaid
flowchart TD
    A[Wordlist File] --|ft_read_wordlist()|--> B[Subdomains Array]
    B --|ft_check_subdomain|--> C[DNS Consults]
    C --> D[FQDN generated //sub.domain.tld//]
    D --|fn_getaddrinfo|--> E[DNS Resolver //8.8.8.8:53//]

:::