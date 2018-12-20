/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 09:08:36 by jucapik           #+#    #+#             */
/*   Updated: 2018/12/20 12:56:55 by jucapik          ###   ########.fr       */
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

typedef struct		s_param
{
	int				id; //numero du parametre
	char			type; //si c'est %c, %c, %p... etc
	bln				hh; //indique que le nombre est en unsigned char
	// ou en signed char
	bln				h; //indique que le nombre est un short int ou unsigned short int
	bln				l; //indique que le nombre est un long int ou unsigned long int
	bln				ll; //pareille mais pour long long int ou unsigned long long int
	bln				L; //pareille mais pour long double
	bln				hash; //pour les nombres, indique qu'on doit convertir.
	//On a donc 2 cas : %o ou il faudra rajouter un 0 au debut et
	//%x ou%X ou il faudra ajouter 0x ou 0X au debut
	bln				zero; //indique que le padding est fait par des 0 a la place
	// d'espaces, (pour les nombres donc)
	bln				moins; //indique que le padding est fait a droite au lieu
	// de a gauche
	bln				plus; //le signe '+' ou '-' doit etre indique avant le nombre
	bln				espace; // un espace ou un '-' doit etre ibdique avant le nombre
	int				avant;
	int				apres;
	int				sans;
	void			*arg;
}					t_param;

typedef struct		s_ctof //conv to function
{
	char	conv;
	char	*(*f)(t_param *);
}					t_ctof;

int		ft_printf(const char *format, ...);
t_param	*create_param(const char *format);
t_ctof	*create_ctof(void); //renvois la table d'options a fonction
void	free_ctof(t_ctof *tab);
int		get_nb_param(const char *format);
void	free_param(t_param *tab);
char	*print_string(const char *str, int *pos);//renvois la taille imprime
char	*print_param(t_ctof *ctof, t_param *param, int *pos);//renvois la taille imprime
void	get_flag1(t_param *param, const char *format, int *i);
void	get_flag2(t_param *param, const char *format, int *i);
void	get_vals(t_param *param, const char *format, int *i);
void	get_type(t_param *param, const char *format, int *i);
char	*c_param(t_param *param); //un caractere unique
char	*s_param(t_param *param); //une chaine de caracteres
char	*p_param(t_param *param); //un pointeur (en hexa)
char	*d_param(t_param *param); //un double ou int (je suis pas sur)
char	*i_param(t_param *param); // un int
char	*o_param(t_param *param); // un unsigned octal
char	*u_param(t_param *param); // un unsigned decimal
char	*x_param(t_param *param); // un unsigned hexa (avce les lettres en petit)
char	*X_param(t_param *param); // un unsigned hexa (avec les lettres en maj)
char	*f_param(t_param *param); // bah float quoi

#endif
