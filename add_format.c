/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:34:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/14 16:27:20 by jucapik          ###   ########.fr       */
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

static char	*case1(char **nbr, t_param *p, int size, int c)
{
	char	*tofill;
	char	*tmp;
	int		big;
	int		i;

	big = (p->apres > p->avant) ? p->apres : p->avant;
	if (p->flags & neg || p->flags & plus || p->flags & espace)
		++big;
	tofill = (char *)malloc(sizeof(char) * (big - size + 1));
	i = 0;
	if (c == '0')
		signe(tofill, &i, p);
	while (i < big - size - 1)
		tofill[i++] = c;
	if (c == ' ' && signe(tofill, &i, p) == FALSE)
		tofill[i++] = ' ';
	else
		tofill[i++] = c;
	tofill[i] = '\0';
	tmp = ft_strjoin(tofill, *nbr);
	ft_memdel((void **)&tofill);
	ft_memdel((void **)nbr);
	return (tmp);
}

static char	*case2(char **nbr, t_param *p, int size)
{
	char	*tofill;
	char	*tmp;
	int		i;

	tofill = (char *)malloc(sizeof(char) * (p->avant - size + 1));
	i = 0;
	while (i < p->avant - p->apres - 1)
		tofill[i++] = ' ';
	if (signe(tofill, &i, p) == FALSE)
		tofill[i++] = ' ';
	while (i < p->avant - size)
		tofill[i++] = '0';
	tofill[i] = '\0';
	tmp = ft_strjoin(tofill, *nbr);
	ft_memdel((void **)&tofill);
	ft_memdel((void **)nbr);
	return (tmp);
}

char		*add_signe(char **nbr, t_param *p, int size)
{
	char	*tofill;
	int		i;

	i = (p->flags & neg || p->flags & plus || p->flags & espace) ? 1 : 0;
	if (i == 1)
	{
		tofill = ft_strnew(size + 1);
		i = 0;
		signe(tofill, &i, p);
		ft_strcpy(tofill + 1, *nbr);
		ft_memdel((void **)nbr);
		ft_putstr("11:");
		ft_putendl(tofill);
		return (tofill);
	}
	else
		return (*nbr);
}

char		*add_format(char **nbr, t_param *p)
{// TODO ne pas envoyer un nombre avec '-' mais activer le flag p->neg
	int		size;

	size = ft_strlen(*nbr);
	//printf("avant = %d, apres = %d\n", p->avant, p->apres);
	ft_putstr("1:");
	ft_putendl(*nbr);
	if (!(p->flags & moins))
	{
		if (p->apres >= p->avant && p->apres > size)
			(*nbr) = case1(nbr, p, size, '0');
		else if (p->avant > p->apres && p->apres > size)
			(*nbr) = case2(nbr, p, size);
		else if (p->avant > size)
			(*nbr) = case1(nbr, p, size, ' ');
		else
			(*nbr) = add_signe(nbr, p, size);
		ft_putstr("2:");
		ft_putendl(*nbr);
	}
	else
	{
		add_format_helper(nbr, p, size);
		//ft_putstr("3: ");
		//ft_putendl(*nbr);
	}
	return (*nbr);
}
