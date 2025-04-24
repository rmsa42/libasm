#include <errno.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>

extern ssize_t ft_write(int fd, void *str, size_t nbyte);
extern size_t ft_strlen(char *str);

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

int main() {
	printf("--- FT_WRITE ---\n");
	ft_write_tests();
	printf("----------------\n\n");

	printf("--- FT_STRLEN ---\n");
	ft_strlen_tests();
	printf("----------------\n\n");
}
