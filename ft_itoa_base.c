/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:55:29 by naali             #+#    #+#             */
/*   Updated: 2018/12/21 14:11:25 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "ft_itoa_base.h"

void		initialisation(t_getnb *n)
{
	n->i = 0;
	n->dbl = 0.0;
	n->flt = 0.0f;
}

t_getnb		init_nb(void *nb, unsigned int type)
{
	t_getnb		n;

	initialisation(&n);
	if (type & Tint)
		n.i = *((int*)nb);
	else if (type & Tdouble)
		n.dbl = *((double*)nb);
	else if (type & Tfloat)
		n.flt = *((float*)nb);
	return (n);
}

char		*ft_itoa_base(void *nb, unsigned int base, int type)
{
	t_getnb		n;
//	char		*ret;

	(void)base;
	n = init_nb(nb, type);
	if (type & Tint)
	{
		printf("%d\n", n.i);
		return ("int");
	}
	else if (type & Tdouble)
	{
		printf("%f\n", n.dbl);
		return ("double");
	}
	else if (type & Tfloat)
	{
		printf("%f\n", n.flt);
		return ("float");
	}
	return (NULL);
}

int			main(void)
{
	int		i;
	float	f;
	double	d;

	i = 42;
	f = 42.0f;
	d = 42.0;
	printf("%s\n", ft_itoa_base(&d, 10, 2));
	printf("i = %02147483644d, f = %.2f, d = %.3f\n", i/6, f, d);
	printf("i = %d, f = %.2f, d = %.3f\n", i, f, d);
	printf("#o = %#o\n", i);
	printf("#x = %#x\n", i);
	printf("#X = %#X\n", i);
	printf("' 'o = % o\n", i);
	printf("' 'x = % x\n", i);
	printf("' 'X = % X\n", i);
	return (0);
}
