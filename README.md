# 0x16. C - Simple Shell Project
## 🚀 Description 
The project is about creating our version of a command line interpreter: shell.
In this repository you will find our version of the Shell: simple Unix command interpreter, replicates the basic functionalities of the simple shell (sh), here we will apply the knowledge that we have acquired during the learning of the programming language C, works with the system call of the Kernel.
## 📑 Learning Objectives
- How does a shell work.  
- What is a pid and a ppid.  
- How to manipulate the environment of the current process.  
- What is the difference between a function and a system call.  
- How to create processes.  
- What are the three prototypes of main.  
- How does the shell use the PATH to find the programs.  
- How to execute another program with the execve system call.  
- How to suspend the execution of a process until one of its children terminates.  
- What is EOF / "end-of-file"?.  
## ✔️ General Requirements  
- Allowed editors: vi, vim, or emacs
- All files were compiled on Ubuntu 14.04 LTS
- Programs and functions were compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All files should end with a new line
- Code should use the Betty style. It is checked using betty-style.pl and betty-doc.pl
- No more than 5 functions per file
- All header files should be include guarded
- System calls are only used when needed
## ✔️ List of allowed functions and system calls.  
access (man 2 access),
chdir (man 2 chdir),
close (man 2 close),
closedir (man 3 closedir),  
execve (man 2 execve),
exit (man 3 exit),
fork (man 2 fork),
free (man 3 free),  
stat (__xstat) (man 2 stat),
lstat (__lxstat) (man 2 lstat),
fstat (__fxstat) (man 2 fstat),  
getcwd (man 3 getcwd), 
getline (man 3 getline), 
kill (man 2 kill),
malloc (man 3 malloc),
open (man 2 open),   
opendir (man 3 opendir),
perror (man 3 perror),
read (man 2 read),
readdir (man 3 readdir),    
signal (man 2 signal),
strtok (man 3 strtok),
wait (man 2 wait),
waitpid (man 2 waitpid),  
wait3 (man 2 wait3),
wait4 (man 2 wait4),
write (man 2 write),
_exit (man 2 _exit),    
isatty (man 3 isatty),
fflush (man 3 fflush),  
## 📂 Repository Contents  
Simple Shell files:
File  | Description
------------- | -------------
[AUTHORS](https://github.com/Valentinaga1/simple_shell/blob/master/AUTHORS "AUTHORS")  | Contains the authors of the project.
[_getenv.c](https://github.com/Valentinaga1/simple_shell/blob/master/_getenv.c "_getenv.c")  |  Contains Function to get the environment variable.
[_putchar.c](https://github.com/Valentinaga1/simple_shell/blob/master/_putchar.c "_putchar.c")  | Contains the function to writes the character c to stdout
[error_functions.c](https://github.com/Valentinaga1/simple_shell/blob/master/error_functions.c "error_functions.c")  | Contains the functions to print messagge errors . 
[execute.c](https://github.com/Valentinaga1/simple_shell/blob/master/execute.c "execute.c")  | Contains Functions to execute a process. 
[man_1_simple_shell](https://github.com/Valentinaga1/simple_shell/blob/master/man_1_simple_shell "man_1_simple_shell")  | Contains the man page of our simple shell.
[printenvironment.c](https://github.com/Valentinaga1/simple_shell/blob/master/printenvironment.c "printenvironment.c")  | Contains the function to prints the environment.
[shell.c](https://github.com/Valentinaga1/simple_shell/blob/master/shell.c "shell.c")  | Contains the Function to handle signals, to handle Not interactive mode, and the main function.
[shell.h](https://github.com/Valentinaga1/simple_shell/blob/master/shell.h "shell.h")  | Header file. Contain all the prototype name of the functions.
[strings.c](https://github.com/Valentinaga1/simple_shell/blob/master/stringFunctions.c "strings.c")  | Contains auxilair functions to handdle the strings.
[tokenize.c](https://github.com/Valentinaga1/simple_shell/blob/master/tokenize.c "tokenize.c")  | Contains the function to extract tokens from strings.  

## ⚙ Compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
## 💻 Usage
### Shell works like this in interactive mode:  
```
$ ./hsh  
$ /bin/ls  
hsh shell.c path.c README.md   
$ ls -l  
total 68  
-rw-rw-r-- 1 vagrant vagrant   288 Aug 13 20:34 envprint.c   
-rwxrwxr-x 1 vagrant vagrant 13956 Aug 13 15:32 ex  
-rw-rw-r-- 1 vagrant vagrant   784 Aug 13 20:44 execute.c    
-rwxrwxr-x 1 vagrant vagrant 14209 Aug 13 20:36 hsh  
-rw-rw-r-- 1 vagrant vagrant   277 Aug 12 17:42 _putchar.c  
-rw-rw-r-- 1 vagrant vagrant  2424 Aug 14 15:23 README.md   
-rw-rw-r-- 1 vagrant vagrant   789 Aug 13 20:47 shell.c   
-rw-rw-r-- 1 vagrant vagrant   570 Aug 13 20:35 shell.h   
-rw-rw-r-- 1 vagrant vagrant  1204 Aug 13 20:45 stringFunctions.c   
-rw-rw-r-- 1 vagrant vagrant   457 Aug 13 20:45 strtok.c  
$ pwd   
/home/vagrant/simple_shell  
$exit    
$  
```
### Shell works like this in non-interactive mode:  
```
$ echo "/bin/ls" | ./hsh  
README.md  _putchar.c  _which.c  envprint.c  ex  execute.c   
hsh  shell.c  shell.h  stringFunctions.c  strtok.c  
```
## 🚀Authors
* **Daniel Villalba** - *Holberton School Student* - [DanielVillalba-holberton](https://github.com/DanielVillalba-holberton)
* **Valentina Gómez** - *Holberton School Student* - [Valentinaga1](https://github.com/Valentinaga1)
