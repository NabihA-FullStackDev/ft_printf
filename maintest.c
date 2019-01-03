/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:15:52 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/03 18:14:46 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>

#include "ft_printf.h"
#include "libft/libft.h"

int		main()
{
	//char test[] = "test";
	//double 		shrt = -12.34;
	//char		*bidule = NULL;

	ft_printf("%%-->1<--%%-->2<--%s-->3<--%s-->4<--%s-->5<--%%",
			"test", "1234", "91011");
	//printf("null = %3z\n", bidule);
	//printf("oct? = %15.05f\n", shrt);
	//printf("oct? = %10.5d\n", 1);
	//printf("oct? = %i\n", 0x12);
	return (0);
}
