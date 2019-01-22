#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucapik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 14:01:47 by jucapik           #+#    #+#              #
#    Updated: 2019/01/16 15:37:57 by naali            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	test

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Werror

SRC0		=	ctof.c	ft_printf.c	maintest.c	param.c	get_param.c \
				print.c	ft_itoa_base.c	ft_itoa_base_uns.c	\
				convert_param_for_itoa.c c_param.c	p_param.c	id_param.c	\
				o_param.c	s_param.c 	f_param.c	x_params.c	u_param.c \
				add_format.c ft_itoa_dbl.c

SRCPATH0	=	.

SOURCES0	=	$(addprefix $(SRCPATH0)/, $(SRC0))

HDR0		=	ft_printf.h


HDRPATH0	=	.

HEADERS0	=	$(addprefix $(HDRPATH0)/, $(HDR0))

LIBNAME		=	ft

LIBPATH		=	./libft

LIBHEAD		=	./libft

OBJ0		=	$(SRC0:.c=.o)

%.o:		$(SRCPATH0)/%.c
			$(CC) -o $@ -c $^ $(CFLAGS)

.PHONY:		clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ0)
			@(cd $(LIBPATH) && $(MAKE))
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ0) -I $(LIBHEAD) -L $(LIBPATH) -l$(LIBNAME)

noflag:		$(OBJ0)
			@(cd $(LIBPATH) && $(MAKE))
			$(CC) -o $(NAME) $(OBJ0) -I $(LIBHEAD) -L $(LIBPATH) -l$(LIBNAME)

clean:
			@(cd $(LIBPATH) && $(MAKE) clean)
			rm -rf $(OBJ0)

fclean:		clean
			rm -rf $(LIBPATH)/lib$(LIBNAME).a
			rm -rf $(NAME)

re:			fclean all

ren:		fclean noflag
