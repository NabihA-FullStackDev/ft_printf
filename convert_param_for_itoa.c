/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_param_for_itoa.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:04:35 by naali             #+#    #+#             */
/*   Updated: 2019/01/16 16:17:12 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_itoa_base.h"

char *ft_itoa_dbl(double n);

static void		init_nb(t_itoa *n, t_param *nb, int base)
{
	n->nb = nb;
	if (n->nb->type == 'X')
		n->base = BASEX;
	else
		n->base = BASEx;
	if (n->nb->type == 'x' || n->nb->type == 'X' || n->nb->type == 'p')
		n->szbs = 16;
	else if (n->nb->type == 'o')
		n->szbs = 8;
	else
		n->szbs = 10;
	n->szbs = base;
}

static char		*convert_f_param(t_itoa n)
{
	int			i;
	int			res;
	char		*tmp1;
	char		*tmp2;

	i = 0;
	printf("%s\n", ft_itoa_dbl(n.nb->dbl));
	res = (int)(n.nb->dbl / 1);
	n.nb->dbl = (n.nb->dbl - res) * 10;
	tmp1 = ft_itoa((int)res);
	tmp2 = tmp1;
	if (n.nb->apres != 0)
	{
		tmp1 = ft_strjoin(tmp1, ".");
		if (tmp2 != NULL)
			free(tmp2);
	}
	while (i < n.nb->apres && n.nb->apres != 0)
	{
		if (i == n.nb->apres - 1)
			res = ((n.nb->dbl + 0.5) / 1);
		else
			res = ((n.nb->dbl) / 1);
		if (res == 10 && i == n.nb->apres - 1)
			res = 0;
/* 		if (i == n.nb->apres - 1) */
/* 			res = ((n.nb->dbl + 0.5) / 1); */
/* 		else */
/* 			res = (n.nb->dbl / 1); */
		tmp2 = tmp1;
		tmp1 = ft_strjoin(tmp1, ft_itoa((int)res));
		if (tmp2 != NULL)
			free(tmp2);
		res = (n.nb->dbl / 1);
		n.nb->dbl = (n.nb->dbl - (int)res) * 10;
		i = i + 1;
	}
	return (tmp1);
}

char			*convert_param_for_itoa(t_param *nb, int base)
{
	t_itoa		n;

	init_nb(&n, nb, base);
	if (n.nb->type == 'd' || n.nb->type == 'i')
		return (ft_itoa_base((int)(n.nb->arg), &n, n.szbs));
	if (n.nb->type == 'p')
		return (ft_itoa_base_uns(n.nb->ui, &n, n.szbs));
	if (n.nb->type == 'u' || n.nb->type == 'x' || n.nb->type == 'X' || n.nb->type == 'o')
		return (ft_itoa_base_uns((unsigned int)n.nb->arg, &n, n.szbs));
	else if (n.nb->type == 'f')
		return (convert_f_param(n));
	return (NULL);
}
