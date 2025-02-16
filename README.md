# SubEnum - Subdomain Enumeration Tool in C
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![GitHub](https://img.shields.io/github/license/seu-usuario/subenum?style=for-the-badge)

SubEnum é uma ferramenta leve e eficiente para enumeração de subdomínios escrita em C, projetada para operações de segurança ofensiva e reconhecimento de infraestrutura.

## ✨ Features

- Leitura de wordlists para teste de subdomínios
- Resolução DNS rápida usando `getaddrinfo()`
- Saída colorida para melhor visualização
- Medição de tempo de execução
- Gerenciamento seguro de memória
- Fácil integração em pipelines de segurança

## 📦 Instalação

# Clone o repositório
```bash
git clone https://github.com/seu-usuario/subenum.git
cd subenum
```
# Compile o projeto
```bash
make
```
# Crie uma wordlist de exemplo
```bash
echo -e "www\nmail\nftp\nadmin\nteste" > wordlist.txt
```
## 🚀 Uso
```bash
./subenum <domain> <wordlist>

# Exemplo:
./subenum example.com wordlist.txt
```

Saída de exemplo:
```bash
[*] Verificando 5 subdomains...
[+] www.example.com
[+] mail.example.com

[*] Total de subdominios validos: 2/5
[*] Tempo de execução: 0.0 segundos
```
## 🧠 Code Structure
```bash
├── headers/
│   └── subenum.h
├── src/
│   ├── main.c
│   └── subenum.c
├── Makefile
└── README.md
```

Componentes Principais

1. subenum.h
    Define macros de cores
    Declarações de funções
    Includes de bibliotecas

2. subenum.c
    ft_check_subdomains(): Verifica a existência de subdomínios
    ft_read_wordlist(): Processa arquivos de wordlist

3. main.c
    Lógica principal do programa
    Medição de tempo de execução
    Gerenciamento de saída

## 🛠️ Makefile Targets
**Comando**		   **Descrição**
make		-> Compila o projeto
make clean 	-> Remove arquivos objetos e binários

## 🤝 Contribuição

Contribuições são bem-vindas! Por favor:

1. Abra uma issue para discutir a mudança proposta;
2. Faça fork do repositório;
3. Crie um branch com sua feature `(git checkout -b feature/awesome-feature)`;
4. Commit suas mudanças `(git commit -m 'Add awesome feature')`;
5. Push para o branch `(git push origin feature/awesome-feature)`;
6. Abra um Pull Request.

## 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE para detalhes.

## 🙌 Reconhecimentos

1. Inspirado em ferramentas como Sublist3r e Amass
2. Utiliza técnicas padrão de resolução DNS
3. Código otimizado para performance


**Notas para personalização:**
1. Substitua `seu-usuario` pelo seu nome de usuário do GitHub
2. Adicione uma licença real no arquivo LICENSE
3. Inclua badges adicionais relevantes
4. Adicione uma seção de roadmap se desejar
5. Inclua informações de contato para relatórios de segurança
