/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:46:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/13 18:56:22 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>
//#include "libft.h"
#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* unsigned int	ft_lenght_nbr(long long nbr, unsigned int base) */
/* { */
/* 	unsigned int	i; */

/* 	i = 0; */
/* 	if (!nbr) */
/* 		i = 1; */
/* 	while (nbr) */
/* 	{ */
/* 		nbr = nbr / base; */
/* 		i++; */
/* 	} */
/* 	return (i); */
/* } */

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

int main(void)
{
	int i = 0;
	int j = 0;
	int	a = 1;
	int	b = 2;
	int	c = 3;
	char	buf[100];
	char	*p;

	p = ft_ntoa_base(256, "0123456789abcdef", buf);
	printf("\np = %s\n", p);
	/* printf("---------------------------------------------------------\n"); */
	/* i = printf("%70p", &a); */
	/* printf("\nretour officiel   : %d\n", i); */
	/* fflush(stdout); */
 	/* j = ft_printf("%70p", &a); */
	/* printf("\nretour non officiel   : %d\n", j); */
	/* printf("---------------------------------------------------------\n"); */
}
