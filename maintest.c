/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:15:52 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/20 16:45:12 by jucapik          ###   ########.fr       */
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

	ft_printf("abcde%sxyz%s", "1234", "5678");
	shrt = shrt -1;
	//printf("res = %-10d\n", 1234);
	//printf("str = %1s\n", "abcdefghijk");
	return (0);
}
