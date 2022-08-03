# About:
This is a group project for Holberton School Tulsa, OK to write a simple Unix command interpreter for Holberton School Tulsa, OK. Friday, July 29th, 2022.

## Tasks:
### Write a UNIX command line interpreter.

## Compilation:
The simple shell is compiled using the following command:
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o -g -O1 hsh

OR

./compile.sh
```
## Interactive Mode:
The simple shell is initiated in interactive mode with the command:
```sh
./hsh
$
```
## Non-Interactive Mode
The simple shell is initiated in non-interactive mode with the command:
```sh
echo "/bin/ls" | ./HSH
```

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments

## Examples

## File Descriptors

## Authors
Alexandra Tatum & Conner Curtis
