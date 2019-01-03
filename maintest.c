/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:15:52 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/03 09:15:18 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>

#include "ft_printf.h"
#include "libft/libft.h"

int		main()
{
	//char test[] = "test";
	double 		shrt = -12.34;
	char		*bidule = NULL;

	ft_printf("abcde%sfgi%c%cjklmn%5.10s\n", NULL, '5', '5', "91011");
	printf("null = %3.1s\n", bidule);
	printf("oct? = %15.05f\n", shrt);
	printf("oct? = %d\n", 1);
	printf("oct? = %i\n", 0x12);
	return (0);
}
