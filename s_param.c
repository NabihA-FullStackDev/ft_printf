/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:53:20 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/20 12:53:35 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

char	*s_param(t_param *param)
{
	char	**s;

	s = (char **)param->arg;
	return (*s);
}
