/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:33:07 by lbaron            #+#    #+#             */
/*   Updated: 2022/12/07 14:33:10 by lbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"libft.h" 


void red() {
  printf("\033[1;31m");
}

void green() {
  printf("\033[0;32m");
}

void yellow() {
  printf("\033[1;33m");
}

void blue() {
  printf("\033[1;34m");
}

void purple() {
  printf("\033[1;35m");
}

void cyan() {
  printf("\033[1;36m");
}

void white() {
  printf("\033[1;37m");
}

void reset() {
  printf("\033[0m");
}

void clean_ptrs(char **double_ptr)
{
	char **tmp;

	tmp = double_ptr;
	while (*tmp) {
		free(*tmp);
		tmp++;
	}
	free(double_ptr);
}

char *char_to_str(char c)
{
	char *str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}



int main()
{ 
	red();
	printf("\nft_isalpha test: a and ?: %i, %i\n\n", ft_isalpha('a'),  ft_isalpha('?'));
	
	
	green();
	printf("ft_isdigit test: 2 and A: %i, %i\n\n", ft_isdigit('2'),  ft_isdigit('A'));
	
	
	yellow();
	printf("ft_isalnum test: 2 and A and @: %i, %i, %i\n\n", ft_isalnum('2'),  ft_isalnum('A'), 		ft_isalnum('@'));
	
	
	blue();
	printf("ft_ascii test: 127 and 130: %i, %i\n\n", ft_isascii(127),  ft_isascii(130));
	
	
	purple();
	printf("ft_isprint test: \\n and ?: %i, %i\n\n", ft_isprint('\n'),  ft_isprint('?'));
	
	
	cyan();
	char str[] = "I have 19 caracters";
	printf("ft_strlen test: \"I have 19 caracters\": %li\n\n", ft_strlen(str));
	
	
	red();
	char buffer[11];
	ft_bzero(buffer,11);
	ft_memset(buffer, 'c', sizeof(char) * 10);
	printf("ft_memset test: Set \'c\' to buffer: %s\n\n", buffer);
	
	
	green();
	ft_bzero(buffer,11);
	printf("ft_bzero test: buffer parsed through ft_bzero: %s\n int print:", buffer);
	for (int i = 0; i < 11; i++)
		printf("%d", buffer[i]);
	printf("\n\n");
	for (int i = 0; i < 11; i++)
		printf("%p\n", &buffer[i]);
	printf("\n\n");
	
	
	yellow();	
	char src[] = "hola que tall?";
	char dest[] = "Jo no soi marinero";
	printf("ft_memcpy test before: %s, %s\n", src, dest);
	ft_memcpy(dest, src, 12);
	printf("ft_memcpy test after: %s, %s\n\n", src, dest);
	
	
	blue();
	/*reset dest to "Jo no soi marinero"*/
	ft_memcpy(dest, "Jo no soi marinero", 18);
	printf("ft_memmove test before: %s, %s\n", src, dest);
	ft_memmove(dest, src, 12);
	printf("ft_memmove test after: %sstrchr, %s\n\n", src, dest);
	
	
	
	purple();
	/*reset dest to "Jo no soi marinero" again*/
	ft_memcpy(dest, "Jo no soi marinero", 18);
	printf("ft_strlcpy test before: %s, %s\n", src, dest);
	ft_strlcpy(dest, src, 19);
	printf("ft_strlcpy test after: %s, %s\n\n", src, dest);
	
	
	cyan();
	char dest1[20] = "this and ";
	char src1[5] = "that";
	printf("ft_strlcat test before: %s, %s\n", src1, dest1);
	ft_strlcat(dest1, src1, 20);
	printf("ft_strlcat test after: %s, %s\n\n", src1, dest1);
	
	
	red();
	char mario = 'm';
	printf("ft_toupper test: Mario: %c, Mario after mushrooms: %c\n\n", mario,   ft_toupper(mario));
	
	
	green();
	char mario2 = 'M';
	printf("ft_tolower test: Mario after mushrooms: %c, Mario after koopa: %c\n\n", mario2, 		ft_tolower(mario2));
	
	
	yellow();
	char email[] = "luizbaron@hotmail.com";
	printf("ft_strchr test: this is my e-mail server: %s\n\n", ft_strchr(email, '@'));
	
	
	blue();
	char a[] = "aaaa";
	char b[] = "aaaa";
	char c[] = "abba";
	char d[] = "baba";
	printf("ft_strncmp test: %i, %i, %i, limit n: %i, %i\n\n", ft_strncmp(c, d, 4), 		ft_strncmp(a, b, 4), ft_strncmp(d, c, 4), ft_strncmp(b, c, 1), ft_strncmp(d, a, 1));
	
	
	purple();
	char data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	char *pos = ft_memchr(data, 'e', 6);
	printf("ft_memchr test:\ngiven arrai char data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};\ninput: char *pos = ft_memchr(data, 'e', 6)\n");
	printf("pos[0] = %c, pos[1] = %c\n\n", pos[0], pos[1]);
	
	
	cyan();
	printf("ft_memcmp test: %i, %i, %i, limit n: %i, %i\n\n", ft_memcmp(c, d, 4), 		ft_memcmp(a, b, 4), ft_memcmp(d, c, 4), ft_memcmp(b, c, 1), ft_memcmp(d, a, 1));
	
	
	red();
	char haystack[] = "This is the way";
	char needle[] = "the";
	char *the = ft_strnstr(haystack, needle, 12);
	printf("ft_strnstr test: %s\n\n", the);
	
	
	green(); 
	char ascii[] = "21";
	printf("ft_atoi test: %d is the meaning of life!\n\n", ft_atoi(ascii) + 21);
	
	
	yellow();
	char *array = (char *)ft_calloc(10, sizeof(char));
	printf("ft_calloc test: ");
	for (int i = 0; i < 10; i++)
		printf("%d", array[i]);		
	printf("\n\n");
	for (int i = 0; i < 10; i++)
		printf("%p\n", &array[i]);
	printf("\n\n");
	free(array);
	
	
	blue();
	char word[] = "I will be cloned!!";
	char *clone;
	clone = ft_strdup(word);
	printf("ft_strdup test: \n%s\n%s\n\n", word, clone);
	printf("adress of the word: %p\nadress of the clone: %p\n\n", &word, &clone);
	free(clone);
	
	
	purple();
	char sub[] = "lalalaI will be cutedlalala";
	char *subed = ft_substr(sub, 6, 15);
	printf("ft_substr test: %s\n\n", subed);
	free(subed);
	
	
	cyan();
	char first[] = "this and ";
	char second[] = "that!";
	char *joined = ft_strjoin(first, second);
	printf("ft_strjoin test: %s\n\n", joined);
	free(joined);

	red();
	char paper[] = "abcI, was trimed!abcabc";
	char scissors[] = "bca";
	char *trimmed = ft_strtrim(paper, scissors);
	printf("ft_strtrim test: %s\n\n", trimmed);
	free(trimmed);
	
	
	green();
	char *apple = "im about to be splited";
	char spliter = ' ';
	char **splited = ft_split(apple, spliter);
	printf("ft_split test:\n\n");
	for(int i = 0; splited[i] != NULL; i++)
		printf("%d %s\n\n", i, splited[i]);
	clean_ptrs(splited);
		
	yellow();
	int i = 0x2A;
	char *hex = ft_itoa(i);
	printf("ft_itoa test: in hexadecimal the mining of life is \"0x%x\", but in reality is: %s\n\n", i, hex);
	free(hex);
	
	
char cipher(unsigned int i, char c) {
return c + i % 2;
}

	blue();
	char power_up[] = "by the powers of grayskull";
	char *mapped = ft_strmapi(power_up, cipher);
	printf("ft_strmapi test: %s\n\n", mapped);
	free(mapped);

	void add_exclamation_mark(unsigned int i, char *c) {
*c = *c + (i / i);
}

	purple();
	char s[] = "abcdefg";
	ft_striteri(s, add_exclamation_mark);
	printf("ft_striteri test: %s\n\n", s);


  ft_putchar_fd('H', 1);
	ft_putchar_fd('i', 1);
  ft_putchar_fd(',', 1);
  ft_putchar_fd(' ', 1);
	
	ft_putstr_fd("Welcome to ", 1);

	ft_putnbr_fd(42, 1);

	ft_putendl_fd(" \\o/", 1);
    reset();
}
