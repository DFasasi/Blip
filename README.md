# Blip! (Binary Parser Language)

## General Overview
This project revolves around the development of a simplistic toy programming language dubbed "Blip". In its initial phase (Phase A), the focus is on constructing basic straight-line code featuring fundamental assignment (var, set) and output (output, text) commands.

## Language Design and Parsing
Blip distinguishes itself through its parsing simplicity. This deliberate choice enables a unique syntax that deviates from conventional programming languages, opting for a prefix expression syntax instead of the more common infix. For instance, to denote "2 + 2", the syntax is "+ 2 2". This departure from traditional syntax facilitates learning and implementation from the ground up.

## Features Implemented
1. **Variable Initialization (var):** Introduces a new variable, managing re-initializations while issuing warnings.
2. **Variable Assignment (set):** Assigns a new value to an existing variable, issuing warnings for undeclared variables.
3. **Output Expressions (output):** Evaluates and displays the results of expressions utilizing Blip's integer operators.
4. **Text Output (text):** Displays a text message on the screen.

## Symbol Table and Memory
The implementation of variables necessitates an efficient data structure capable of storing and retrieving output based on the provided input string. In this project, a self-implemented linked list fulfills this role by storing the computed value of a given variable. Computation of this input is achieved through the utilization of a recursive function that generates a binary expression tree based on the provided tokens/elements. Alternatively, the stack data structure can also be utilized to push and pop variables based on the input string.

## Usage of C++ Libraries and Binary Tree Data Structure
To enhance efficiency and facilitate complex operations, this project utilizes C++ libraries for optimized data handling and processing. Specifically, the binary tree data structure is employed to efficiently manage expressions and variables within the Blip language. This choice not only ensures robust performance but also enables scalability for potential future expansions and enhancements.









