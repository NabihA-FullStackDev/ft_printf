/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:03:02 by naali             #+#    #+#             */
/*   Updated: 2019/01/03 17:39:22 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_BASE_H
# define FT_ITOA_BASE_H

# include "ft_printf.h"

# define BASEX "0123456789ABCDEF"
# define BASEx "0123456789abcdef"

typedef struct		s_itoa
{
	t_param			*nb;
	char			*base;
	unsigned int	szbs;
}					t_itoa;

char		*ft_itoa_base(t_param *nb, unsigned int base);

#endif
