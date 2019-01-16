/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:21:48 by naali             #+#    #+#             */
/*   Updated: 2019/01/16 11:36:14 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_itoa_base.h"

char		*p_param(t_param *p)
{
	char	*nbr;

	write(2, "pp\n", 3);
	nbr = convert_param_for_itoa(p, 16);
	nbr = add_format(nbr, p);
	return (nbr);
}
