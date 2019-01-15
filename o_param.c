/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:01:12 by naali             #+#    #+#             */
/*   Updated: 2019/01/15 09:01:25 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa_base.h"

char		*o_param(t_param *p)
{
	char	*nbr;

	nbr = convert_param_for_itoa(p, 8);
	if (p->apres < 3 && p->flags & hash)
		p->apres = 3;
	nbr = add_format(&nbr, p);
	return (nbr);
}
