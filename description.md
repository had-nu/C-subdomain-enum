Hey guys, what's up!

In January, I was immersed in an incredible experience at the @42Porto Piscine, and I can say it was the most amazing educational experience I've ever had. It was 26 intensive days, 10 hours a day, 7 days a week, just building projects in C. Now that it's over, I feel a little bored. So, I've been thinking, "What if I try to build something with all that I've learned? What am I capable of doing now?"

I am a cybersecurity enthusiast, and I've already spent countless hours collecting data and all kinds of information, trying to do something close to a real-world cybersecurity job. I love the role of an ethical hacker, social engineering, and so on, but it's quite difficult to simulate some scenarios in a homelab by yourself. Before you know it, you're drowning in an ocean of tools, techniques, and countless courses, only to end up achieving nothing new or worthwhile. Not even the slightest practical knowledge.

Among this sea of tools, I tend to use a lot of subdomain enumeration tools. Collecting info is my favorite part of the ethical hacker role, but each tool has different strengths, and sometimes you need to use multiple tools to meet a need. For example, Amass is comprehensive but might be slow, while Sublist3r is quick but less thorough. Some tools require more resources; others need API keys, and some might generate excessive traffic and get blocked. Compatibility issues can arise if you try to integrate with other tools, and so on. It might be confusing to decide which tool to pick based on your specific needs, and it's quite common to get overwhelmed and lose precious time. So, I decided to build my own subdomain enumeration tool in C :)

"Oh, why don't you use aggregation tools that combine the most popular subdomain enumeration tools, or build an aggregator?" Because it's not fun! I don't want to! I want to see how far I can go by building my own functional program in C, with my own libraries and functions. There are a lot of Python tools and tutorials about building this in Python, but nothing about how to do it in C. So, let me try something new.

By the way, subdomain enumeration is the process of finding all subdomains associated with a main domain (e.g., sub.example.com). It's an essential technique in security tests, pentests, and bug bounty programs, as it helps map the attack surface of an organization, revealing possible vulnerable points or exposed services.

I am not building a complete tool with all the features I can imagine. I will start with an MVP. This project is just about that. I will describe how I outlined the MVP features, my workflow, and how I thought through my process.

----
What problem do I want to solve?


How will I build it?
First, I need to outline the MVP features. The simplest approach is reading subdomains from a wordlist and checking DNS records. For DNS, using the getaddrinfo() function makes sense because it's standard and handles DNS queries without requiring external libraries. That way, I can focus on the core logic without getting bogged down with networking complexities. Let's save some time. Later, I can make this tool more robust. It's just an MVP

Hint: man getaddrinfo

Next, project structure. Setting up a Git repo with some standard directories to organize the code. A Makefile will simplify compilation, especially as the project grows. I will explain each part of the Makefile soon.

Now, the core functionality. The main steps are:

1. Reading a wordlist;
2. Generating subdomains; and
3. Checking if they resolve.

For the wordlist, using fopen() and fgets() is basic but effective (again, take a look at the manuals). I'm still learning about dynamic arrays, so using malloc() and free() to read lines into a buffer is a great way to practice memory management and prevent leaks.

Generating subdomains involves concatenating each word with the target domain. I need a function that takes the domain and a word, combines them into a subdomain, and then checks it. Using strcat() or snprintf() could work, but I need to be careful about buffer overflows.

Finally, I need a function to return DNS information (after DNS checking with getaddrinfo), so if it succeeds, the subdomain exists.

In the main function, I'll parse command-line arguments (domain, wordlist path), read the wordlist into an array, iterate through each word to generate subdomains, and check them. The realloc() function can be helpful to deal with the growing wordlist, or maybe a fixed-size array or a pre-count of lines to keep it simple. I don't want to deal with buffer overflows in this MVP.

I am a defender of learning good practices early, as they help handle errors and avoid pitfalls. So, I try to perform checks whenever possible, like making commits after each major step, checking if files open correctly, if memory allocations succeed, and cleaning up resources after use.

After all of this, I'll test the MVP with an example wordlist and domain, showing how to compile and run the program.

Potential issues to consider:

1. Buffer overflow in string handling;
2. Proper use of pointers and memory; and
3. Ensuring the code is portable across different systems (a final personal challenge).

For future MVP improvements, I can list threading, more DNS record types, wildcard handling, or something like that. I don't know yet.
