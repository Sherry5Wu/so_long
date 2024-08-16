#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//case: test specifers: i, d, u
	printf("sys-char_printed=%d\n", printf("%d\n", 23));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%d\n", 23));

	printf("sys-char_printed=%d\n", printf("%d\n", -78));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%d\n", -78));

	printf("sys-char_printed=%d\n", printf("%d\n", 0));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%d\n", 0));
	

	printf("sys-char_printed=%d\n", printf("%u\n", 420));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%u\n", 420));

	printf("sys-char_printed=%d\n", printf("%u\n", -420));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%u\n", -420));

	printf("sys-char_printed=%d\n", printf("%d\n", 2147483647));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%d\n", 2147483647));

	printf("sys-char_printed=%d\n", printf("%d\n", -2147483647));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%d\n", -2147483647));

	printf("sys-char_printed=%d\n", printf("%i\n", 23));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%i\n", 23));

	printf("sys-char_printed=%d\n", printf("%i\n", -78));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%i\n", -78));

	printf("sys-char_printed=%d\n", printf("%i\n", 0));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%i\n", 0));

	// case: test numbers with wrong speicifiersclear
	
	printf("sys-char_printed=%d\n", printf("%c\n", 12));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%c\n", 12));

	//case: output address of a pointer
	int n = 14;
	int *p = &n;

	printf("sys-char_printed=%d\n", printf("%p\n", p));
	ft_printf("own-char_printed=%d\n", ft_printf("%p\n", p));

	printf("sys-char_printed=%d\n", printf("%d\n", *p));
	ft_printf("own-char_printed=%d\n", ft_printf("%d\n", *p));

	printf("sys-char_printed=%d\n", printf("%p\n", NULL));
	ft_printf("own-char_printed=%d\n", ft_printf("%p\n", NULL));

	//test case: specifier: c
	printf("sys-char_printed=%d\n", printf("%c\n", 'A'));
	ft_printf("own-char_printed=%d\n", ft_printf("%c\n", 'A'));
	printf("sys-char_printed=%d\n", printf("%c\n", ' '));
	ft_printf("own-char_printed=%d\n", ft_printf("%c\n", ' '));
	printf("sys-char_printed=%d\n", printf("%c\n", 35));
	ft_printf("own-char_printed=%d\n", ft_printf("%c\n", 35));

	// test case: specifier s
	printf("sys-char_printed=%d\n", printf("%s\n", "hello"));
	ft_printf("own-char_printed=%d\n", ft_printf("%s\n", "hello"));
	printf("sys-char_printed=%d\n", printf("%s\n", ""));
	ft_printf("own-char_printed=%d\n", ft_printf("%s\n", ""));
	printf("sys-char_printed=%d\n", printf("%s\n", " "));
	ft_printf("own-char_printed=%d\n", ft_printf("%s\n", " "));

	// test case: specifer : x, X
	printf("sys-char_printed=%d\n", printf("%x\n", 20));
	ft_printf("own-char_printed=%d\n", ft_printf("%x\n", 20));
	printf("sys-char_printed=%d\n", printf("%x\n", 156));
	ft_printf("own-char_printed=%d\n", ft_printf("%x\n", 156));
	printf("sys-char_printed=%d\n", printf("%X\n", 58692));
	ft_printf("own-char_printed=%d\n", ft_printf("%X\n", 58692));
	
	// test case: output '%'
	printf("own-char_printed=%d\n", printf("a%%\n"));
	ft_printf("sys-char_printed=%d\n", ft_printf("a%%\n"));

	// // case: format = NULL, need compile them without flags
	// char *str;
	// printf("sys-char_printed=%d\n", printf(str));
	// ft_printf("own-char_printed=%d\n", ft_printf(str));

	// // case: *format = NULL, need compile them without flags
	// printf("own-char_printed=%d\n", printf(""));
	// ft_printf("sys-char_printed=%d\n", ft_printf(""));

	// // test case: there is no specifier after %.  need compile them without flags
	// printf("own-char_printed=%d\n", printf("a%k\n"));
	// ft_printf("sys-char_printed=%d\n", ft_printf("a%k\n"));

	return (0);
}