NAME = libdynamic.so

all: $(NAME)

$(NAME): Database.o Employee.o Policy.o
	g++ -shared -o $@ $^

%.o: %.cpp
	g++ -Wall -c -fPIC $< -o $@

clean:
	rm -f *.o *.a $(NAME)