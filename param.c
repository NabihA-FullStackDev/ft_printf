/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:15:40 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/22 15:02:50 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

#include <stdio.h>

static void	init_param(t_param *param)
{
	param->type = 'N';
	param->flags = 0;
	param->avant = 0;
	param->apres = 0;
}

static void	get_everything(t_param *params, int curr_param,
		const char *format, int *i)
{
	while (get_flagopt(params + curr_param, format, i) != FALSE)
		;
	if (get_vals(params + curr_param, format, i) == TRUE)
		get_vals(params + curr_param, format, i);
	get_flaglen(params + curr_param, format, i);
	get_type(params + curr_param, format, i);
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
			get_everything(params, curr_param, format, &i);
			curr_param++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
			i += 2;
		else
			++i;
	}
	return (params);
}
