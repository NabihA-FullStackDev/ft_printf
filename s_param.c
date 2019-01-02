/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:53:20 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/02 13:44:41 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

char	*cpytoret(char *d, char *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n && d)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*s_param(t_param *param)
{
	char	*s;
	int		sizetomal;
	char	*ret;
	int		towrite;

	s = (param->arg == NULL) ? ft_strdup("(null)") : (char *)param->arg;
	towrite = ((int)ft_strlen(s) > ft_abs(param->avant))
		? ft_strlen(s) : ft_abs(param->avant);
	sizetomal = (param->apres >= towrite) ? param->apres : towrite;
	ret = (char *)malloc(sizeof(char) * (sizetomal + 1));
	ft_memset((void *)ret, ' ', sizetomal);
	if (towrite > param->apres && param->avant > 0)
		cpytoret((void *)(ret + sizetomal - param->apres), (void *)s, towrite);
	else
		cpytoret((void *)(ret), (void *)s, towrite);
	ret[sizetomal] = '\0';
	printf("DEBUG: ret = %s\n", ret);
	return (ret);
}
