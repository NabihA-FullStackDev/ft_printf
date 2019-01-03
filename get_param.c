/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 12:04:21 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/03 17:06:03 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

void			get_flaglen(t_param *param, const char *format, int *i)
{
	if (format[*i] == 'h' && format[(*i) + 1] == 'h')
	{
		param->flags |= hh;
		(*i) += 1;
	}
	else if (format[*i] == 'h')
		param->flags |= h;
	else if (format[*i] == 'l' && format[(*i) + 1] == 'l')
	{
		param->flags |= ll;
		(*i) += 1;
	}
	else if (format[*i] == 'l')
		param->flags |= l;
	else if (format[*i] == 'L')
		param->flags |= L;
	else
		--(*i);
	++(*i);
}

bln				get_flagopt(t_param *param, const char *format, int *i)
{
	bln ret;

	ret = TRUE;
	if (format[*i] == '#')
		param->flags |= hash;
	else if (format[*i] == '0')
	{
		if (!(param->flags & moins))
			param->flags |= zero;
	}
	else if (format[*i] == '-')
	{
		param->flags &= ~zero;
		param->flags |= moins;
	}
	else if (format[*i] == '+')
	{
		param->flags &= ~espace;	
		param->flags |= plus;
	}
	else if (format[*i] == ' ')
	{
		if (param->type != 'p' && !(param->flags & plus))
			param->flags |= espace;
	}
	else
	{
		--(*i);
		ret = FALSE;
	}
	++(*i);
	return (ret);
}

bln				get_vals(t_param *param, const char *format, int *i)
{
	bln ret;

	ret = TRUE;
	if (format[*i] == '.' && format[(*i) + 1] >= '0' && format[(*i) + 1] <= '9')
	{
		++(*i);
		param->apres = ft_atoi(format + (*i));
		while (format[*i] >= '0' && format[*i] <= '9')
			++(*i);
	}
	else if ((format[*i] >= '0' && format[*i] <= '9'))
	{
		param->avant = ft_atoi(format + (*i));
		if (param->flags & moins)
			param->avant *= -1;
		while ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '-')
			++(*i);
	}
	else
		ret = FALSE;
	return (ret);
}

bln		checkwholenum(t_param *param)
{
	if (param->type == 'd' || param->type == 'i' || param->type == 'o' ||
			param->type == 'u' || param->type == 'x' || param->type == 'X')
		return (TRUE);
	return (FALSE);
}

bln				get_type(t_param *param, const char *format, int *i)
{
	bln ret;

	ret = TRUE;
	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p' ||
			format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'o' ||
			format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X' ||
			format[*i] == 'f')
		param->type = format[*i];
	else
	{
		param->type = '\0';
		ret = FALSE;
	}
	// a ajouter quand les options d,i,o... sont ajoutes TODO
	//if (checkwholenum(param) == TRUE && param->avant != 0)
	//	param->flags &= ~zero;
	++(*i);
	return (ret);
}
