#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>

struct list {
	void *data;
	struct list *next;
};

extern ssize_t ft_write(int fd, void *str, size_t nbyte);
extern size_t ft_strlen(char *str);
extern int ft_strcmp(char *str1, char *str2);
extern char test(char *str);
extern int ft_read(int fd, void *buf, size_t nbyte);
extern char *ft_strcpy(const char *dest, const char *src);
extern char *ft_strdup(const char *str);
extern int ft_atoi_base(char *str, char *base);
extern void ft_list_push_front(struct list **list, void *data);
extern int ft_list_size(struct list *list);
extern void ft_list_sort(struct list **list, int(*cmp)(int, int));

void ft_write_tests() {
	char *str = NULL;
	ssize_t wr_ret;
	ssize_t ft_ret;
	
	// Normal String Test
	str = "Normal String\n";
	wr_ret = write(1, str, strlen(str));
	ft_ret = ft_write(1, str, strlen(str));
	assert(ft_ret == wr_ret);

	// Prints half
	str = "Halfed Text\n";
	wr_ret = write(1, str, strlen(str) / 2);
	ft_ret = ft_write(1, str, strlen(str) / 2);
	assert(ft_ret == wr_ret);
	
	// Bad Fd Test
	str = "Bad Fd\n";
	wr_ret = write(10, str, strlen(str));
	ft_ret = ft_write(10, str, strlen(str));
	assert(ft_ret == wr_ret);
}

void ft_strlen_tests() {
	char *str = NULL;

	// Normal Test
	str = "Hello";
	printf("Ret: %zu\n", ft_strlen(str));
	assert(ft_strlen(str) == strlen(str));
	// Empty Test
	printf("Ret: %zu\n", ft_strlen(""));
	assert(ft_strlen("") == strlen(""));
	// \0 in the middle
	str = "He\0llo";
	printf("Ret: %zu\n", ft_strlen(str));
	assert(ft_strlen(str) == strlen(str));
}

void ft_strcmp_tests() {
	char *str1 = "POlasd";
	char *str2 = "Hello";
	int ret;
	int ft_ret;

	ret = strcmp(str1, str2);
	ft_ret = ft_strcmp(str1, str2);
	printf("ft: %d, strcmp: %d\n", ft_ret, ret);
	assert(ft_ret == ret);

	//str1 = "JIOK";
	//ret = strcmp(str1, str2);
	//ft_ret = ft_strcmp(str1, str2);
	//printf("ft: %d, strcmp: %d\n", ft_ret, ret);
	//assert(ft_ret == ret);

	//str1 = "JIOK";
	//str2 = "lol";
	//ret = strcmp(str1, str2);
	//ft_ret = ft_strcmp(str1, str2);
	//printf("ft: %d, strcmp: %d\n", ft_ret, ret);
	//assert(ft_ret == ret);
}

void ft_read_tests() {
	int ret;
	char buffer[100] = {0};
	
	//ret = read(10, NULL, sizeof(buffer));
	ret = ft_read(10, NULL, sizeof(buffer));
}

void ft_strcpy_tests() {
	char *ret = NULL;
	char buffer[100] = {0};
	char *src = "Hello";

	ret = ft_strcpy(buffer, src);
	printf("Buffer: %s, Src: %s\n", ret, src);
	assert(strcmp(buffer, src) == 0);
}

void ft_strdup_tests() {
	char *str = "POALSD";

	char *ret = ft_strdup(str);
	printf("Str: %p\n", str);
	printf("Ret: %p, %s\n", ret, ret);
	assert(strcmp(str, ret) == 0);
}

void ft_atoi_base_tests() {
	char *str = "-+-10";
	char *dec_base = "0123456789";
	char *hex_base = "0123456789abcdef";
	char *octal_base = "01234567";
	char *binary_base = "01";
	int ret;

	ret = ft_atoi_base(str, dec_base);
	printf("Dec: %d\n", ret);
	ret = ft_atoi_base(str, hex_base);
	printf("Hex: %d\n", ret);
	ret = ft_atoi_base(str, octal_base);
	printf("Oct: %d\n", ret);
	ret = ft_atoi_base(str, binary_base);
	printf("Bin: %d\n", ret);
	//ret = ft_atoi_base("101A", dec_base);
	//printf("Bin: %d\n", ret);

	//assert(ret == atoi(str));
}

int cmp(int a, int b) {
	return (a - b);
}

struct list *new_node(const int *nbr) {
	struct list *node;

	node = malloc(sizeof(struct list));
	node->data = (void *)nbr;
	node->next = NULL;
	return (node);
}

void ft_list_tests() {
	int nbr[3] = {3, 2, 1};
	struct list *list = new_node(&nbr[0]);
	
	for (int i = 1; i < 3; i++) {
		list->next = new_node(&nbr[i]);
	}
	int lol = 90;
	ft_list_push_front(&list, &lol);
	struct list *temp = list;
	while (temp != NULL) {
		printf("List Node: %d\n", *(int *)temp->data);
		temp = temp->next;
	}
	printf("----------------\n\n");

	// ft_list_size
	printf("--- FT_LIST_SIZE ---\n");
	int size = ft_list_size(list);
	printf("Size: %d\n", size);
	printf("----------------\n\n");

	// ft_list_sort
	printf("--- FT_LIST_SORT ---\n");
	ft_list_sort(&list, &cmp);
	temp = list;
	while (temp != NULL) {
		printf("List Node: %d\n", *(int *)temp->data);
		temp = temp->next;
	}
}

int main() {
	printf("--- FT_WRITE ---\n");
	ft_write_tests();
	printf("----------------\n\n");

	printf("--- FT_STRLEN ---\n");
	ft_strlen_tests();
	printf("----------------\n\n");

	printf("--- FT_STRCMP ---\n");
	//ft_strcmp_tests();
	printf("----------------\n\n");

	printf("--- FT_READ ---\n");
	ft_read_tests();
	printf("----------------\n\n");

	printf("--- FT_STRCPY ---\n");
	ft_strcpy_tests();
	printf("----------------\n\n");

	printf("--- FT_STRDUP ---\n");
	ft_strdup_tests();
	printf("----------------\n\n");

	printf("--- FT_ATOI_BASE ---\n");
	ft_atoi_base_tests();
	printf("----------------\n\n");

	printf("--- FT_LIST_PUSH_FRONT ---\n");
	ft_list_tests();
	printf("----------------\n\n");
}
