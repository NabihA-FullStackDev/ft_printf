/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:03:02 by naali             #+#    #+#             */
/*   Updated: 2019/01/07 12:14:00 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_BASE_H
# define FT_ITOA_BASE_H

# include "ft_printf.h"

# define BASEX "0123456789ABCDEF"
# define BASEx "0123456789abcdef"

typedef struct		s_itoa
{
	int				dbl;
	t_param			*nb;
	char			*base;
	int				szbs;
	int				mod;
	int				signe;
	int				size;
}					t_itoa;

char		*convert_param_for_itoa(t_param *nb, int base);
char		*ft_itoa_base(int nb, t_itoa *tools, int base);

#endif
