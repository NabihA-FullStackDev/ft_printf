/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:15:46 by naali             #+#    #+#             */
/*   Updated: 2018/12/21 15:36:10 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*test(float f, unsigned int p)
{
//	char	*s;
	int		res;
	float	coma;
	unsigned int cp;

	cp = 0;
	(void)p;
	/*Suppression avant la virgule: calcul ok*/
	res = f / 1;
	printf("res = %d\n", res);
	coma = f - res;
	/**/
	printf("coma = %.7f\n", f);
	printf("coma = %.7f\n", coma);
	cp = (unsigned int)((coma * 10000) + 0.5);
	printf("cp = %u\n", cp);
	cp = (unsigned int)((coma * 1000000) + 0.5);
	printf("coma = %d\n", cp);
	return (NULL);
}

int main(void)
{
	float	f;
//	char	*s;

	f = 42.000501268479684324684751654f;
	test(f, 1);
	return (0);
}
