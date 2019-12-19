/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:46:47 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/19 17:18:24 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>


/* int	main(int ac, char **av) */
/* { */
/*  	int	ft = 0; */
/* 	int	libc = 0; */
/*  	double n = 2501; */

/* 	char *s = setlocale(LC_NUMERIC , "fr_FR.UTF-8"); */

/* 	ft = ft_printf("salut\n"); */
/* 	libc = printf("salut\n"); */
/* 	printf("ft_  = %d | libc = %d\n", ft, libc); */
/* 	(void)n; */
/* 	(void)s; */
/* 	(void)av; */
/* 	(void)ac; */
/* 	(void)libc; */
/* 	(void)ft; */
/* 	return (0); */
/* } */

int main(void)
{
	int i = 0;
	int j = 0;

	i = printf("%05%");
	printf("\nretour officiel   : %d\n", i);
	fflush(stdout);
	j =  ft_printf("%05%");
	printf("\nretour non officiel   : %d\n", j);
}
