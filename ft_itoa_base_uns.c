/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:09:12 by naali             #+#    #+#             */
/*   Updated: 2019/01/09 15:45:58 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_itoa_base.h"

static void		get_nb_size_uns(t_ulli nb, t_ulli *mod, int *size, t_ulli base)
{
	*mod = 1;
	*size = 1;
	while (nb > (base - 1))
	{
		nb = nb / base;
		*mod = *mod * base;
		*size = *size + 1;
	}
}

static char		*convert_nb_uns(t_ulli nb, t_itoa *t, t_ulli base, char *b)
{
	int			i;
	char		*n;

	i = 0;
	if ((n = (char*)malloc(sizeof(char) * (t->size + t->signe + 1))) == NULL)
		return (NULL);
	while (t->umod > 0)
	{
		n[i] = b[(nb / t->umod)];
		nb = nb % t->umod;
		t->umod = t->umod / base;
		i = i + 1;
	}
	n[i] = '\0';
	return (n);
}

char			*ft_itoa_base_uns(t_ulli nb, t_itoa *tools, t_ulli base)
{
	char	*nbr;

	tools->signe = 0;
	get_nb_size_uns(nb, &(tools->umod), &(tools->size), base);
	if (tools->nb->type == 'X')
		nbr = convert_nb_uns(nb, tools, base, BASEX);
	else
		nbr = convert_nb_uns(nb, tools, base, BASEx);
	return (nbr);
}
