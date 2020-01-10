/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:46:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/10 17:46:06 by mkayumba         ###   ########.fr       */
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
	i = printf("%5p", NULL);
	printf("\nretour officiel   : %d\n", i);
	fflush(stdout);
	j =  ft_printf("%5p", NULL);
	printf("\nretour non officiel   : %d\n", j);
	printf("---------------------------------------------------------\n");
}
