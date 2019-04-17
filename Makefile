CC=g++
CFLAGS=
source=sine-terminal.cc
output=sinesay
$(output): $(source)
	$(CC) -o $(output) $(source)

clean: 
	  $(RM) $(output) 
