NAME	= main
SRCS1	= rucksack_organisation.cpp
SRCS2	= rucksack_organisation_2.cpp
GCC		= g++ -Wfatal-errors
ARGV	= files/input2.txt

pt2:
	$(GCC) $(SRCS2) -o $(NAME) 
	@./$(NAME) $(ARGV)
pt1:
	$(GCC) $(SRCS1) -o $(NAME) 
	@./$(NAME) $(ARGV)

clean:
	@rm -rf $(NAME)
