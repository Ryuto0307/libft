NAME             =    libft.a
SRCS             =    ft_isalpha.c ft_strjoin.c ft_isdigit.c ft_substr.c ft_isascii.c ft_isprint.c ft_strlen.c

BONUS            =    ft_lstnew.c\
                    ft_lstadd_front.c\
                    ft_lstsize.c\
                    ft_lstlast.c\
                    ft_lstadd_back.c\
                    ft_lstdelone.c\
                    ft_lstclear.c\
                    ft_lstiter.c\
                    ft_lstmap.c

CC                =    cc
CFLAGS            =    -Wall -Wextra -Werror
LIBC            =    ar -rc
RM                =    rm -f
ifdef WITH_BONUS
SRCS        +=    ${BONUS}
endif
OBJS            =    ${SRCS:.c=.o}


.c.o:
	 ${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	${LIBC} ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS} ${BONUS:.c=.o}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

bonus:
	make WITH_BONUS=1 ${NAME}
