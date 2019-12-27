/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:46:47 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/27 16:14:53 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>


int main(void)
{
	int i = 0;
	int j = 0;

	printf("---------------------------------------------------------\n");
	i = printf("%10.3s", "hello");
	printf("\nretour officiel   : %d\n", i);
	fflush(stdout);
/* 	j =  ft_printf("%s", "hello"); */
/* 	printf("\nretour non officiel   : %d\n", j); */
	printf("---------------------------------------------------------\n");
}
