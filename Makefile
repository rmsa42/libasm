NAME = libasm
LIB_NAME = $(NAME).a
NASM = nasm
NASM_FLAGS = -f elf64

SRC = ft_write.s ft_strlen.s ft_strcmp.s ft_read.s \
	ft_strcpy.s ft_strdup.s
OBJS = $(SRC:.s=.o)

SRC_BONUS = $(SRC) \
	ft_atoi_base_bonus.s ft_list_push_front_bonus.s ft_list_size_bonus.s \
	ft_list_sort_bonus.s ft_list_remove_if_bonus.s
OBJS_BONUS = $(SRC_BONUS:.s=.o)
BONUS = bonus

$(LIB_NAME): $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)

%.o: %.s
	$(NASM) $(NASM_FLAGS) -o $@ $<

bonus: $(OBJS_BONUS)
	@make OBJS="$(OBJS_BONUS)" $(LIB_NAME)

all: $(LIB_NAME)
	cc -o $(NAME) -g main.c -L. -lasm
	./$(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean: clean
	rm -rf $(LIB_NAME)

re: fclean all

.SILENT: main all
