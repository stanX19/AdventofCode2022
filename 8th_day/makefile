NAME	= main
SRCS1	= number_of_hidden_trees.cpp
SRCS2	= highest_scenic_score.cpp
GCC		= g++ -Wfatal-errors #-Wall -Wextra -Werror #-fsanitize=address
ARGV	= files/input2.txt


pt2:
	$(GCC) $(SRCS2) -o $(NAME) 
	@./$(NAME) $(ARGV)
pt1:
	$(GCC) $(SRCS1) -o $(NAME) 
	@./$(NAME) $(ARGV)
clean:
	@rm -rf $(NAME)
