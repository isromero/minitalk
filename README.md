# minitalk
The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.

#### The goal of this project is:
  - To create two executables named: server and client.
  - The client will send information (a string) to the server, using UNIX signals.
  - The server must correctly receive and interpret this information, then display it.

#### Specific rules of the project:
   - The executables must be named client and server.
   - You can provide a Makefile, which will compile the source files of your program. Can't do relink.
   - You can use libft project.
   - You must handle errors carefully. Under no circumstances your program may terminate unexpectedly (segfault, bus error, double free, etc).
   - Your program cannot have memory leaks.
   - You can use one global variable per program (one for the client and one for the server), but you will have to justify its use.
   - In the mandatory part you are allowed to use the following functions:
      - write
      - ft_printf and whatever equivalent YOU have programmed
      - signal
      - sigemptyset
      - sigaddset
      - sigaction
      - kill
      - getpid
      - malloc
      - free
      - pause
      - sleep
      - asleep
      - leave

## Signals? What is that?
***Signals are a form of communication between processes*** used by Unix-like systems
and those respecting the POSIX standards. ***Signals can be defined as a message***,
an event or an interrupt. When a process receives a signal, the process will
stop what its doing and ***take some action***.

In the context of the Minitalk project, signals are used to transmit messages
between processes using the minitalk communication protocol.

### A visual representation made by [42-cursus.gitbook-guide](https://42-cursus.gitbook.io/guide/rank-02/minitalk/understand-minitalk) :
  ![client and server diagram](https://1295869145-files.gitbook.io/~/files/v0/b/gitbook-x-prod.appspot.com/o/spaces%2Fz2zo8aAL0o31034sj7J7%2Fuploads%2F5eY61q1QT9MHUx2Zxf7g%2Fminitalk_scheme.png?alt=media&token=22a960bd-d30e-4e73-a4e7-a683b9c4d931)

Looking at this visual representation maybe you are asking: how can I transform my chars into bits for display the correct message? That's where the concept of bit translation✨ comes in.

## Bitwise operations in C
For understanding correctly the bit translation you have to know every operation possible and their operator for the bit translation:

In the C programming language, operations can be performed on a bit level using bitwise operators.

Bitwise operations are contrasted by byte-level operations which characterize the bitwise operators' logical counterparts, the AND, OR, NOT operators. Instead of performing on individual bits, byte-level operators perform on strings of eight bits (known as bytes) at a time. The reason for this is that a byte is normally the smallest unit of addressable memory (i.e. data with a unique memory address).

This applies to bitwise operators as well, which means that even though they operate on only one bit at a time they cannot accept anything smaller than a byte as their input.

### Bitwise operators

| Symbol | Operator |
| :---: | :---: |
| & | bitwise AND |
| \| | bitwise inclusive OR |
| ^ | bitwise XOR (exclusive OR) |
| << | left shift |
| >> | right shift |
| ~ | bitwise NOT (one's complement) (unary) |

#### Logical VS Bitwise

| Bitwise | Logical |
| :---: | :---: |
| a & b | a && b |
| a \| b | a \|\| b |
| a ^ b | a != b |
| ~a | !a |

#### Shift operators (THIS IS WHAT YOU NEED 100%)


#### Bitwise assignment operators


