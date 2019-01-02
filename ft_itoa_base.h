/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:03:02 by naali             #+#    #+#             */
/*   Updated: 2018/12/21 13:26:27 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_BASE_H
# define FT_ITOA_BASE_H

enum
{
	Tint = 1,
	Tdouble = 2,
	Tfloat = 4,
};

typedef	struct		s_getnb
{
	int				i;
//	unsigned int	ui;
	double			dbl;
	float			flt;
}					t_getnb;

char		*ft_itoa_base(void *nb, unsigned int base, int type);

#endif
