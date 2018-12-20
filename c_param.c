/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:14:05 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/20 15:22:43 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

char	*c_param(t_param *param)
{
	char	c;
	char	*ret;

	c = (char)param->arg;
	ret = (char *)malloc(sizeof(char) * 2);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
