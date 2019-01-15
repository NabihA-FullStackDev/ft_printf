/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:34:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/15 14:16:13 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

bln			signe(char *tofill, int *i, t_param *p)
{
	if (p->flags & neg)
		tofill[(*i)++] = '-';
	else if (p->flags & plus)
		tofill[(*i)++] = '+';
	else if (p->flags & espace)
		tofill[(*i)++] = ' ';
	else
		return (FALSE);
	return (TRUE);
}

static char	*case2(char **nbr, t_param *p, int size)
{
	char	*tofill;
	char	*tmp;
	int		big;
	int		check;
	int		i;

	big = (p->apres > p->avant) ? p->apres - size : p->avant - size;
	check = ((p->type == 'x' || p->type == 'X') && p->flags & hash) ? 2 : 0;
	big += check;
	printf("big = %d, size = %d\n", big, size);
	tofill = ft_strnew(big - size + 1);
	i = 0;
	if (p->avant > p->apres)
		while (i < p->avant - p->apres - 2 && i < p->avant - size - 2)
			tofill[i++] = ' ';
	if ((p->type == 'x' || p->type == 'X') && p->flags & hash)
	{
		tofill[i++] = '0';
		tofill[i++] = (p->type == 'x') ? 'x' : 'X';
	}
	else if (p->avant > p->apres)
	{
		tofill[i++] = ' ';
		if (signe(tofill, &i, p) == FALSE)
			tofill[i++] = ' ';
	}
	while (i < p->apres - size + check)
		tofill[i++] = '0';
	tofill[i] = '\0';
	printf("i = %d, tofill = %s\n", i, tofill);
	tmp = ft_strjoin(tofill, *nbr);
	ft_memdel((void **)&tofill);
	ft_memdel((void **)nbr);
	return (tmp);
}

char		*add_format(char **nbr, t_param *p)
{
	int		size;

	size = ft_strlen(*nbr);
	if (!(p->flags & moins))
	{
		if (p->avant > 0 || p->apres > 0)
			(*nbr) = case2(nbr, p, size);
		else
			(*nbr) = add_signe(nbr, p, size);
	}
	else
		add_format_helper(nbr, p, size);
	return (*nbr);
}
