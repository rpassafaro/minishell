#include "libft.h"
#include <stdio.h>

void	test_memset(char *str, char c, int n)
{
		char *s1 = ft_strdup(str);
		char *s2 = ft_strdup(s1);
		char *out2 = memset(s2, c, n);
		char *out1 = ft_memset(s1, c, n);
		if (ft_strequ((const char *)out1, (const char *)out2))
			printf("Pass -- memset: %s\n\tft_memset: %s\n", out1, out2);
		else    			
			printf("Fail -- memset: %s\n\t    ft_memset: %s\n", out1, out2);
		// memset(s1, '\0', ft_strlen(s1));
		// memset(s2, '\0', ft_strlen(s2));
		free(s1);
		free(s2);
		memset(out1, '\0', ft_strlen(out1));
		memset(out2, '\0', ft_strlen(out2));


}

void	test_bzero(void *s, size_t n)
{
	char *s3 = ft_strdup(s);
	char *s4 = ft_strdup(s3);
	bzero(s3, n);
 	ft_bzero(s4, n);
	if (ft_strequ((const char *)s3, (const char *)s4))
		printf("Pass -- bzero: %s\n\tft_bzero: %s\n", s3, s4);
	else 
		printf("Fail -- bzero: %s\n\tft_bzero: %s\n", s3, s4);
	// memset(s1, '\0', ft_strlen(s1));
	// memset(s2, '\0', ft_strlen(s2));
	free(s3);
	free(s4);
	
}

void	test_memcpy(char *dest, const char *src, size_t n)
{
	char *d5 = ft_strdup(dest);
	char *d6 = ft_strdup(d5);
	char *s5 = ft_strdup((char *)src);
	char *s6 = ft_strdup(s5);
	char *out5 = memcpy(d5, (const char *)s5, n);
	char *out6 = ft_memcpy(d6, (const char *)s6, n);
	if (ft_strequ((const char *)out5, (const char *)out6))
		printf("Pass -- memcpy: %s\n\tft_memcpy: %s\n", out5, out6);
	else 
		printf("Fail -- memcpy: %s\n\tft_memcpy: %s\n", out5, out6);
	// free(d5);
	// free(d6);
	// free(s5);
	// free(s6);
}

void	test_memccpy(char *dest2, const char *src2, int c, size_t n)
{
	char *d7 = ft_strdup(dest2);
	char *d8 = ft_strdup(d7);
	char *s7 = ft_strdup((char *)src2);
	char *s8 = ft_strdup(s7);
	char *out7 = memccpy(d7, (const char *)s7, c, n);
	char *out8 = ft_memccpy(d8, (const char *)s8, c, n);
	if (out7 == NULL && out8 == NULL)
		printf("Pass -- memccpy: %s\n\tft_memccpy: %s\n", out7, out8);
	else if (ft_strequ((const char *)out7, (const char *)out8))
		printf("Pass -- memccpy: %s\n\tft_memccpy: %s\n", out7, out8);
	else 
		printf("Fail -- memccpy: %s\n\tft_memccpy: %s\n", out7, out8);
	free(d7);
	free(d8);
	free(s7);
	free(s8);

}

void	test_memmove(char *d_est, const char *s_rc, size_t n)
{
	char *d9 = ft_strdup(d_est);
	char *d10 = ft_strdup(d9);
	char *s9 = ft_strdup((char *)s_rc);
	char *s10 = ft_strdup(s9);
	char *out9 = memmove(d9, (const char *)s9, n);
	char *out10 = ft_memmove(d10, (const char *)s10, n);
	if (ft_strequ((const char *)out9, (const char *)out10))
		printf("Pass -- memmove: %s\n\tft_memmove: %s\n", out9, out10);
	else 
		printf("Fail -- memmove: %s\n\tft_memmove: %s\n", out9, out10);
	free(d9);
	free(d10);
	free(s9);
	free(s10);
}

