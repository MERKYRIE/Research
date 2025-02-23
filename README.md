# Introduction

Many games have been using a tilemap or its derivatives (octree as a three-dimensional approach).

Simulating worlds effectively in terms of memory and performance has been always being a problem.

The goal is to show how to optimize a tilemap (a two-dimensional level data structure).

# State of the Art

I have been searching a lot for any already existing information about the chosen subject.

Unfortunately, I've failed to find an exhaustive reference around this topic, only the plain ones.

I'm still sure it's somewhere out there but I'm basing my research on flat grounds.

# Approach

## Remove function parameters in calls to tilemap's partitions for performance upgrade

The first problem of a naive tilemap implementation in terms of performance is Space's updates.

Space is updating each Partition with one function call and 6 64-bits copying function parameters.

And then Partition is processing each Ground and each Entity in the exact same way.

So totally 3 equivalent and redundant function calls are involved throughout this in-depth rendering process.

18 64-bits copying function parameters (3 function calls * 6 64-bits copying function parameters) are passed.

The process itself on how the function parameters are transfered depends on just 2 things:

1. The Instruction Set Architecture (ISA) as 8086, IA-32, x86-64, A32, A64, MIPS, SPARC, SuperH, 68k

2. The Application Binary Interface (ABI) as vectorcall, Microsoft x64 (Windows), System V AMD64 ABI (Linux)

ISA is related to a specific processor and is a prerequisite for ABI proper choice.

ABI is defined by Operating System (OS) and is a precondition for the calling convention.

Finally, the calling convention specifies the process itself on how the function parameters are transfered.

A function parameter can be either pushed on the stack or placed in a register.

To be mentioned, various ABIs are resolving this process in rather different ways, for example:

1. Windows places the first 4 integer function parameters in RCX, RDX, R8, R9 registers respectively;

   and the first 4 floating point function parameters in XMM0, XMM1, XMM2, XMM3 registers respectively;

   whilst pushing all the other ones on the stack in the right to left order
  
2. Linux places the first 6 integer parameters in RDI, RSI, RDX, RCX, R8, R9 registers;
   
   the first 8 floating parameters in XMM0, XMM1, XMM2, XMM3, XMM4, XMM5, XMM6, XMM7 registers;
   
   whilst pushing all the other ones on the stack in the right to left order
   
An assembly instruction "Mov" is usually used to place a function parameter in a register.

It can be noted that this specific assembly instruction provides one of the fastest behaviors.

The reason of it is that register operations are computed in a very quick way.

An assembly instruction "Push" is usually used to push a function parameter on the stack.

Note that this specific assembly instruction provides a much slower behavior than the previous one.

The reason of it is that stack operations are computed in a slowed down way.

That said, we conclude that the function parameters placed in registers have some performance gain.

So it is more preferable to lay down under the ABI's register function parameters limitations.

As we are targeting multiple platforms, we should follow the strictest ABI's limitations as possible.

Here, Windows is providing the least number of function parameters (4 integer and 4 floating).

Whilst Linux provides a little bit more both of them (6 integer and 8 floating).

In our case we're using 2 integer and 4 floating 64-bits copying function parameters, so:

1. The number of the function parameters (2 and 4) is not exceeding ABI's register limitations
   
2. The size of the function parameters (64) is speeding us up on a 64-bit architecture

3. The qualifier of the function parameters (copying) is implying copy and use (without a pointer)

4. The type of the function parameters (integer and floating) is not using an allocation pointer

Like that, we haven't hit the worst case - pushing the function parameters on the stack.

But nevertheless stack operations are actually taking place in such a case slowing all down.

The fact that we're calling 3 functions with 6 parameters gives us 18 of them.

Each further executed function call is actually pushing the previous function parameters on the stack.

And this executed function call is then popping the previous function parameters from the stack.

Such a process can be illustrated on a step by step basis by the following:

1. Space calls Partition - the Partition parameters are now placed in the registers

2. Partition calls Ground - the Partition parameters are now pushed on the stack, the Ground parameters are now placed in the registers

# Analysis

# Bibliography
