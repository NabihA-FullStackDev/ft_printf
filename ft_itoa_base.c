/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:55:29 by naali             #+#    #+#             */
/*   Updated: 2019/01/14 13:43:41 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_itoa_base.h"

static void		get_nb_size(t_lli nb, t_lli *mod, int *size, t_lli base)
{
	*mod = 1;
	*size = 1;
	while (nb < -(base - 1))
	{
		nb = nb / base;
		*mod = *mod * base;
		*size = *size + 1;
	}
}

static char		*convert_nb(int nb, t_itoa *t, t_lli base, char *b)
{
	int			i;
	char		*n;

	i = 0;
	if ((n = (char*)malloc(sizeof(char) * (t->size + t->signe + 1))) == NULL)
		return (NULL);
/* 	if (t->signe == 1) */
/* 	{ */
/* 		n[i] = '-'; */
/* 		i = i + 1; */
/* 	} */
	while (t->smod > 0)
	{
		n[i] = b[((nb / t->smod) * (-1))];
		nb = nb % t->smod;
		t->smod = t->smod / base;
		i = i + 1;
	}
	n[i] = '\0';
	return (n);
}
char			*ft_itoa_base(t_lli nb, t_itoa *tools, t_lli base)
{
	char	*nbr;

	tools->signe = 0;
	if (nb >= 0)
		nb = nb * (-1);
/* 	else */
/* 		tools->signe = 1; */
	get_nb_size(nb, &(tools->smod), &(tools->size), base);
	if (tools->nb->type == 'X')
		nbr = convert_nb(nb, tools, base, BASEX);
	else
		nbr = convert_nb(nb, tools, base, BASEx);
	return (nbr);
}
