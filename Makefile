# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 19:11:26 by kyork             #+#    #+#              #
#    Updated: 2017/05/03 11:43:55 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem_in

COMMONSRC	+= ft_strict_atoi.c main.c
COMMONSRC	+= moverec/moverec_new.c moverec/moverec_add.c moverec/moverec_next.c moverec/moverec_dump.c moverec/moverec_destroy.c

SOLVESRC	+= 

VISULSRC	+=

SOLVEOBJS	= $(addprefix srcs/, $(SOLVESRC:.c=.o) $(COMMONSRC:.c=.o))
VISULOBJS	= $(addprefix srcs/, $(VISULSRC:.c=.o) $(COMMONSRC:.c=.o))

LIBS		= libft/libft.a

CFLAGS		+= -Wall -Wextra -Wmissing-prototypes
#CFLAGS		= -Wall -Wextra -Wfloat-equal -Wundef -Wint-to-pointer-cast -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wcast-qual -Wmissing-prototypes -Wstrict-overflow=5 -Wwrite-strings -Wconversion --pedantic-errors
CFLAGS		+= -I includes/ -I srcs/
LDFLAGS		+= -Wall -Wextra

ifndef NO_WERROR
	CFLAGS += -Werror
	LDFLAGS += -Werror
endif

ifdef DEBUG
	CFLAGS += -fsanitize=address -g
	LDFLAGS += -fsanitize=address -g
endif

ifdef RELEASE
	CFLAGS += -O2
	LDFLAGS += -O2
endif

ifeq ($(SHELL),zsh)
	PRINTF	= printf
else
	PRINTF  = $(shell which printf)
endif

.PHONY: all clean fclean re

all: lem_in vis 

lem_in: $(SOLVEOBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $^
	@printf "\e[32m\e[1m[OK]\e[m $@\n" | tr '\\e' '\e'

vis: $(VISOBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $^
	@printf "\e[32m\e[1m[OK]\e[m $@\n" | tr '\\e' '\e'

libft/libft.a: libft/.git/refs/heads/master
	$(MAKE) -C libft libft.a

libft/.git/refs/heads/master:
	# ignore

clean:
	rm -f $(SOLVEOBJS) $(VISULOBJS)
	$(MAKE) -C libft clean
	@echo "\e[33m\e[1m[CLEAN]\e[m $$(basename $$(pwd))\n" | tr '\\e' '\e'

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	@echo "\e[33m\e[1m[FCLEAN]\e[m $$(basename $$(pwd))\n" | tr '\\e' '\e'

re: fclean
	$(MAKE) all

build:
	mkdir -p build

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

