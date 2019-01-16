/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:53:20 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/16 11:43:07 by jucapik          ###   ########.fr       */
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
	while (i < n)
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
	int		abs_avant;

	write(2, "sp\n", 3);
	abs_avant = ft_abs(param->avant);
	s = (param->arg == NULL) ? ft_strdup("(null)") : (char *)param->arg;
	towrite = (param->apres > (int)ft_strlen(s) || param->apres == 0) ?
		ft_strlen(s) : param->apres;
	sizetomal = (abs_avant > towrite) ? abs_avant : towrite;
	ret = (char *)malloc(sizeof(char) * (sizetomal + 1));
	ft_memset((void *)ret, ' ', sizetomal);
	if (towrite < abs_avant && param->avant > 0)
		cpytoret((ret + sizetomal - towrite), s, towrite);
	else
		cpytoret(ret, s, towrite);
	ret[sizetomal] = '\0';
	if (param->arg == NULL)
		free(s);
	return (ret);
}