void	test_memchr(char *str, int c, size_t n)
{
	char *mch = ft_strdup(str);
	char *ft_mc = ft_strdup(mch);
	char *res1 = memchr((const char *)mch, c, n);
	char *res2 = ft_memchr((const char *)ft_mc, c, n);
	if (res1 == NULL && res2 == NULL)
		printf("Pass -- memchr: %s\n\tft_memchr: %s\n", res1, res2);
	else if(res1 == NULL || res2 == NULL)
		printf("Fail -- memchr: %s\n\tft_memchr: %s\n", res1, res2);
	else if (ft_strequ((const char *)res1, (const char *)res2))
		printf("Pass -- memchr: %s\n\tft_memchr: %s\n", res1, res2);
	else 
		printf("Fail -- memchr: %s\n\tft_memchr: %s\n", res1, res2);
	free(mch);
	free(ft_mc);
}

void	test_memcmp(char *s1, char *s2, size_t n)
{
	char *st1 = ft_strdup(s1);
	char *st2 = ft_strdup(s2);
	char *ft_str1 = ft_strdup(st1);
	char *ft_str2 = ft_strdup(st2);
	int first = memcmp((const void *)st1, (const void *)st2, n);
	int second = ft_memcmp((const void *)ft_str1, (const void *)ft_str2, n);
	if (first == second)
		printf("Pass -- memcmp: %d\n\tft_memcmp: %d\n", first, second);
	else 
		printf("Fail -- memcmp: %d\n\tft_memcmp: %d\n", first, second);
	free(st1);
	free(st2);
	free(ft_str1);
	free(ft_str2);

}

void	test_strlen(const char *str)
{
	char *str1 = ft_strdup(str);
	char *str2 = ft_strdup(str1);
	size_t len1 = strlen((const char *)str1);
	size_t len2 = ft_strlen((const char *)str2);
	if (len1 == len2)
		printf("Pass -- strlen: %zu\n\tft_strlen: %zu\n", len1, len2);
	else 
		printf("Fail -- strlen: %zu\n\tt_strlen: %zu\n", len1, len2);
	free(str1);
	free(str2);

}

void	test_strdup(const char *str)
{
	char *str_1 = strdup(str);
	char *str_2 = ft_strdup(str);
	if (ft_strequ((const char *)str_1, (const char *)str_2))
		printf("Pass -- strdup: %s\n\tft_strdup: %s\n", str_1, str_2);
	else 
		printf("Fail -- strdup: %s\n\tft_strdup: %s\n", str_1, str_2);
	free(str_1);
	free(str_2); 
}

void	test_strcpy(char *dest, char *src)
{
	char *dest1 = ft_strdup(dest);
	char *dest2 = ft_strdup(dest1);
	char *src1 = ft_strdup(src);
	char *src2 = ft_strdup(src1);
	char *out1 = strcpy(dest1, (const char *)src1);
	char *out2 = ft_strcpy(dest2, (const char *)src2);
	if (ft_strequ((const char *)out1, (const char *)out2))
		printf("Pass -- strcpy: %s\n\tft_strcpy: %s\n", out1, out2);
	else 
		printf("Fail -- strcpy: %s\n\tft_strcpy: %s\n", out1, out2);
	free(dest1);
	free(dest2);
	free(src1);
	free(src2);
}

void	test_strncpy(char *dest, char *src, size_t n)
{
	char *de1 = ft_strdup(dest);
	char *de2 = ft_strdup(de1);
	char *rc1 = ft_strdup(src);
	char *rc2 = ft_strdup(rc1);
	char *out1 = strncpy(de1, (const char *)rc1, n);
	char *out2 = ft_strncpy(de2, (const char *)rc2, n);
	if (ft_strequ((const char *)out1, (const char *)out2))
		printf("Pass -- strncpy: %s\n\tft_strncpy: %s\n", out1, out2);
	else 
		printf("Fail -- strncpy: %s\n\tft_strncpy: %s\n", out1, out2);
	// free(de1);
	// free(de2);
	// free(rc1);
	// free(rc2);
}

