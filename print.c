/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:27:38 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/03 18:14:31 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

static char	*ft_strndupspe(const char *s1, size_t n)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(s1);
	if (size < n)
	{
		if ((dest = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
			return (NULL);
	}
	else
	{
		if ((dest = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
			return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i] != '\0' && j < n)
	{
		if (s1[i] == '%' && s1[i + 1] == '%')
			++i;
		dest[j++] = s1[i++];
	}
	dest[j] = '\0';
	return (dest);
}

char		*print_string(const char *str, int *pos)
{
	int size;
	int og_pos;

	og_pos = *pos;
	size = 0;
	if (str[(*pos)] == '%' && str[(*pos) + 1] == '%')
	{
		(*pos) += 2;
		++size;
	}
	while (str[*pos] != '\0' && str[*pos] != '%')
	{
		if (str[(*pos) + 1] == '%' && str[(*pos) + 2] == '%')
		{
			(*pos) += 2;
			++size;
		}
		++(*pos);
		size++;
	}
	return (ft_strndupspe(str + og_pos, size));
}

char		*print_param(t_ctof *ctof, t_param *param)
{
	int		i;

	i = 0;
	while (ctof[i].conv != param->type && ctof[i].conv != 'N')
		i++;
	if (ctof[i].conv == 'N')
	{
		//printf("\nONYEST\n");
		return (ft_strdup("TEST"));
	}
	return (ctof[i].f(param));
}
