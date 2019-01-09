/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:03:02 by naali             #+#    #+#             */
/*   Updated: 2019/01/09 21:46:58 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_BASE_H
# define FT_ITOA_BASE_H

# include "ft_printf.h"

# define BASEX "0123456789ABCDEF"
# define BASEx "0123456789abcdef"

typedef long long int t_lli;
typedef unsigned long long int t_ulli;

typedef struct		s_itoa
{
	int				dbl;
	t_param			*nb;
	int				size;
	int				signe;
	t_lli			smod;
	t_ulli			umod;
	int				szbs;
	char			*base;
}					t_itoa;

typedef struct		s_flgcheck
{
	char			*space;
	char			*zero;
	char			plus;
	char			blank;
	char			*tmp1;
	char			*tmp2;
}					t_flgcheck;

char		*convert_param_for_itoa(t_param *nb, int base);
char		*ft_itoa_base(t_lli nb, t_itoa *tools, t_lli base);
char		*ft_itoa_base_uns(t_ulli nb, t_itoa *tools, t_ulli base);

#endif
