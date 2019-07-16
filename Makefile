CXX		=	g++

RM		=	rm -f

NAME		=	words

OBJS		=	$(SRCS:.cpp=.o)

SRCS		=	words.cpp

CXXFLAGS	=	-W -Wall -Wextra -Wfatal-errors


all		:	$(NAME)
			@echo		"|-----------------------|"
			@echo -e       	"|     \e[5mIT'S WORKING!\e[0m     |"
			@echo -e       	"|     \e[34m____v__   _  _\e[0m    |"
			@echo -e       	"|    \e[34m| 0     |  \||/\e[0m    |"
			@echo -e       	"|    \e[34m|       |__/ |\e[0m     |"
			@echo -e       	"|    \e[34;1m~~~~~~~~~~~~~~~\e[0m    |"
			@echo        	"|-----------------------|"

$(NAME)		:	$(OBJS)
			$(CXX) -o $(NAME) $(OBJS)

clean		:	$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
