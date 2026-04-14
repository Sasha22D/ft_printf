*This project has been created as part of the 42 curriculum by sadaniel.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the standard C `printf` function. It handles a subset of format specifiers and returns the total number of characters printed, just like the original. The project is built as a static library (`libftprintf.a`) that can be linked into any C project alongside `libft`.

### Supported conversions

| Specifier | Description |
|---|---|
| `%c` | Print a single character |
| `%s` | Print a string (`(null)` if NULL) |
| `%p` | Print a pointer address in hexadecimal (`(nil)` if NULL) |
| `%d` / `%i` | Print a signed decimal integer |
| `%u` | Print an unsigned decimal integer |
| `%x` | Print an unsigned integer in lowercase hexadecimal |
| `%X` | Print an unsigned integer in uppercase hexadecimal |
| `%%` | Print a literal `%` character |

---

## Instructions

### Compilation

```bash
git clone <repo_url>
cd ft_printf
make
```

This produces a `libftprintf.a` static library in the root of the project. The `libft/` submodule is compiled automatically as a dependency.

### Using the library in your project

Link `libftprintf.a` and include the header in your source file:

```c
#include "include/ft_printf.h"
```

Then compile with:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o my_program
```

### Creating a test executable

Create a `main.c` at the root of the project:

```c
#include "include/ft_printf.h"
#include <stdio.h>

int main(void)
{
    int r1;
    int r2;

    r1 = printf("printf   : [%c] [%s] [%d] [%x]\n", 'A', "hello", -42, 255);
    r2 = ft_printf("ft_printf: [%c] [%s] [%d] [%x]\n", 'A', "hello", -42, 255);
    printf("printf    returned: %d\n", r1);
    printf("ft_printf returned: %d\n", r2);
    return (0);
}
```

Then compile and run:

```bash
make
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

### Cleanup

```bash
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # full recompile
```

---

## Project structure

```
ft_printf/
├── Makefile
├── README.md
├── libft/            # libft submodule (compiled as dependency)
├── include/
│   └── ft_printf.h
└── srcs/
    ├── ft_printf.c   # main ft_printf function and ft_putunsigned
    └── utils.c       # format dispatch, hex/ptr/str print helpers
```

---

## Resources

- [`printf` man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [`va_start` / `va_arg` / `va_end` — stdarg.h](https://man7.org/linux/man-pages/man3/va_arg.3.html)
- [`stdint.h` — uintptr_t](https://man7.org/linux/man-pages/man0/stdint.h.0p.html)
- [ar — create and maintain library archives](https://man7.org/linux/man-pages/man1/ar.1.html)
