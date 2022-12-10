NAME	= main
SRCS1	= number_of_hidden_trees.cpp
SRCS2	= .cpp
GCC		= g++ -Wfatal-errors #-Wall -Wextra -Werror #-fsanitize=address
ARGV	= files/input.txt


# pt2:
# 	$(GCC) $(SRCS2) -o $(NAME) 
# 	@./$(NAME) $(ARGV)
pt1:
	$(GCC) $(SRCS1) -o $(NAME) 
	@./$(NAME) $(ARGV)
clean:
	@rm -rf $(NAME)
