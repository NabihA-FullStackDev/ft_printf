/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 12:04:21 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/21 10:28:25 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	get_flag1(t_param *param, const char *format, int *i)
{
	if (format[*i] == 'h' && format[(*i) + 1] == 'h')
	{
		param->hh = TRUE;
		(*i) += 2;
	}
	else if (format[*i] == 'h')
	{
		param->h = TRUE;
		(*i) += 1;
	}
	else if (format[*i] == 'l')
	{
		param->l = TRUE;
		(*i) += 1;
	}
	else if (format[*i] == 'l' && format[(*i) + 1] == 'l')
	{
		param->ll = TRUE;
		(*i) += 2;
	}
	else if (format[*i] == 'L')
	{
		param->L = TRUE;
		(*i) += 1;
	}
}

void	get_flag2(t_param *param, const char *format, int *i)
{
	if (format[*i] == '#')
	{
		param->hash = TRUE;
		(*i) += 1;
	}
	if (format[*i] == '0')
	{
		param->zero = TRUE;
		(*i) += 1;
	}
	if (format[*i] == '-')
	{
		param->moins = TRUE;
		(*i) += 1;
	}
	if (format[*i] == '+')
	{
		param->plus = TRUE;
		(*i) += 1;
	}
	if (format[*i] == ' ')
	{
		param->espace = TRUE;
		(*i) += 1;
	}
}	// Probably going to have to change this function,
	// there can be more than one at a time of these parameters TODO

void	get_vals(t_param *param, const char *format, int *i)
{
	int		val;
	int		check;

	check = 0;
	if (format[*i] == '.')
	{
		++i;
		check = 1;
	}
	if (format[*i] >= '1' && format[*i] <= '9')
		val = ft_atoi(format + (*i));
	while (format[*i] >= '0' && format[*i] <= '9')
		++(*i);
	if (check == 1)
		param->avant = val;
	if (format[*i] == '.')
	{
		check = 2;
		++i;
	}
	if (format[*i] >= '1' && format[*i] <= '9')
		val = ft_atoi(format + (*i));
	while (format[*i] >= '0' && format[*i] <= '9')
		++(*i);
	//PAS FINIS, la logique est pas bonne	
}

void	get_type(t_param *param, const char *format, int *i)
{
	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p' ||
			format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'o' ||
			format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X' ||
			format[*i] == 'f')
		param->type = format[*i];
}
