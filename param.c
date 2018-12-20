/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:15:40 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/20 10:29:49 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

#include <stdio.h>

static void	init_param(t_param *param)
{
	param->hh = FALSE;
	param->h = FALSE;
	param->l = FALSE;
	param->ll = FALSE;
	param->L = FALSE;
	param->hash = FALSE;
	param->zero = FALSE;
	param->moins = FALSE;
	param->plus = FALSE;
	param->avant = -1;
	param->apres = -1;
	param->sans = -1;
}

int			get_nb_param(const char *format)
{
	int		i;
	int		nb_param;

	i = 0;
	nb_param = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] != '%')
				++nb_param;
		}
		++i;
	}
	return (nb_param);
}

t_param		*create_param(const char *format)
{
	int		i;
	int		nb_param;
	t_param	*params;
	int		curr_param;

	nb_param = get_nb_param(format);
	params = (t_param *)malloc(sizeof(t_param) * (nb_param + 1));
	i = 0;
	curr_param = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			++i;
			init_param(params + curr_param);
			params[curr_param].id = curr_param + 1;
			//get_flag1(params + curr_param, format, &i);
			//get_flag2(params + curr_param, format, &i);
			//get_vals(params + curr_param, format, &i);
			get_type(params + curr_param, format, &i);
		}
		if (format[i] == '%' && format[i + 1] == '%')
			++i;
		++i;
	}
	return (params);
}
