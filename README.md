# ft_printf

The goal of this project is to recode `printf()`.

## Guidelines
- The project is written in C.
- The code follows the norm coding standards.
- Functions do not cause unexpected crashes (segfaults, bus errors, etc.).
- All heap-allocated memory is freed; no memory leaks.
- A Makefile is provided with rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- Only the allowed external functions are used: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.
- My `libft` library functions are used.
- Program name: `libftprintf.a`
- The function handles these conversions:
  - `%c` Prints a single character.
  - `%s` Prints a string.
  - `%p` Prints a void * pointer in hexadecimal format.
  - `%d` Prints a decimal (base 10) number.
  - `%i` Prints an integer in base 10.
  - `%u` Prints an unsigned decimal (base 10) number.
  - `%x` Prints a number in hexadecimal (base 16) lowercase format.
  - `%X` Prints a number in hexadecimal (base 16) uppercase format.
  - `%%` Prints a percent sign.
- The function includes precision handling in its output, just like the original printf().

## Creator's Note
Project made with ❤️ by [**cgangaro**](https://github.com/cgangaro).

If you found this project helpful, please consider giving it a ⭐ and following me!

Connect with me on [LinkedIn](https://fr.linkedin.com/in/camille-gangarossa-2ab929227)!

Feel free to reach out with any questions.
