/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:43:52 by naali             #+#    #+#             */
/*   Updated: 2019/01/16 13:02:29 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_itoa_base.h"

#include <unistd.h>

char		*d_param(t_param *p)
{
	char	*nbr;

	if ((int)p->arg < 0)
		p->flags |= neg;
	nbr = convert_param_for_itoa(p, 10);
	return (nbr);
}

char		*i_param(t_param *p)
{
	char	*nbr;

	if ((int)p->arg < 0)
		p->flags |= neg;
	nbr = convert_param_for_itoa(p, 10);
	return (nbr);
}
