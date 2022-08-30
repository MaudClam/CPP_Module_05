NAME 		= 	No_you_need_form_28B

SRC 		= 	main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp
				
OBJS 		= 	${SRC:.cpp=.o}

HEADERS		=	Bureaucrat.hpp \
				AForm.hpp \
				ShrubberyCreationForm.cpp \
				PresidentialPardonForm.hpp \
				RobotomyRequestForm.hpp

FLAGS		=	-Wall -Wextra -Werror -std=c++98

CPP			=	clang++

RM 			= 	rm -f

%.o:			%.cpp ${HEADERS}
				${CPP} -c ${FLAGS} -I. $< -o ${<:.cpp=.o}

${NAME}:		${OBJS}
				${CPP} ${FLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
