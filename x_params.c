/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_params.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:26:19 by naali             #+#    #+#             */
/*   Updated: 2019/01/16 13:02:59 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa_base.h"
#include <unistd.h>

char		*x_param(t_param *p)
{
	char	*nbr;

	nbr = convert_param_for_itoa(p, 16);
	return (nbr);
}

char		*X_param(t_param *p)
{
	char	*nbr;

	nbr = convert_param_for_itoa(p, 16);
	return (nbr);
}
