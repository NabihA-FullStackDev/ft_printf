/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:34:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/16 13:02:01 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

char	*add_zeros(char *nbr, t_param *p, int *size)
{
	char	*tofill;
	char	*tmp;
	int		nbz;
	int		i;

	i = 0;
	if (p->flags & zero && !(p->flags & moins)
			&& p->apres == -1 && p->avant > *size)
		nbz = p->avant - *size;
	else if (p->apres > *size)
		nbz = p->apres - *size;
	else
		return (nbr);
	tofill = ft_strnew(nbz);
	while (i < nbz)
		tofill[i++] = '0';
	tofill[i] = '\0';
	tmp = ft_strjoin(tofill, nbr);
	ft_memdel((void **)&nbr);
	ft_memdel((void **)&tofill);
	*size += nbz;
	return (tmp);
}// TODO where is the segfault with %04d

char	*add_type(char *nbr, t_param *p)
{
	char	*tofill;
	char	*tmp;

	tofill = ft_strnew(2);
	tofill[0] = '0';
	if ((p->type == 'x' || p->type == 'X') && p->flags & hash)
	{
		tofill[1] = (p->type == 'x') ? 'x' : 'X';
		tofill[2] = '\0';
	}
	else if (p->flags & hash && p->type == 'o')
		tofill[1] = '\0';
	else
		return (nbr);
	tmp = ft_strjoin(tofill, nbr);
	ft_memdel((void **)&nbr);
	ft_memdel((void **)&tofill);
	return (tmp);
}

char		*add_format(char *nbr, t_param *p)
{
	int		size;

	size = ft_strlen(nbr);
	nbr = add_zeros(nbr, p, &size);
	//nbr = add_type(nbr, p);
	//nbr = add_spaces(nbr, p, size);
	(void)p;
	return (nbr);
}
