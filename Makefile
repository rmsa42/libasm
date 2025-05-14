NAME = libasm
LIB_NAME = $(NAME).a
NASM = nasm
NASM_FLAGS = -f elf64

SRC = ft_write.s ft_strlen.s ft_strcmp.s ft_read.s \
	ft_strcpy.s ft_strdup.s ft_atoi_base.s ft_list_push_front.s \
	ft_list_size.s ft_list_sort.s ft_list_remove_if.s
OBJ = $(SRC:.s=.o)

$(NAME): $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

%.o: %.s
	$(NASM) $(NASM_FLAGS) -o $@ $<

all: $(NAME)
	cc -o $(NAME) -g main.c -L. -lasm
	./$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB_NAME)

re: fclean $(NAME)

.SILENT: main all
