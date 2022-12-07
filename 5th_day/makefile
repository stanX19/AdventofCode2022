NAME	= main
SRCS1	= supply_stacks.cpp
SRCS2	= supply_stacks_2.cpp
GCC		= g++ -Wfatal-errors
ARGV	= files/input.txt


pt2:
	$(GCC) $(SRCS2) -o $(NAME) 
	@./$(NAME) $(ARGV)
pt1:
	$(GCC) $(SRCS1) -o $(NAME) 
	@./$(NAME) $(ARGV)
clean:
	@rm -rf $(NAME)
