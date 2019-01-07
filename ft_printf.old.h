/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 09:08:36 by jucapik           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/03 14:22:52 by naali            ###   ########.fr       */
=======
/*   Updated: 2019/01/04 10:05:34 by jucapik          ###   ########.fr       */
>>>>>>> 0cd826d5889b3a556d9e4a77ddecc6d4443bab72
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
	hh = 1,// conversion en char
	h = 2,// short int
	l = 4,// long int
	ll = 8,// long long int
	L = 16,// long double
	hash = 32,// ne peut pas etre seul:
/*
** #o prefix octal avec '0'
** #x ou #X prefix hexa avec 0x ou 0X
** #f montre toujours le point (exemple printf("%1.0f", 1.0) ==> 1.)
*/
	zero = 64,// remplie les vides avec des '0'
	moins = 128,// les espaces sont apres le nombre
	plus = 256,// affiche le signe
	espace = 512,// laisse un espace devant les nombres positifs
}					t_flags;

typedef struct		s_param
{
	int				id;// Numero du parametre
	char			type;// Si c'est %c, %c, %p... etc
	int				flags;
	int				avant;
	int				apres;
	void			*arg;
	double			dbl;
}					t_param;

typedef struct		s_ctof// Conv to function
{
	char	conv;
	char	*(*f)(t_param *);
}					t_ctof;

int		ft_printf(const char *format, ...);
t_param	*create_param(const char *format);
<<<<<<< HEAD
t_ctof	*create_ctof(void);// Renvois la table d'options a fonction
void	free_ctof(t_ctof *tab);
=======
t_ctof	*create_ctof(void); //renvois la table d'options a fonction
>>>>>>> 0cd826d5889b3a556d9e4a77ddecc6d4443bab72
int		get_nb_param(const char *format);
void	free_ctof(t_ctof *ctof);
void	free_param(t_param *tab);
char	*print_string(const char *str, int *pos);
char	*print_param(t_ctof *ctof, t_param *param);
void	get_flaglen(t_param *param, const char *format, int *i);
bln		get_flagopt(t_param *param, const char *format, int *i);
bln		get_vals(t_param *param, const char *format, int *i);
bln		get_type(t_param *param, const char *format, int *i);
char	*c_param(t_param *param);// Un caractere unique
char	*s_param(t_param *param);// Une chaine de caracteres
char	*p_param(t_param *param);// Un pointeur (en hexa)
char	*d_param(t_param *param);// Toujours int (je suis pas sur)
char	*i_param(t_param *param);// Peut convertir en octal ou decimal
char	*o_param(t_param *param);// Un unsigned octal
char	*u_param(t_param *param);// Un unsigned decimal
char	*x_param(t_param *param);// Un unsigned hexa (avce les lettres en petit)
char	*X_param(t_param *param);// Un unsigned hexa (avec les lettres en maj)
char	*f_param(t_param *param);// Bah float quoi

#endif
