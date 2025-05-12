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
extern void ft_list_sort(struct list **list, int(*cmp)(void *, void *));
extern void ft_list_remove_if(struct list **list, void *data, int(*cmp)(void *, void *), void(*free_fct)(void *));

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

	printf("All good. No errors\n");
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

	printf("All good. No errors\n");
}

void ft_strcmp_tests() {
	char *str1 = "POlasd";
	char *str2 = "Hello";
	int ret;
	int ft_ret;

	ret = strcmp(str1, str2);
	ft_ret = ft_strcmp(str1, str2);
	printf("Ft: %d, Strcmp: %d\n", ft_ret, ret);
	assert(ft_ret == ret);

	str1 = "JIOK";
	ret = strcmp(str1, str2);
	ft_ret = ft_strcmp(str1, str2);
	printf("Ft: %d, Strcmp: %d\n", ft_ret, ret);
	assert(ft_ret == ret);

	str1 = "JIOK";
	str2 = "lol";
	ret = strcmp(str1, str2);
	ft_ret = ft_strcmp(str1, str2);
	printf("Ft: %d, Strcmp: %d\n", ft_ret, ret);
	assert(ft_ret == ret);

	str1 = "Hel\0lo";
	str2 = "Hel\0lo";
	ret = strcmp(str1, str2);
	ft_ret = ft_strcmp(str1, str2);
	printf("Ft: %d, Strcmp: %d\n", ft_ret, ret);
	assert(ft_ret == ret);

	str1 = "H\0ello";
	str2 = "Hel\0lo";
	ret = strcmp(str1, str2);
	ft_ret = ft_strcmp(str1, str2);
	printf("Ft: %d, Strcmp: %d\n", ft_ret, ret);
	assert(ft_ret == ret);

	printf("All good. No errors\n");
}

void ft_read_tests() {
	int ret;
	char buffer[100] = {0};
	
	//ret = read(10, NULL, sizeof(buffer));
	ret = ft_read(10, buffer, sizeof(buffer));

	printf("All good. No errors\n");
}

void ft_strcpy_tests() {
	char *ft_ret = NULL;
	char *ret = NULL;
	char buff[100] = {0};
	char ft_buff[100] = {0};
	char *src = "Hello";

	ret = strcpy(buff, src);
	ft_ret = ft_strcpy(ft_buff, src);
	printf("Ft_buff: %s, Buff: %s\n", ft_ret, ret);
	assert(strcmp(ft_ret, ret) == 0);

	src = "";
	ret = strcpy(buff, src);
	ft_ret = ft_strcpy(ft_buff, src);
	printf("Ft_buff: %s, Buff: %s\n", ft_ret, ret);
	assert(strcmp(ft_ret, ret) == 0);

	src = "Pol\0asd";
	ret = strcpy(buff, src);
	ft_ret = ft_strcpy(ft_buff, src);
	printf("Ft_buff: %s, Buff: %s\n", ft_ret, ret);
	assert(strcmp(ft_ret, ret) == 0);

	printf("All good. No errors\n");
}

void ft_strdup_tests() {
	char *str = "POALSD";
	char *ret = NULL;
	char *ft_ret = NULL;

	ret = strdup(str);
	ft_ret = ft_strdup(str);
	printf("Ft_ret: %s, Ret: %s\n", ft_ret, ret);
	assert(strcmp(ft_ret, ret) == 0);
	free(ft_ret);
	free(ret);

	str = "Hel\0lo";
	ret = strdup(str);
	ft_ret = ft_strdup(str);
	printf("Ft_ret: %s, Ret: %s\n", ft_ret, ret);
	assert(strcmp(ft_ret, ret) == 0);
	free(ft_ret);
	free(ret);

	str = "";
	ret = strdup(str);
	ft_ret = ft_strdup(str);
	printf("Ft_ret: %s, Ret: %s\n", ft_ret, ret);
	assert(strcmp(ft_ret, ret) == 0);
	free(ft_ret);
	free(ret);

	printf("All good. No errors\n");
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

	printf("All good. No errors\n");
}

struct list *new_node(void *nbr) {
	struct list *node;

	node = malloc(sizeof(struct list));
	node->data = nbr;
	node->next = NULL;
	return (node);
}

