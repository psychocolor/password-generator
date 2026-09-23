# password-generator

## Description
C++ script for generating multiple passwords of any desired length (Capped at 100 passwords and 50 characters, can be changed in the code) and exporting them to a .txt file. Uses the Mersenne Twister algorithm to generate pseudo-random characters for the passwords. Originally based on my first-semester Computer Science project.

## How to run
1. Clone the repository.
2. Compile source code using a compiler of your choice (in my case g++).
```bash
g++ -o pw-gen main.cpp 
```
3. Run the executable.
```bash
./pw-gen
```
