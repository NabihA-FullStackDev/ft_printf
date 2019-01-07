/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:55:29 by naali             #+#    #+#             */
/*   Updated: 2019/01/07 12:16:20 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_itoa_base.h"

void		init_nb(t_itoa *n, t_param *nb, int base)
{
	n->nb = nb;
	if (n->nb->type == 'X')
		n->base = BASEX;
	else
		n->base = BASEx;
	if (n->nb->type == 'x' || n->nb->type == 'X')
		n->szbs = 16;
	else if (n->nb->type == 'o')
		n->szbs = 8;
	else
		n->szbs = 10;
	n->szbs = base;
}

char		*convert_param_for_itoa(t_param *nb, int base)
{
	t_itoa		n;

	init_nb(&n, nb, base);
	if (n.nb->type == 'd' || n.nb->type == 'i' || n.nb->type == 'x' || n.nb->type == 'X')
	{
		printf("printf %d\n", (int)(n.nb->arg));
		return (ft_itoa_base((int)(n.nb->arg), &n, n.szbs));
	}
	else if (n.nb->type == 'f')
	{
		printf("printf %f\n", n.nb->dbl);
		return (ft_strdup("double"));
	}
	return (NULL);
}

static void		get_nb_size(int nb, int *mod, int *size, int base)
{
	while (nb < -(base - 1))
	{
		nb = nb / base;
		*mod = *mod * base;
		*size = *size + 1;
	}
}

static char		*convert_nb(int nb, t_itoa *t, int base, char *b)
{
	int			i;
	char		*n;

	i = 0;
	if ((n = (char*)malloc(sizeof(char) * (t->size + t->signe + 1))) == NULL)
		return (NULL);
	if (t->signe == 1)
	{
		n[i] = '-';
		i = i + 1;
	}
	while (t->mod > 0)
	{
		n[i] = b[((nb / t->mod) * (-1))];
		nb = nb % t->mod;
		t->mod = t->mod / base;
		i = i + 1;
	}
	n[i] = '\0';
	return (n);
}

char			*ft_itoa_base(int nb, t_itoa *tools, int base)
{
	char	*nbr;

	tools->mod = 1;
	tools->signe = 0;
	tools->size = 1;
	nbr = NULL;
	if (nb >= 0)
		nb = nb * (-1);
	else
		tools->signe = 1;
	get_nb_size(nb, &(tools->mod), &(tools->size), base);
	if (tools->nb->type == 'X')
		nbr = convert_nb(nb, tools, base, BASEX);
	else
		nbr = convert_nb(nb, tools, base, BASEx);
	return (nbr);
}
