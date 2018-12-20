/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:27:38 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/20 16:43:28 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char		*print_string(const char *str, int *pos)
{
	int size;
	int og_pos;

	og_pos = *pos;
	size = 0;
	while (str[*pos] != '\0' && str[*pos] != '%')
	{
		(*pos)++;
		size++;
	}
	return (ft_strndup(str + og_pos, size));
}

char		*print_param(t_ctof *ctof, t_param *param)
{
	int		i;
	char	*ret;

	write(1, "1\n", 2);
	i = 0;
	while (ctof[i].conv != param->type && ctof[i].conv != 'N')
		i++;
	write(1, "2\n", 2);
	if (ctof[i].conv == 'N')
		return (NULL);
	write(1, "3\n", 2);
	ret = ctof[i].f(param);
	write(1, "4\n", 2);
	return (ret);
}
