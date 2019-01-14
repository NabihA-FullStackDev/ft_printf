/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:43:52 by naali             #+#    #+#             */
/*   Updated: 2019/01/14 13:46:22 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa_base.h"

char		*d_param(t_param *p)
{
	int		signe;
	char	*nbr;

	if ((int)p->arg < 0)
		signe = 1;
	nbr = convert_param_for_itoa(p, 10);
	return (nbr);
}

char		*i_param(t_param *p)
{
	int		signe;
	char	*nbr;

	if ((int)p->arg < 0)
		signe = 1;
	nbr = convert_param_for_itoa(p, 10);
	return (nbr);
}
