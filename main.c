/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:46:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 13:08:29 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>
//#include "libft.h"
#include <stdlib.h>
#include <limits.h>

int main(void)
{
	int i = 0;
	int j = 0;
	int	a = 1;
	int	b = 2;
	int	c = 3;

	printf("---------------------------------------------------------\n");
/* 	i = printf("%0-7i\n", -54); */
	printf("%0*i\n", -7, -54); 
	//i = printf("%-05d\n", 12);
	printf("\nretour officiel   : %d\n", i);
	fflush(stdout);
	j = ft_printf("%0*i", -7, -54);
	printf("\nretour non officiel   : %d\n", j);
	(void)i;
	(void)j;
	(void)a;
	(void)c;
	(void)b;
	printf("---------------------------------------------------------\n");
}
