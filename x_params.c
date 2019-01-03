/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_params.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:26:19 by naali             #+#    #+#             */
/*   Updated: 2019/01/03 17:27:55 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa_base.h"

char		*x_param(t_param *p)
{
	char	*nbr;

	nbr = ft_itoa_base(p, 16);
	return (nbr);
}

char		*X_param(t_param *p)
{
	char	*nbr;

	nbr = ft_itoa_base(p, 16);
	return (nbr);
}
