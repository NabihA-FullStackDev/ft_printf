/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:53:20 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/02 09:23:52 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

char	*s_param(t_param *param)
{
	char	*s;

	if (param->arg == NULL)
		return (ft_strdup("(null)"));
	s = (char *)param->arg;
	return (ft_strdup(s));
}
