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

### Logical VS Bitwise

| Bitwise | Logical |
| :---: | :---: |
| a & b | a && b |
| a \| b | a \|\| b |
| a ^ b | a != b |
| ~a | !a |

### Shift operators (Read and practice until you are comfortable with it)

#### Right shift (>>):
The right shift operator is denoted by '>>'. It takes two operands: the bit pattern (an integer) and the number of positions you want to shift the bits to the right. When you perform a right shift, you are effectively dividing the number by 2 to the power of the specified shift count and discarding the remainder. With right shift you put zeros on left.
Example:
  ```
  int i = 14; // Bit pattern 00001110
  int j = i >> 1; // Here, we shift the bit pattern by 1 position to the right, resulting in 00000111 = 7, which is 14 divided by 2.
  ```
The right shift operation is equivalent to performing integer division by 2 to the power of the specified shift count. So, for each right shift by n positions, the number is effectively divided by 2^n.

#### Left shift (<<)
The left shift operator is denoted by '<<'. Like the right shift, it also takes two operands: the bit pattern (an integer) and the number of positions you want to shift the bits to the left. When you perform a left shift, you are effectively multiplying the number by 2 to the power of the specified shift count. With left shift you put zeros on right.
Example:
  ```
  int i = 14; // Bit pattern 00001110
  int j = i << 1; // Here, we shift the bit pattern by 1 position to the left, resulting in 00011100 = 28, which is 14 multiplied by 2.  
  ```

The left shift operation is equivalent to performing multiplication by 2 to the power of the specified shift count. So, for each left shift by n positions, the number is effectively multiplied by 2^n.

### Bitwise assignment operators (Read and practice until you are comfortable with it)

| Symbol | Operator |
| :---: | :---: |
| &= | bitwise AND assignment |
| \|= | bitwise inclusive OR assignment |
| ^= | bitwise exclusive OR assignment |
| <<= | left shift assignment |
| >>= | right shift assignment |

#### &= (bitwise AND assignment)
The '&=' operator combines the bitwise AND operation with the estimate. That is, it takes the value of the variable on the left, performs a bitwise AND operation on the value of the variable on the right, and then assigns the result back to the variable on the left.
Example:
  ```
  int x = 10; // In binary: 00001010
  int y = 6;  // In binary: 00000110
  x &= y;
  ```
Result:
  ```
  // Binary AND operation between 00001010 (x) and 00000110 (y)
  // Compares each bit, if both bits are 1, the result bit is 1, otherwise, it's 0
  // Only the second bit from the right has a common 1 between x and y
  // Therefore, x is updated to 00000010 in binary, which is 2 in decimal.
  // x = 2
  ```

