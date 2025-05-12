NAME = libasm
NASM = nasm
NASM_FLAGS = -f elf64

SRC = ft_write.s ft_strlen.s ft_strcmp.s ft_read.s \
	ft_strcpy.s ft_strdup.s ft_atoi_base.s ft_list_push_front.s \
	ft_list_size.s ft_list_sort.s ft_list_remove_if.s
OBJ = $(SRC:.s=.o)

%.o: %.s
	$(NASM) $(NASM_FLAGS) -o $@ $<

all: main $(OBJ)
	cc -o $(NAME) main.o $(OBJ)
	./$(NAME)

main:
	cc -o main.o -g -c main.c

clean:
	rm -rf $(OBJ)
	rm -rf main.o
	rm -rf $(NAME)
