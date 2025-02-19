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
# Analysis
# Bibliography