void	test_strcat(const char *dt, const char *sc)
{
	char *base1 = ft_strdup(dt);
	char *base2 = ft_strdup((const char *)base1);
	char *add1 = ft_strdup(sc);
	char *add2 = ft_strdup((const char *)add1);
	//printf("\ndest1: %s  dest2: %s  src1: %s src2: %s\n", dst1, dst2, sr1, sr2);
	char *first_cat = strcat(base1, (const char *)add1);
	char *second_cat = ft_strcat(base2, (const char *)add2);
	//printf("\nout1: %s   out2: %s\n", o1, o2);
	if (ft_strequ((const char *)first_cat, (const char *)second_cat))
		printf("Pass -- strcat: %s\n\tft_strcat: %s\n", first_cat, second_cat);
	else 
		printf("Fail -- strcat: %s\n\tft_strcat: %s\n", first_cat, second_cat);
	free(base1);
	free(base2);
	free(add1);
	free(add2);
}
void	test_strchr(const char *sor, int ch)
{
	char *sor1 = ft_strdup(sor);
	char *sor2 = ft_strdup(sor1);
	char *val1 = strchr(sor1, ch);
	char *val2 = ft_strchr(sor2, ch);
	if (val1 == NULL && val2 == NULL)
		printf("Pass -- strchr: %s\n\tft_strchr: %s\n", val1, val2);
	else if (ft_strequ(val1, val2))
		printf("Pass -- strchr: %s\n\tft_strchr: %s\n", val1, val2);
	else 
		printf("Fail -- strchr: %s\n\tft_strchr: %s\n", val1, val2);
}

void	test_strrchr(const char *sor, int ch)
{
	char *sor1 = ft_strdup(sor);
	char *sor2 = ft_strdup(sor1);
	char *val1 = strrchr(sor1, ch);
	char *val2 = ft_strrchr(sor2, ch);
	if (val1 == NULL && val2 == NULL)
		printf("Pass -- strrchr: %s\n\tft_strrchr: %s\n", val1, val2);
	else if (ft_strequ(val1, val2))
		printf("Pass -- strrchr: %s\n\tft_strrchr: %s\n", val1, val2);
	else 
		printf("Fail -- strrchr: %s\n\tft_strrchr: %s\n", val1, val2);
}

void	test_strstr(const char *sor, char *sub)
{
	char *sor1 = ft_strdup(sor);
	char *sor2 = ft_strdup(sor1);
	char *sub1 = ft_strdup(sub);
	char *sub2 = ft_strdup(sub1);
	char *val1 = strstr(sor1, sub1);
	char *val2 = ft_strstr(sor2, sub2);
	if (val1 == NULL && val2 == NULL)
		printf("Pass - strstr: %s    ft_strstr: %s\n", val1, val2);
	else if (ft_strequ(val1, val2))
		printf("Pass - strstr: %s    ft_strstr: %s\n", val1, val2);
	else 
		printf("Fail - strstr: %s   ft_strstr: %s\n", val1, val2);
}

void	test_strnstr(char *dest, char *src, size_t n)
{
	char *dest1 = ft_strdup(dest);
	char *dest2 = ft_strdup(dest1);
	char *src1 = ft_strdup(src);
	char *src2 = ft_strdup(src1);
	char *out1 = strnstr(dest1, (const char *)src1, n);
	char *out2 = ft_strnstr(dest2, (const char *)src2, n);
	if (out1 == NULL && out2 == NULL)
		printf("Pass - strnstr: %s    ft_strnstr: %s\n", out1, out2);
	else if (out1 == NULL || out2 == NULL)
		printf("Fail - strnstr: %s   ft_strnstr: %s\n", out1, out2);
	else if (ft_strequ((const char *)out1, (const char *)out2))
		printf("Pass - strnstr: %s    ft_strnstr: %s\n", out1, out2);
	else 
		printf("Fail - strnstr: %s   ft_strnstr: %s\n", out1, out2);
	// free(de1);
	// free(de2);
	// free(rc1);
	// free(rc2);
}

void	test_itoa(int c)
{

	char *out2 = ft_itoa(c);

		printf("Pass - itoa: %d    ft_itoa: %s\n", c, out2);

}

void	test_strcmp(char *dest, char *src)
{
	char *dest1 = ft_strdup(dest);
	char *dest2 = ft_strdup(dest1);
	char *src1 = ft_strdup(src);
	char *src2 = ft_strdup(src1);
	int out1 = strcmp((const char *)dest1, (const char *)src1);
	int out2 = ft_strcmp((const char *)dest2, (const char *)src2);
	if (out1 == out2)
		printf("Pass -- strcmp: %d\n\tft_strcmp: %d\n", out1, out2);
	else 
		printf("Fail -- strcmp: %d\n\tft_strcmp: %d\n", out1, out2);
}

