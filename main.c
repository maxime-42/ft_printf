/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:46:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/14 17:49:02 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>
//#include "libft.h"
#include <stdlib.h>


int main(void)
{
	int i = 0;
	int j = 0;
	int	a = 1;
	int	b = 2;
	int	c = 3;

	printf("---------------------------------------------------------\n");
	i = printf("%-70p", &a);
	printf("\nretour officiel   : %d\n", i);
	fflush(stdout);
/*  	j = ft_printf("%70p", &a); */
/* 	printf("\nretour non officiel   : %d\n", j); */
	(void)i;
	(void)j;
	(void)a;
	(void)c;
	(void)b;
	printf("---------------------------------------------------------\n");
}
