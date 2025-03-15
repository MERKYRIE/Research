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

3. Partition regains control - the Partition parameters are now popped from the stack

4. Partition calls Entity - the Partition parameters are now pushed on the stack, the Entity parameters are now placed in the registers

5. Partition regains control - the Partition parameters are now popped from the stack

6. Space regains control - the registers are filled with the information defined by ABI itself

Pushing/popping the parameters on/from the stack is a pretty time-consuming operation.

There are 2 pushes and 2 pops.

Each of them is 6 64-bits parameters stack push/pop instructions long.

12 (2 pushes * 6 parameters) parameters from pushes and 12 (2 pops * 6 parameters) parameters from pops.

Totally, 24 (12 pushes + 12 pops) parameters.

24 stack instructions.

Moving the parameters to the registers is a time-consuming operation too.

There is 1 such operation.

It is 6 64-bits parameters register mov instructions long.

6 register instructions.

So it will be 24 stack instructions and 6 register ones in total.

Multiplied by every Partition in entire Space.

Let us say, there are 1000000 (1000 by width * 1000 by height) of them now.

In such a case 24000000 (24 instructions * 1000000 partitions) stack instructions and 6000000 (6 instructions * 1000000 partitions) register ones would totally take place.

It is possible to move all the code from Ground and from Entity to Partition.

Removing all the stack instructions in such a way.

But still preserving all the register ones.

Moreover, degrading the code structure by it.

There is a better solution.

To convert all the parameters to the global variables.

## Replace std::shared_ptr usages with std::unique_ptr ones for memory upgrade

## Remove checking of ground pointer validity for performance upgrade

## Separate ground structures and entity ones for performance upgrade

## Move ground and entity image here for memory upgrade

## Move ground and entity image loading for permormance upgrade

# Analysis

## Remove function parameters in calls to tilemap's partitions for performance upgrade

Space evolutioned from Space1.hxx to Space2.hxx by moving the call parameters as its global variables.

It was done to directly pass them as function parameters in calls to tilemap's partitions.

The following code was added to Space2.hxx (lines 39-61):

//Configures viewport's current respective coordinates
\
//Move here as global to directly pass as function parameters in calls to tilemap's partitions
\
double FX;
\
double FY;
\
//Configures viewport's current respective scale
\
//Move here as global to directly pass as function parameters in calls to tilemap's partitions
\
double FScaleX;
\
double FScaleY;
\
//Configures viewport's last respective scale
\
//Move here as global to directly pass as function parameters in calls to tilemap's partitions
\
double FScaleLastX;
\
double FScaleLastY;
\
//Configures tilemap's current respective partition
\
//Move here as global to directly pass as function parameters in calls to tilemap's partitions
\
std::int64_t FIterationX;
\
std::int64_t FIterationY;

Space evolutioned from Space1.cxx to Space2.cxx by replacing the call parameters by its global variables.

It was also done to the loops counters in the iteration to keep them updated.

The following code was modified in Space2.cxx (lines 18-...-21):

for(FIterationX = 0 ; FIterationX < FWidth ; FIterationX++)
\
...
\
for(FIterationY = 0 ; FIterationY < FHeight ; FIterationY++)

The same code (lines 46-...-48):

for(FIterationX = 0 ; FIterationX < FWidth ; FIterationX++)
\
...
\
for(FIterationY = 0 ; FIterationY < FHeight ; FIterationY++)

The following code (line 50):

FMatrix[FIterationX][FIterationY]->IUpdate();

## Replace std::shared_ptr usages with std::unique_ptr ones for memory upgrade

## Remove checking of ground pointer validity for performance upgrade

## Separate ground structures and entity ones for performance upgrade

## Move ground and entity image here for memory upgrade

## Move ground and entity image loading for permormance upgrade

# Bibliography

https://link.springer.com/book/10.1007/978-1-4842-5076-1 - Netwide Assembly (NASM) and stand-alone assembly programming with it under Linux x64 and Windows x64

https://link.springer.com/book/10.1007/978-1-4842-9603-5 - Microsoft Assembly (MASM) and Microsoft Visual C (MSVC) linked with assembly programming under Windows x64

https://en.wikipedia.org/wiki/Template:Program_execution - general low-level programming staff throughout all the application stages

https://en.wikipedia.org/wiki/Template:Application_binary_interface - specific low-level programming staff only about the compilation stage

https://en.wikipedia.org/wiki/Template:X86_assembly_topics - hardware programming staff commonly on the processor level
