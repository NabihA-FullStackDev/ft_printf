/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:46:52 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/20 12:05:16 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

#include <unistd.h>
#include <stdio.h>

static void	swap_print_string(char *to_print, int *pos, const char *format)
{
	char *tmp;

	tmp = ft_strjoin(to_print, print_string(format, pos));
	free(to_print);
	to_print = tmp;
}

/*
** L'argument envoye a swap_print_param est deja l'element choisis
*/

static void	swap_print_param(char *to_print, int *pos, t_ctof *cf, t_param *p)
{
	char *tmp;

	tmp = ft_strjoin(to_print, print_param(cf, p, pos));
	free(to_print);
	to_print = tmp;
}

int			print_all(const char *format, t_ctof *ctof_tab, t_param *params)
{
	int		i;
	int		pos;
	int		nb_param;
	char	*to_print;
	int		size;

	i = 0;
	pos = 0;
	to_print = (char *)malloc(sizeof(char) * 1);
	to_print[0] = '\0';
	nb_param = get_nb_param(format);
	while (i < nb_param)
	{
		swap_print_string(to_print, &pos, format);
		swap_print_param(to_print, &pos, ctof_tab, params + i);
		++i;
	}
	swap_print_string(to_print, &pos, format);
	//free_ctof(ctof_tab);
	//free_param(params);
	size = ft_strlen(to_print);
	write(1, to_print, size);
	return (size);
}

int			ft_printf(const char *format, ...)
{
	t_ctof	*ctof_tab;
	t_param		*params;
	int		nb_param;
	int		i;
	va_list	ap;

	ctof_tab = create_ctof();
	params = create_param(format);
	nb_param = get_nb_param(format);
	i = 0;
	va_start(ap, format);
	while (i < nb_param)
	{
		params[i].arg = (void *)va_arg(ap, long long int);
		++i;
	}
	va_end(ap);
	return (print_all(format, ctof_tab, params));
	//return (0);
}
