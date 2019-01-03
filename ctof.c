/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:41:03 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/03 17:28:55 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_ctof	*create_ctof(void)
{
	t_ctof	*ctof;

	ctof = (t_ctof *)malloc(sizeof(t_ctof) * 11); // 10 mais le 11eme a NULL
	ctof[0].conv = 'c';
	ctof[0].f = &c_param;
	ctof[1].conv = 's';
	ctof[1].f = &s_param;
/*	ctof[2].conv = 'p';
	ctof[2].f = &p_param;
*/	ctof[2].conv = 'd';
	ctof[2].f = &d_param;
/*	ctof[4].conv = 'i';
	ctof[4].f = &i_param;
	ctof[5].conv = 'o';
	ctof[5].f = &o_param;
	ctof[6].conv = 'u';
	ctof[6].f = &u_param;
*/	ctof[3].conv = 'x';
	ctof[3].f = &x_param;
	ctof[4].conv = 'X';
	ctof[4].f = &X_param;
	ctof[5].conv = 'f';
	ctof[5].f = &f_param;
	ctof[6].conv = 'N';// A CHANGER OU METTRE NULL
	return (ctof);
}
