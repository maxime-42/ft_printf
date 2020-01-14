
#include "./include/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>
//#include "libft.h"
#include <stdlib.h>

static	long long ft_lenght_nb(long long n, long long size_base)
{
	long long length;

	length = (n <= 0) ? 1 : 0;
	while (n > 0 || n < 0)
	{
		n = n / size_base;
		length++;
	}
	return ((size_t)length);
}

char		*ft_ntoa_base(long long n, char *base, char *p)
{
	char		sign;
	size_t		length;
	long long	size_base;

	sign =  '\0';
	if (n < 0)
		sign = '-';
	size_base = (long long)ft_strlen(base);
	length = ft_lenght_nb(n, size_base);
	if (!p && !(p = malloc(sizeof(char) * (length + 1))))
		return (0);
	p[length] = '\0';
	while (length)
	{
		if (n < 0)
  			p[--length] = (base[(-(n) % size_base)]);
		else
			p[--length] = (base[(n % size_base)]);
		n = n / size_base;
	}
	if (sign)
		p[length] = sign;
	return (p);
}
