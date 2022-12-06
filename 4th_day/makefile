NAME	= main
SRCS1	= fully_contains.cpp
SRCS2	= overlaps_at_all.cpp
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
