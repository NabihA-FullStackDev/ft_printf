/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:34:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/11 16:37:22 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	case1(char *nbr, t_param *p, int size, int c)
{
	char	*tofill;
	char	*tmp;
	int		big;

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
	tofill[i] = '\0';
	tmp = ft_strjoin(tofill, nbr);
	ft_memdel(&tofill);
	ft_memdel(&nbr);
	return (tmp);
}

static void	case2(char *nbr, t_param *p, int size)
{
	char	*tofill;
	char	*tmp;
	int		i;

	tofill = (char *)malloc(sizeof(char) * (p->avant - size + 1));
	i = -1;
	while (++i < p->avant - p->apres - 1)
		tofill[i] = ' ';
	if (signe(tofill, &i, p) == FALSE)
		tofill[i++] = ' ';
	while (++i < p->avant - size)
		tofill[i] = '0';
	tofill[i] = '\0';
	tmp = ft_strjoin(tofill, nbr);
	ft_memdel(&tofill);
	ft_memdel(&nbr);
	return (tmp);
}

bln			signe(char *tofill, int *i, t_param *p)
{
	char *tmp;

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

void		add_format(char *nbr, t_param *p)
{// TODO ne pas envoyer un nombre avec '-' mais activer le flag p->neg
	int		size;
	int		i;
	bln		negpos;

	size = ft_strlen(nbr);
	if (!(p->flags & moins))
	{
		if (p->apres > p->avant && p->apres > size)
			case1(nbr, p, size, '0');
		else if (p->avant > p->apres && p->apres > size)
			case2(nbr, p, size);
		else if (p->avant > size)
			case1(nbr, p, size, ' ');
	}
	else
		add_format_helper(nbr, p, size);
	return (nbr);
}
