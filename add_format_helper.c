/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:06:56 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/11 16:37:23 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static char	*case1(char *nbr, int big)
{
	char	*tmp;
	char	*tofill;
	int		i;

	tofill = ft_strnew(big);
	i = 0;
	signe(tofill, &i, p);
	while (i < big)
		tofill[i++] = '0';
	tmp = ft_strjoin(tofill, nbr);
	ft_memdel(tofill);
	ft_memdel(nbr);
	return (tmp);
}

static char *case2(char *nbr, int big, t_param *p)
{
	char	*tmp;
	char	*tofill;
	int		size;
	int		i;

	size = p->avant - big;
	tofill = ft_strnew(size);
	i = -1;
	while (++i < size)
		tofill[i] = ' ';
	tmp = ft_strjoin(nbr, tofill);
	ft_memdel(tofill);
	ft_memdel(nbr);
	return (tmp);
}


char		*add_format_helper(char *nbr, t_param *p, int size)
{
	char	*tmp;
	int		big;

	big = p->apres - size;
	big += (p->flags & neg || p->flags & plus || p->flags & espace) ? 1 : 0;
	if (big > 0)
		nbr = case1(nbr, big);
	big = ft_strlen(nbr);
	if (p->avant > big)
		nbr = case2(nbr, big, p);
	return (nbr);
}