void	test_strncmp(char *dest, char *src, int n)
{
	char *dest1 = ft_strdup(dest);
	char *dest2 = ft_strdup(dest1);
	char *src1 = ft_strdup(src);
	char *src2 = ft_strdup(src1);
	int out1 = strncmp((const char *)dest1, (const char *)src1, n);
	int out2 = ft_strncmp((const char *)dest2, (const char *)src2, n);
	if (out1 == out2)
		printf("Pass -- strncmp: %d\n\tft_strncmp: %d\n", out1, out2);
	else 
		printf("Fail -- strncmp: %d\n\tft_strncmp: %d\n", out1, out2);
}
void	run_tests(void)
{
	test_memset("This is the string test", '#', 8);
	test_memset("     ", '$', 10);
	test_memset("Longer string ", ' ', 5);
	test_memset("", '^', 1);
	test_memset("T", '?', 0);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_bzero("This is the string test", 8);
	test_bzero("     ", 10);
	test_bzero("number > string length ", 25);
	test_bzero("",  1);
	test_bzero("This length is set to zero",  0);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_memcpy("Destination", "Source", 5);
	test_memcpy("Destination", "Source", 25);
	test_memcpy("", "Source", 4);
	test_memcpy("Destination", "Source", 0);
	test_memcpy("Destination", "Source", 3);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_memccpy("Destination", "Source", 101, 7);
	test_memccpy("Destination", "Source", 'u', 15);
	test_memccpy("Destination", "Source", 'e', 3);
	test_memccpy("Destination", "Source", 'D', 9);
	test_memccpy("Destination", "Source", 'S', 2);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_memmove("Destination", "Source", 7);
	test_memmove("Destinatource", "Source", 9);
	test_memmove("DesSourmat", "Source", 10);
	test_memmove("Sourcination", "Source", 13);
	test_memmove("Destination", "nation", 2);
	test_memmove("Destination", "nation", 0);
	test_memmove("  ", "Source", 7);
	test_memmove("Destination", "   ", 8);
	test_memmove("", "Souce", 6);
	test_memmove("Destination", "", 18);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_memchr("Hello World", 'o', 6);
	test_memchr("Hello Wordl", 'o', 3);
	test_memchr("StringMan", 'm', 9);
	test_memchr("StringMan", 'M', 9);
	test_memchr("ReturnValue", 't', 0);
	test_memchr("Seperated Words", ' ', 18);
	test_memchr("This is! a sentence", '!', 45);
	test_memchr("   ", 'i', 7);
	test_memchr("   ", ' ', 5);
	test_memchr("", 'r', 4);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_memcmp("First String", "Second String", 7);
	test_memcmp("First String", "Second String", 15);
	test_memcmp("String First", "String Second", 3);
	test_memcmp("String First", "String Second", 7);
	test_memcmp("Same String", "Same String", 2);
	test_memcmp("Same String", "Same String", 7);
	test_memcmp("nothen", "Not Same String", 16);
	test_memcmp("different", "Not Same String", 5);
	test_memcmp("Same String", "Same String", 0);
	test_memcmp("Empty String", " ", 7);
	test_memcmp("CASE SENSITIVE", "case sensitive", 9);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strlen("Apples Sauce");
	test_strlen("9990000");
	test_strlen("        ");
	test_strlen("");
	test_strlen("\n\n\n\n\n\n");
	test_strlen("this is a sentence");
	test_strlen("++++++++++");
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strdup("A sentence");
	test_strdup("ONEBIGWORD");
	test_strdup("13256499");
	test_strdup("     ");
	test_strdup("");
	test_strdup("*********++++++++");
	test_strdup("\n\n\n\t\t\t");
	test_strdup(" ");
	test_strdup("t");
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strcpy("Desination", "Source");
	test_strcpy("Desi", "Source");
	test_strcpy("Desination", "");
	test_strcpy("Desination", " ");
	test_strcpy("", "Source");
	test_strcpy(" ", "Source");
	test_strcpy("Desination", "S");
	test_strcpy("D", "D");
	test_strcpy("999557", "words");
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strncpy("Desination", "Source", 5);
	test_strncpy("Desi", "Source", 9);
	test_strncpy("Desination", "", 100);
	test_strncpy("Desination", " ", 5);
	test_strncpy("", "Source", 0);
	test_strncpy(" ", "Source", 1);
	test_strncpy("Desination", "S", 1);
	test_strncpy("D", "D", 2);
	test_strncpy("999557", "words", 5);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strcat("First", "Second");
	test_strcat("Desin", "");
	test_strcat("Nvim ation", " ");
	test_strcat("", "Sorce");
	test_strcat(" ", "Srce");
	test_strcat("Dation", "S");
	test_strcat("D", "D");
	test_strcat("999557", "words");
	test_strcat("Dest", "Source");
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strchr("Cabbage", 'g');
	test_strchr("Cabbage", 'b');
	test_strchr("Its all nonsense", 'I');
	test_strchr("Another String", 'r');
	test_strchr("Another String", 'g');
	test_strchr("Aaron Hunt", ' ');
	test_strchr("terrific", 'z');
	test_strchr("", 'g');
	test_strchr("  ", 'g');
	test_strchr("It's a new line", '\'');
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strrchr("Cabbage", 'g');
	test_strrchr("Cabbage", 'b');
	test_strrchr("Its all nonsense", 'I');
	test_strrchr("Another String", 'r');
	test_strrchr("Another String", 'g');
	test_strrchr("Aaron Hunt", ' ');
	test_strrchr("terrific", 'z');
	test_strrchr("", 'g');
	test_strrchr("  ", 'g');
	test_strrchr("It's a new line", '\'');
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strstr("Cabbage", "g");
	test_strstr("Cabbage", "bag");
	test_strstr("Its all nonsense", "non");
	test_strstr("Another String", "other");
	test_strstr("Another String", "g");
	test_strstr("Aaron Hunt", " ");
	test_strstr("terrific", "z");
	test_strstr("", "g");
	test_strstr("  ", "g");
	test_strstr("It's a new line", "\'");
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strnstr("Waka flaka flame", "flaka", 15);
	test_strnstr("Waka flake flame", "flake", 10);
	test_strnstr("Its all nonsense", "non", 18);
	test_strnstr("Tupac is alive", "dead", 777);
	test_strnstr("Tupac is alive", "alive", 15);
	test_strnstr("Johnny Bannanas", " ", 8);
	test_strnstr("Johnny Bannanas", "", 8);
	test_strnstr(" ", " ", 1);
	test_strnstr("  ", "g", 0);
	test_strnstr("It's a new line", "\'", 7);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strcmp("Suuhh duudde", "Suuhh duudde");
	test_strcmp("    suh     ", "    suh     ");
	test_strcmp("Nope", "Yupp");
	test_strcmp(" ", " ");
	test_strcmp("  ", " ");
	test_strcmp("", "empty");
	test_strcmp("empty", "");
	test_strcmp("lololol", "lololol");
	test_strcmp("ooooo", "ooooo ");
	test_strcmp("\'\\","\'\\");
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_strncmp("Suuhh duudde", "Suuhh duudde", 15);
	test_strncmp("    suh     ", "    suh     ", 20);
	test_strncmp("Nope", "Yupp", 7);
	test_strncmp(" ", " ", 5);
	test_strncmp("  ", " ", 1);
	test_strncmp("", "empty", 3);
	test_strncmp("empty", "", 3);
	test_strncmp("lololol", "lololol", 0);
	test_strncmp("ooooo", "ooooo ", 5);
	test_strncmp("\'\\","\'\\", 3);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");

	test_itoa(12345);
	test_itoa(35462770);
	test_itoa(-6798);
	test_itoa(10001);
	test_itoa(10000);
	test_itoa(-5);
	printf("  ---------------------------------------------------------");
	printf("-------------------  \n");
}

int main(void)
{
	run_tests();
	return (0);	
}
