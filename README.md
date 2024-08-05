# Minishell
A group project by Ben Thomas and Jean Teissier.

## Intro
Minishell is a miniature, but powerful, version of the bash command line interface.
You can do most of what you want:
- Launch executables
- Navigate & create files/directories
- Use vim & other command line tools
- Pipe commands into one another
- Create heredocs
- Redirect input/output
- Create, export & expand environment variables
- Access the exit status of the previous command {$?}

Some key features we didn't implement for simplicity:
- Parentheses
- $$ and || operators
- background execution (&)

## Getting started
```
make
./minishell
```
Run the make command to compile the program, and ./minishell to launch the executable.

After that you're free to do what ever you want. Some interesting commands to try:
```
export make=Make
cat $make'file'
```

```
vim test.txt
```

```
echo ::::???'''""$PATH""'''????::::
```

