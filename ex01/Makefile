NAME    = easyfind
SRCS    = $(shell find . -name "*.cpp")
OBJS 	= ${SRCS:.cpp=.o}
CXXFLAGS   = -Wall -Wextra -Werror -std=c++98
RM		= rm -rf
CXX      = c++
  
%.o: %.cpp %.hpp Makefile
	@$(CXX) ${CXXFLAGS} -I. -c $< -o $@

all:	${NAME}

$(NAME):	$(OBJS)
	@$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
	@${RM} ${OBJS}

fclean:		clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re