/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_params.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:26:19 by naali             #+#    #+#             */
/*   Updated: 2019/01/15 09:37:47 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa_base.h"

char		*x_param(t_param *p)
{
	char	*nbr;

	nbr = convert_param_for_itoa(p, 16);
	nbr = add_format(&nbr, p);
	return (nbr);
}

char		*X_param(t_param *p)
{
	char	*nbr;

	nbr = convert_param_for_itoa(p, 16);
	nbr = add_format(&nbr, p);
	return (nbr);
}
