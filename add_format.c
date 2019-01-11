/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:34:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/11 09:44:36 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	case1(char **nbr, t_param *p, int size, int c)
{
	char *zeros;
	char *tmp;

	zeros = (char *)malloc(sizeof(char) * (p->apres - size + 1));
	i = -1;
	while (++i < p->apres - size)
		zeros[i] = c;
	zeros[i] = '\0';
	tmp = ft_strjoin(zeros, nbr);
	ft_memdel(&zeros);
	ft_memdel(nbr);
	return (tmp);
}

static void	case2(char **nbr, t_param *p, int size)
{
	char	*tofill;
	char	*tmp;
	int		i;

	tofill = (char *)malloc(sizeof(char) * (p->avant - size + 1));
	i = -1;
	while (++i < p->avant - p->apres)
		tofill[i] = ' ';
	while (++i < p->avant - size)
		tofill[i] = '0';
	tofill[i] = '\0';
	tmp = ft_strjoin(tofill, nbr);
	ft_memdel(&tofill);
	ft_memdel(nbr);
	return (tmp);
}

static void	signe(char *nbr, t_param *p)
{
	char *tmp;

	if (p->flags & plus)
	{
		tmp = ft_strjoin("+", nbr);
		ft_memdel(nbr);
		nbr = tmp;
	}
	else if (p->flags & plus)
	{
		tmp = ft_strjoin(" ", nbr);
		ft_memdel(nbr);
		nbr = tmp;
	}
}

void		add_format(char **nbr, t_param *p)
{
	int		size;
	int		i;

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
	if ((p->flags & plus || p->flags & espace) && nbr[0] != '-')
		signe(nbr, p);
}
