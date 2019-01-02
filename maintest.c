/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:15:52 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/02 13:44:52 by jucapik          ###   ########.fr       */
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

	ft_printf("abcde%2.3sfgi%c%cjklmn%5.4s\n", NULL, '5', '5', "91011");
	printf("null = %-3.1s\n", bidule);
	printf("oct? = %15.05f\n", shrt);
	printf("oct? = %-5i\n", 012);
	printf("oct? = %i\n", 0x12);
	return (0);
}
