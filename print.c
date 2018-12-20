/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:27:38 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/20 11:08:37 by jucapik          ###   ########.fr       */
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
	return (ft_strndup(str, size));
}

char		*print_param(t_ctof *ctof, t_param *param, int *pos)
{
	int		i;
	char	*ret;
	
	i = 0;
	while (ctof[i].conv != param->type && ctof[i].conv != 'N')
		i++;
	if (ctof[i].conv == 'N')
		return (NULL);
	ret = ctof[i].f(param);
	(*pos) += ft_strlen(ret);
	return (ret);
}
