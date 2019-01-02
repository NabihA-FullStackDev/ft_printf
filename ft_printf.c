/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:46:52 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/02 11:33:31 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

#include <unistd.h>
#include <stdio.h>

static void	swap_print_string(char **to_print, int *pos, const char *format)
{
	char *tmp;
	char	*ps;

	ps = print_string(format, pos);
	tmp = ft_strjoin(*to_print, ps);
	free(*to_print);
	free(ps);
	*to_print = tmp;
}

/*
** L'argument envoye a swap_print_param est deja l'element choisis
*/

static void	swap_print_param(char **to_print, t_ctof *cf, t_param *p)
{
	char	*tmp;
	char	*pp;

	pp = print_param(cf, p);
	if (pp != NULL)
	{
		tmp = ft_strjoin(*to_print, pp);
		free(*to_print);
		*to_print = tmp;
	}
	free(pp);
}

int			modif_pos(int pos, const char *format)
{
	while (format[pos] != 'c' && format[pos] != 's' && format[pos] != 'p' &&
			format[pos] != 'd' && format[pos] != 'i' && format[pos] != 'o' &&
			format[pos] != 'u' && format[pos] != 'x' && format[pos] != 'X' &&
			format[pos] != 'f' && format[pos] != '\0')
		++pos;
	++pos;
	return (pos);
}

/*static void TESTFUN(t_param *param)
{
	if (param->flags & hh)
		printf("hh options up for %d\n", param->id);
	if (param->flags & h)
		printf("h options up for %d\n", param->id);
	if (param->flags & ll)
		printf("ll options up for %d\n", param->id);
	if (param->flags & l)
		printf("l options up for %d\n", param->id);
	if (param->flags & L)
		printf("L options up for %d\n", param->id);
	if (param->flags & hash)
		printf("hash options up for %d\n", param->id);
	if (param->flags & zero)
		printf("zero options up for %d\n", param->id);
	if (param->flags & moins)
		printf("moins options up for %d\n", param->id);
	if (param->flags & plus)
		printf("plus options up for %d\n", param->id);
	if (param->flags & espace)
		printf("espace options up for %d\n", param->id);
	printf("avant = %d de %d\n", param->avant, param->id);
	printf("apres = %d de %d\n", param->apres, param->id);
}*/

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
		swap_print_string(&to_print, &pos, format);
		swap_print_param(&to_print, ctof_tab, params + i);
		pos = modif_pos(pos, format);
		//TMP TEST
		//TESTFUN(params + i);
		++i;
	}
	swap_print_string(&to_print, &pos, format);
	//free_ctof(ctof_tab);
	//free_param(params);
	size = ft_strlen(to_print);
	write(1, to_print, size);
	return (size);
}

int			ft_printf(const char *format, ...)
{
	t_ctof	*ctof_tab;
	t_param	*params;
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
}
