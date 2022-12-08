NAME	= main
SRCS1	= first_unique4.cpp
SRCS2	= first_unique14.cpp
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
