/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:15:46 by naali             #+#    #+#             */
/*   Updated: 2019/01/03 14:14:18 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*test(double f, unsigned int p)
{
//	char	*s;
	int		i;
	int		res;
//	double	coma;
	unsigned int cp;

	cp = 0;
	(void)p;
	i = 0;
//	printf("dans test f = %.100f\n", f);
	while (i != 20)
	{
		res = f / 1;
		f = f - res;
		printf("%d: test f = %1.0f\n", i, f);
		i++;
		f = f * 10;
	}
	/*Suppression avant la virgule: calcul ok*/
/* 	res = f / 1; */
/* 	printf("res = %d\n", res); */
/* 	coma = f - res; */
	/**/
/* 	printf("f = %.7f\n", f); */
/* 	printf("coma = %.7f\n", coma); */
/* 	cp = (unsigned int)((coma * 10000)); */
/* 	printf("cp = %u\n", cp); */
/* 	coma = coma - ((double)cp / 10000); */
/* 	cp = (unsigned int)((coma * 1000000)); */
/* 	printf("cp = %d\n", cp); */
/* 	printf("coma = %.7f\n", coma); */
	return (NULL);
}

int main(void)
{
	double	f1;
/*	double	f2;
	double	f3;*/
//	char	*s;

	f1 = 0;
//	printf("1 dans main f1 = %.100f\n", f1);
	test(f1, 1);
/*	f2 = 0.000000000000004324684751654;
	printf("2 dans main f2 = %.100f\n", f2);
	test(f2, 1);
	f3 = 0.2048;
	printf("3 dans main f3 = %.100f\n", f3);
	test(f3, 1);*/
	return (0);
}
