/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:15:52 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/21 12:10:20 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>

#include "ft_printf.h"
#include "libft/libft.h"

int		main()
{
	//char test[] = "test";
	long int	shrt = -1;

	ft_printf("abcde%sfghi%cjklmn%s\n", "1234", '5', "91011");
	shrt = shrt -1;
	/*printf("oct? = %ld\n", 2147483648);
	printf("oct? = % -5i\n", 012);
	printf("oct? = % -5i\n", 0x12);
	*/return (0);
}
