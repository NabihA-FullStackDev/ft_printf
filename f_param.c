/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:34:12 by naali             #+#    #+#             */
/*   Updated: 2019/01/16 13:03:12 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_itoa_base.h"

char		*fill_str(int size, char c)
{
	int		i;
	char	*str;

	i = 0;
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = c;
		i = i + 1;
	}
	str[i] = '\0';
	return (str);
}

void		prepare_flg(t_flgcheck *check, t_param *p, int size)
{
	int			dif;

	if (p->flags & plus)
		check->plus = '+';
	else
		check->plus = 0;
	if (p->flags & espace)
		check->blank = ' ';
	else
		check->blank = 0;
	if (size < p->avant)
	{
		if (p->flags & plus || p->flags & espace)
			dif = (p->avant - size) - 1;
		else
			dif = p->avant - size;
		check->space = fill_str(dif, ' ');
		check->zero = fill_str(dif, '0');
	}
	else
	{
		check->space = NULL;
		check->zero = NULL;
	}
}

void		free_all_useless(t_flgcheck *check, char **nbr)
{
	if (*nbr != NULL && check->tmp2 != NULL)
	{
		free(*nbr);
		*nbr = check->tmp2;
	}
	else
		*nbr = NULL;
	if (check->space != NULL)
		free(check->space);
	if (check->zero != NULL)
		free(check->zero);
	if (check->tmp1 != NULL)
		free(check->tmp1);
	if (check->tmp2 != NULL)
		check->tmp2 = NULL;
}

char		*check_flags(t_param *p, char *nbr, int size)
{
	t_flgcheck	check;

	prepare_flg(&check, p, size);
	if (p->flags & zero && !(p->flags & moins))
	{
		check.tmp1 = ft_strjoin(check.zero, nbr);
		if (p->flags & plus && !(p->flags & espace))
			check.tmp2 = ft_strjoin("+", check.tmp1);
		else if (p->flags & espace && !(p->flags & plus))
			check.tmp2 = ft_strjoin(" ", check.tmp1);
		else
			check.tmp2 = check.tmp1;
		check.tmp1 = NULL;
	}
	else if (!(p->flags & zero))
	{
		if (p->flags & plus && !(p->flags & espace))
			check.tmp1 = ft_strjoin("+", nbr);
		else if (p->flags & espace && !(p->flags & plus))
			check.tmp1 = ft_strjoin(" ", nbr);
		else
			check.tmp1 = NULL;
		if (p->flags & moins)
			check.tmp2 = ft_strjoin((check.tmp1 == NULL) ? nbr : check.tmp1, check.space);
		else
			check.tmp2 = ft_strjoin(check.space, (check.tmp1 == NULL) ? nbr : check.tmp1);
	}
	free_all_useless(&check, &nbr);
	return (nbr);
}

char		*f_param(t_param *p)
{
	char	*nbr;

	nbr = convert_param_for_itoa(p, 10);
	nbr = check_flags(p, nbr, ft_strlen(nbr));
	return (nbr);
}