void free_list(struct list *list) {
	struct list *tmp;

	while (list != NULL) {
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void print_list_int(struct list *list) {
	while (list != NULL) {
		printf("List Node: %d\n", *(int *)list->data);
		list = list->next;
	}
}

void print_list_str(struct list *list) {
	while (list != NULL) {
		if (list->data != NULL) {
			printf("List Node: %s\n", (char *)list->data);
			list = list->next;
		}
	}
}

void push_back(struct list **list, struct list *new_node) {
	struct list *tmp = *list;

	if (*list == NULL) {
		*list = new_node;
		return;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = new_node;
}

void ft_list_push_front_tests() {
	int nbr[3] = {3, 2, 1};
	int src;
	struct list *list = NULL;
	
	for (int i = 0; i < 3; i++) {
		push_back(&list, new_node(&nbr[i]));
	}
	print_list_int(list);

	// Add 782
	src = 782;
	ft_list_push_front(&list, &src);
	printf("\n");
	print_list_int(list);

	// Add 9090
	src = 9090;
	ft_list_push_front(&list, &src);
	printf("\n");
	print_list_int(list);

	// Add 180
	src = 180;
	ft_list_push_front(&list, &src);
	printf("\n");
	print_list_int(list);

	free_list(list);
}

void ft_list_size_tests() {
	int nbrs[10] = {10, 78, 90, 87, 45, 345, 456, 1, 3, 4};
	int ft_ret;
	int size = sizeof(nbrs) / 4;
	struct list *list = NULL;
	
	for (int i = 0; i < size; i++) {
		push_back(&list, new_node(&nbrs[i]));
	}

	ft_ret = ft_list_size(list);
	printf("Ft_ret: %d, Size: %d\n", ft_ret, size);
	assert(ft_ret == size);

	push_back(&list, new_node(&nbrs[0]));
	size++;

	ft_ret = ft_list_size(list);
	printf("Ft_ret: %d, Size: %d\n", ft_ret, size);
	assert(ft_ret == size);

	printf("All good. No errors\n");
	free_list(list);
}

int cmp_int(void *data1, void *data2) {
	int a = *(int *)data1;
	int b = *(int *)data2;
	return (a - b);
}

int verify_sort(struct list *list) {
	while (list->next != NULL) {
		if (cmp_int(list->data, list->next->data) > 0) {
			return (0);
		}
		list = list->next;
	}
	return (1);
}

void ft_list_sort_tests() {
	int nbrs[] = {10, 78, 90, 87, 45, 345, 456, 1, 3, 4};
	//int nbrs[] = {90, 123, 89, 234, 21, 1, 2, 3, 4};
	int size = sizeof(nbrs) / 4;
	struct list *list = NULL;
	
	for (int i = 0; i < size; i++) {
		push_back(&list, new_node(&nbrs[i]));
	}
	ft_list_sort(&list, cmp_int);
	if (!verify_sort(list)) {
		printf("List Not Sorted\n");
	}
	//print_list_int(list);

	printf("All good. No errors\n");
	free_list(list);
}

void free_fct(void *data) {
	printf("Called free: %s\n", (char *)data);
	free(data);
	data = NULL;
}

int cmp_str(void *data1, void *data2) {
	//printf("\nAddr: %p, %p\n", data1, data2);
	char *nbr1 = (char *)data1;
	char *nbr2 = (char *)data2;
	return (strcmp(nbr1, nbr2));
}

void free_list_data(struct list *list) {
	struct list *tmp;

	while (list != NULL) {
		tmp = list;
		list = list->next;
		if (tmp->data != NULL) {
			free(tmp->data);
		}
		free(tmp);
	}
}

void ft_list_remove_if_tests() {
	char *str[7];
	char *src = "Hello";
	str[0] = strdup("LL");
	str[1] = strdup("POlasd");
	str[2] = strdup("JIdsa");
	str[3] = strdup("Hello");
	str[4] = strdup("Koasd");
	str[5] = strdup("poili");
	str[6] = strdup("Hello");
	struct list *list = NULL;
	
	for (int i = 0; i < sizeof(str) / 8; i++) {
		push_back(&list, new_node(str[i]));
	}
	//ft_list_remove_if(&list, src, cmp_str, free_fct);
	printf("Data: %s\n", (char *)list->data);
	free_fct(list->data);
	//print_list_str(list);
	printf("Data: %s\n", (char *)list->data);

	//free_list_data(list);
}


int main() {
	printf("--- FT_WRITE ---\n");
	ft_write_tests();
	printf("----------------\n\n");

	printf("--- FT_STRLEN ---\n");
	ft_strlen_tests();
	printf("----------------\n\n");

	printf("--- FT_STRCMP ---\n");
	ft_strcmp_tests();
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
	ft_list_push_front_tests();
	printf("----------------\n\n");

	printf("--- FT_LIST_SIZE ---\n");
	ft_list_size_tests();
	printf("----------------\n\n");

	printf("--- FT_LIST_SORT ---\n");
	ft_list_sort_tests();
	printf("----------------\n\n");

	//printf("--- FT_LIST_REMOVE_If ---\n");
	//ft_list_remove_if_tests();
	//printf("----------------\n\n");
}
