/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:15:52 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/09 22:58:35 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>

#include "ft_printf.h"
#include "libft/libft.h"

int		main()
{
	int		i;
	double	f;
	//char test[] = "test";
/* 	double 		shrt = -12.34; */
 	char		*bidule;
/* 	unsigned long int	t; */
	unsigned int	u;

	u = 4294967295;
	bidule = malloc(sizeof(char) * 42);
	i = 5;
	f = 42.424242424242;

	printf("or -->%05.1f<--\n", f);
//	printf("or --> %.6f <--\n", f);
	ft_printf("my -->%05.1f<--\n", f);
//	ft_printf("my --> %.6f <--\n", f);

/* 	ft_printf("abcde --> %5.2s <-- fgi --> %c %c <-- jklmn --> %s <--\n", NULL, '5', '5', "91011"); */
/* 	ft_printf("--> %d <--\n", 010); */
/* 	ft_printf("--> %o <--\n", i+4); */
/* 	ft_printf("--> %x <--\n", i+42); */
/* 	ft_printf("--> %X <--\n", i+42); */
/* 	ft_printf("--> %10.125f <--\n", f); */

/* 	ft_printf("--> i de 0 = %i <--\n", 00); */
/* 	ft_printf("--> d de 10 = %d <--\n", 010); */
/* 	printf("or --> i de 042 = %i <--\n", 042); */
/* 	ft_printf("my --> i de 042 = %i <--\n", 042); */

/* 	printf("or --> p = %p <--\n", &f); */
/* 	ft_printf("my --> p = %p <--\n", &f); */

/* 	printf("or --> p = %p <--\n", &i); */
/* 	ft_printf("my --> p = %p <--\n", &i); */

/* 	printf("or --> p = %s <--\n", NULL); */
/* 	ft_printf("my --> p = %s <--\n", NULL); */

/* 	printf("or --> p = %p <--\n", bidule); */
/* 	ft_printf("my --> p = %p <--\n", bidule); */

/* 	t = (unsigned long int)bidule; */
/* 	printf("#lx --> p = %#lx <--\n", t); */

/* 	printf("or --> u = %u <--\n", u); */
/* 	ft_printf("my --> u = %u <--\n", u); */
/* 	u = 0; */
/* 	printf("or --> u = %u <--\n", u); */
/* 	ft_printf("my --> u = %u <--\n", u); */
/* 	u = -46; */
/* 	printf("or --> u = %u <--\n", u); */
/* 	ft_printf("my --> u = %u <--\n", u); */

//printf("--> %.125f <--\n", f);
/* 	printf("null = %1s\n", bidule); */
/* 	printf("oct? = %15.05f\n", shrt); */
/* 	printf("oct? = %i\n", 012); */
/* 	printf("oct? = %i\n", 0x12); */
	//double 		shrt = -12.34;
	//char		*bidule = NULL;


	free(bidule);
	return (0);
}
