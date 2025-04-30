#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>

extern ssize_t ft_write(int fd, void *str, size_t nbyte);
extern size_t ft_strlen(char *str);
extern int ft_strcmp(char *str1, char *str2);
//extern char teste(char *str);
extern int ft_read(int fd, void *buf, size_t nbyte);
extern char *ft_strcpy(const char *dest, const char *src);
extern char *ft_strdup(const char *str);

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
	assert(ft_strlen(str) == strlen(str));
	// Empty Test
	assert(ft_strlen("") == strlen(""));
	// \0 in the middle
	str = "He\0llo";
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
}
