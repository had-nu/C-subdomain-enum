# SubEnum - Subdomain Enumeration Tool in C
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![License](https://img.shields.io/github/license/had-nu/C-subdomain-enum?style=for-the-badge)

SubEnum is a lightweight, efficient subdomain enumeration tool written in C, designed for offensive security operations and infrastructure reconnaissance.

## ✨ Features

- Wordlist processing for subdomain testing
- Fast DNS resolution using `getaddrinfo()`
- Execution time measurement
- Safe memory management
- Easy integration into security pipelines

## 📦 Instalação

### Clone repository
```bash
git clone https://github.com/had-nu/C-subdomain-enum.git
cd C-subdomain-enum
```
### Compile project
```bash
make
```
### Create sample wordlist
```bash
echo -e "www\nmail\nftp\nadmin\nteste" > wordlist.txt
```
## 🚀 Usage
```bash
./C-subdomain-enum <domain> <wordlist>

# Exemple:
./subenum example.com wordlist.txt
```

Sample output:
```bash
[*] Checking 5 subdomains...
[+] www.example.com
[+] mail.example.com

[*] Valid subdomains found: 2/5
[*] Execution time: 0.00 seconds
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

**Main Components**

1. subenum.h
	- Colour macros
	- Function declarations
	- Library includes

2. subenum.c
	- ft_check_subdomains(): Verifies subdomain existence
	- ft_read_wordlist(): Processes wordlist files

3. main.c
	- Core program logic
    - Execution timing
    - Output management

## 🛠️ Makefile Targets

| **Command**   | **Description**                |
|---------------|--------------------------------|
| `make`        | Compiles the project           |
| `make clean`  | Removes object files and binary|

## 🤝 Contribution

Contributions welcome! Please:

1. Open an issue to discuss proposed changes;
2. Fork the repository;
3. Create feature branch `(git checkout -b feature/awesome-feature)`;
4. Commit changes `(git commit -m 'Add awesome feature')`;
5. Push branch `(git push origin feature/awesome-feature)`;
6. Open Pull Request.

## 📄 Licence

This project is licensed under the MIT Licence - see LICENCE file for details.

## 🙌 Acknowledgements

1. Inspired by tools like Sublist3r and Amass
2. Uses standard DNS resolution techniques
3. Code optimised for performance
