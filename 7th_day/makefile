NAME	= main
SRCS1	= sum_of_dir_smaller_than.cpp
SRCS2	= smallest_dir_greater_than.cpp
GCC		= g++ -Wfatal-errors #-Wall -Wextra -Werror #-fsanitize=address
ARGV	= files/input.txt


pt2:
	$(GCC) $(SRCS2) -o $(NAME) 
	@./$(NAME) $(ARGV)
pt1:
	$(GCC) $(SRCS1) -o $(NAME) 
	@./$(NAME) $(ARGV)
clean:
	@rm -rf $(NAME)
