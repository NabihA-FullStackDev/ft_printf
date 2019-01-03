/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:55:29 by naali             #+#    #+#             */
/*   Updated: 2019/01/03 17:59:30 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_itoa_base.h"

/*t_itoa*/void		init_nb(t_itoa *n, t_param *nb, unsigned int base)
{
//	t_itoa	n;

	n->nb = nb;
	if (n->nb->type == 'X')
		n->base = BASEX;
	else
		n->base = BASEx;
	n->szbs = base;
//	return (n);
}

char		*ft_itoa_base(t_param *nb, unsigned int base)
{
	t_itoa		n;

	init_nb(&n, nb, base);
	if (n.nb->type == 'd' || n.nb->type == 'i' || n.nb->type == 'x' || n.nb->type == 'X')
	{
		printf("%d\n", (int)(n.nb->arg));
		return (ft_strdup("int"));
	}
	else if (n.nb->type == 'f')
	{
		printf("%f\n", *((double*)(n.nb->arg)));
		return (ft_strdup("double"));
	}
	return (NULL);
}
