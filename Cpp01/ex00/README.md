# BraiiiiiiinnnzzzZ 🧟

A C++98 program demonstrating memory allocation differences between stack and heap using a Zombie class.

## Description

This project illustrates two ways of creating objects in C++:
- **Stack allocation**: Objects created automatically and destroyed when out of scope
- **Heap allocation**: Objects created with `new` that must be manually destroyed with `delete`

## Files

- `Zombie.hpp` - Zombie class declaration
- `Zombie.cpp` - Zombie class implementation
- `newZombie.cpp` - Creates a zombie on the heap (returns pointer)
- `randomChump.cpp` - Creates a zombie on the stack (automatic cleanup)
- `main.cpp` - Demonstrates both allocation methods

## Build

```bash
make
```

## Usage

```bash
./BraiiiiiiinnnzzzZ
```

### Expected Output

```
Dancer Zombie: BraiiiiiiinnnzzzZ...
Singer Zombie: BraiiiiiiinnnzzzZ...
Singer Zombie has been killed! 🧟
Dancer Zombie has been killed! 🧟
```

## Key Concepts

**newZombie()**: Allocates a zombie on the heap using `new`. The zombie persists beyond function scope and must be manually deleted to avoid memory leaks.

**randomChump()**: Allocates a zombie on the stack. The zombie is automatically destroyed when the function returns.

## Compilation

- Compiler: c++
- Standard: C++98
- Flags: `-Wall -Wextra -Werror -std=c++98 -pedantic`

## Clean

```bash
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild everything
```
