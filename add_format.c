/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:34:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/10 11:55:53 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*case1(char *nbr, t_param *p, int size)
{
	char *zeros;
	char *tmp;

	zeros = (char *)malloc(sizeof(char) * (p->apres - size + 1));
	i = -1;
	while (++i < p->apres - size)
		zeros[i] = '0';
	zeros[i] = '\0';
	tmp = ft_strjoin(zeros, nbr);
	ft_memdel(&zeros);
	ft_memdel(&nbr);
	return (tmp);
}

static char	*case2(char *nbr, t_param *p, int size)
{
	char *tofill;
	char *tmp;

	tofill = (char *)malloc(sizeof(char) * (

static void	signe(char *nbr, t_param *p)
{
	char *tmp;

	if (p->flags & plus)
	{
		tmp = ft_strjoin("+", nbr);
		ft_memdel(&nbr);
		nbr = tmp;
	}
	else if (p->flags & plus)
	{
		tmp = ft_strjoin(" ", nbr);
		ft_memdel(&nbr);
		nbr = tmp;
	}
}

char		*add_format(char *nbr, t_param *p)
{
	int		size;
	int		i;

	size = ft_strlen(nbr);
	if ((p->flags & plus || p->flags & espace) && nbr[0] != '-')
		signe(nbr, p);
	if (!(p->flags & moins))
	{
		if (p->apres > p->avant && p->apres > size)
			return (case1(nbr, p, size);
		else if (p->avant > p->apres && p->apres > size)
			return (case2(nbr, p, size));

