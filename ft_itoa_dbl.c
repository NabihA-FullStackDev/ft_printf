/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:40:24 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/16 16:43:06 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

static int	getnblen(double n, int *signe, double *mod)
{
	int i;

	i = 1;
	*signe = 0;
	*mod = 1;
	if (n < 0)
		*signe = 1;
//	else
//		n = n * -1;
	printf("%.0f\n", *mod);
	while (n > 10)
	{
		n /= 10;
		*mod = *mod * 10;
		i++;
	}
	printf("%.0f\n", *mod);
	return (i);
}

char		*ft_itoa_dbl(double n)
{
	int		i;
	char	*res;
	int		signe;
	double	mod;

	i = 0;
	res = (char*)malloc(sizeof(char) * (getnblen(n, &signe, &mod) + signe + 1));
	while (mod > 0.000001)
	{
 		res[i] = (int)(n / mod) + '0';
//		printf("%d", (int)(n/mod));
		while (n >= mod)
			n = n - mod;
		mod = mod / 10;
		i = i + 1;
	}
	res[i] = '\0';
	return (res);
}
