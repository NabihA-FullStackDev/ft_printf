/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:46:52 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/11 11:07:52 by jucapik          ###   ########.fr       */
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

static void	swap_print_param(char **to_print, t_ctof *cf, t_param *p)
{
	char	*tmp;
	char	*pp;

	pp = print_param(cf, p);
	tmp = ft_strjoin(*to_print, pp);
	free(*to_print);
	*to_print = tmp;
	free(pp);
}

int			modif_pos(int pos, const char *format)
{
	++pos;
	while (format[pos] == '#' || format[pos] == '-' || format[pos] == '+'
			|| format[pos] == '0' || format[pos] == ' ')
		++pos;
	while ((format[pos] >= '0' && format[pos] <= '9') || format[pos] == '.')
		++pos;
	while (format[pos] == 'h' || format[pos] == 'l' || format[pos] == 'L')
		++pos;
	++pos;
	return (pos);
}

static void TESTFUN(t_param *param)
{
	printf("flags for param number %d:\n", param->id);
	if (param->flags & hh)
		printf("\thh options up for %d\n", param->id);
	if (param->flags & h)
		printf("\th options up for %d\n", param->id);
	if (param->flags & ll)
		printf("\tll options up for %d\n", param->id);
	if (param->flags & l)
		printf("\tl options up for %d\n", param->id);
	if (param->flags & L)
		printf("\tL options up for %d\n", param->id);
	if (param->flags & hash)
		printf("\thash options up for %d\n", param->id);
	if (param->flags & zero)
		printf("\tzero options up for %d\n", param->id);
	if (param->flags & moins)
		printf("\tmoins options up for %d\n", param->id);
	if (param->flags & plus)
		printf("\tplus options up for %d\n", param->id);
	if (param->flags & espace)
		printf("\tespace options up for %d\n", param->id);
	if (param->flags & point)
		printf("\tpoint options up for %d\n", param->id);
	printf("\ttype %c for %d\n", param->type, param->id);
	if (param->avant != 0)
		printf("\tavant = %d de %d\n", param->avant, param->id);
	if (param->apres != 0)
		printf("\tapres = %d de %d\n", param->apres, param->id);
	printf("\tflags = ");
	int c = 9, k, n = param->flags;
	while (c >= 0)
	{
		k = n >> c;

		if (k & 1)
			printf("1");
		else
			printf("0");
		c--;
	}
	printf("\n");
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
		swap_print_string(&to_print, &pos, format);
		swap_print_param(&to_print, ctof_tab, params + i);
		pos = modif_pos(pos, format);
		//TMP TEST
				TESTFUN(params + i);
		++i;
	}
	swap_print_string(&to_print, &pos, format);
	free_ctof(ctof_tab);
	free_param(params);
	size = ft_strlen(to_print);
	write(1, to_print, size);
	free(to_print);
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
		params[i].arg = NULL;
		if (params[i].type == 'f')
			params[i].dbl = (long double)va_arg(ap, long double);
		else if (params[i].type == 'p')
			params[i].ui = (long long)va_arg(ap, long long);
		else
			params[i].arg = (void *)va_arg(ap, void *);
		++i;
	}
	va_end(ap);
	return (print_all(format, ctof_tab, params));
}
