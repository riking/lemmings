# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 19:11:26 by kyork             #+#    #+#              #
#    Updated: 2017/05/20 12:51:43 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem_in

COMMONSRC	+= ft_strict_atoi.c main.c flood.c paths_conflict.c max_path.c
COMMONSRC	+= $(addprefix moverec/, moverec_new.c moverec_add.c moverec_next.c moverec_dump.c moverec_destroy.c)
COMMONSRC	+= search/search_print_path.c search/search_path_room_queue.c search/search_work_path.c search/search_workall.c search/search_setup.c search/search_path_cost.c search/search_cleanup.c
COMMONSRC	+= roomlist_has_room.c find_room.c
COMMONSRC	+= parse/parse_directive.c parse/parse_room.c parse/parse_link.c parse/parse_movements.c parse/parse_error.c
COMMONSRC	+= parse/parse_rooms.c parse/parse_layout.c parse/parse_set_startfinish.c parse/parse_cleanup.c
COMMONSRC	+= $(addprefix subset/, pathcmp.c subset_construct.c subset_findn.c subset_path_add.c subset_room_bits.c subset_search.c subset_cleanup.c)
COMMONSRC	+= $(addprefix lemprint/, print_comments.c  print_layout.c  print_room.c  print_room_links.c)
COMMONSRC	+= $(addprefix antassign/, antassign_cleanup.c  antassign_do.c  antassign_print.c  antassign_tick.c)

SOLVESRC	+= 

VISULSRC	+=

SOLVEOBJS	= $(addprefix srcs/, $(SOLVESRC:.c=.o) $(COMMONSRC:.c=.o))
VISULOBJS	= $(addprefix srcs/, $(VISULSRC:.c=.o) $(COMMONSRC:.c=.o))

LIBS		= libft/libft.a

# Flags start
CFLAGS		+= -Wall -Wextra -Wmissing-prototypes
CFLAGS		+= -I includes/
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
# Flags end

ifeq ($(SHELL),zsh)
	PRINTF	= printf
else
	PRINTF  = $(shell which printf)
endif

.PHONY: all clean fclean re

all: lem_in

lem_in: $(SOLVEOBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $^
	@printf "\e[32m\e[1m[OK]\e[m $@\n" | tr '\\e' '\e'

libft/libft.a: libft/.git/refs/heads/master
	$(MAKE) -C libft libft.a

libft/.git/refs/heads/master:
	# ignore

clean:
	rm -rf build/
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

build/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

