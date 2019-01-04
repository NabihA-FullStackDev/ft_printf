/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 09:08:36 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/04 10:05:34 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef	enum		boolean
{
	ERROR = -1,
	FALSE = 0,
	TRUE = 1
}					bln;

typedef enum		s_flags
{
	hh = 1,
	h = 2,
	l = 4,
	ll = 8,
	L = 16,
	hash = 32,
	zero = 64,
	moins = 128,
	plus = 256,
	espace = 512,
}					t_flags;

typedef struct		s_param
{
	int				id; //numero du parametre
	char			type; //si c'est %c, %c, %p... etc
	int				flags;
	int				avant;
	int				apres;
	void			*arg;
	double			dbl;
}					t_param;

typedef struct		s_ctof //conv to function
{
	char	conv;
	char	*(*f)(t_param *);
}					t_ctof;

int		ft_printf(const char *format, ...);
t_param	*create_param(const char *format);
t_ctof	*create_ctof(void); //renvois la table d'options a fonction
int		get_nb_param(const char *format);
void	free_ctof(t_ctof *ctof);
void	free_param(t_param *tab);
char	*print_string(const char *str, int *pos);
char	*print_param(t_ctof *ctof, t_param *param);
void	get_flaglen(t_param *param, const char *format, int *i);
bln		get_flagopt(t_param *param, const char *format, int *i);
bln		get_vals(t_param *param, const char *format, int *i);
bln		get_type(t_param *param, const char *format, int *i);
char	*c_param(t_param *param); //un caractere unique
char	*s_param(t_param *param); //une chaine de caracteres
char	*p_param(t_param *param); //un pointeur (en hexa)
char	*d_param(t_param *param); //toujours int (je suis pas sur)
char	*i_param(t_param *param); // peut convertir en octal ou decimal
char	*o_param(t_param *param); // un unsigned octal
char	*u_param(t_param *param); // un unsigned decimal
char	*x_param(t_param *param); // un unsigned hexa (avce les lettres en petit)
char	*X_param(t_param *param); // un unsigned hexa (avec les lettres en maj)
char	*f_param(t_param *param); // bah float quoi

#endif
