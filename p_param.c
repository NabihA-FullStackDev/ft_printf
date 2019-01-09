/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:21:48 by naali             #+#    #+#             */
/*   Updated: 2019/01/09 15:53:25 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_itoa_base.h"

char		*p_param(t_param *p)
{
	char	*ret;
	char	*nbr;

	nbr = convert_param_for_itoa(p, 16);
	ret = ft_strjoin("0x", nbr);
	if (nbr != NULL)
		free(nbr);
	return (ret);
}
