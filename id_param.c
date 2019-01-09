/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:43:52 by naali             #+#    #+#             */
/*   Updated: 2019/01/07 14:18:46 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa_base.h"

char		*d_param(t_param *p)
{
	char	*nbr;

	nbr = convert_param_for_itoa(p, 10);
	return (nbr);
}

char		*i_param(t_param *p)
{
	char	*nbr;

	nbr = convert_param_for_itoa(p, 10);
	return (nbr);
}
