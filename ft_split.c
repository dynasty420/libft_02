/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yut <yut@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:53:38 by yut               #+#    #+#             */
/*   Updated: 2023/08/06 17:32:26 by yut              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwrd(char const *str, char c);
static char	**ft_setwords(char **tmp, char *str, char c, size_t col_num);
static int	array_row(char **tmp, size_t k, size_t rowlen, char *src);
static void	*ft_free(char **str, size_t col_num);

char	**ft_split(char const *str, char c)
{
	size_t	col_num;
	char	**tmp;
	char	**array;

	if (str == NULL)
		return (NULL);
	col_num = ft_cntwrd(str, c);
	tmp = (char **)malloc(sizeof(char *) * (col_num + 1));
	if (tmp == NULL)
		return (NULL);
	array = ft_setwords(tmp, (char *)str, c, col_num);
	if (array == NULL)
		return (NULL);
	return (array);
}

static int	ft_cntwrd(char const *str, char c)
{
	size_t	i;
	size_t	col_num;

	i = 0;
	col_num = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			col_num++;
			i++;
		}
		while ((str[i] != '\0') && (str[i] != c))
			i++;
	}
	return (col_num);
}

static int	array_row(char **tmp, size_t col, size_t rowlen, char *src)
{
	tmp[col] = malloc(sizeof(char) * (rowlen + 1));
	if (tmp[col] == NULL)
	{
		ft_free(tmp, col);
		return (0);
	}
	ft_strlcpy(tmp[col], (const char *)src, rowlen + 1);
	tmp[col][rowlen] = '\0';
	return (1);
}

static char	**ft_setwords(char **tmp, char *str, char c, size_t col_num)
{
	size_t	i;
	size_t	col;
	size_t	rowlen;
	size_t	start;

	i = 0;
	col = 0;
	while (col < col_num)
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		rowlen = 0;
		while (str[i] != '\0' && str[i] != c)
		{
			rowlen++;
			i++;
		}
		start = i - rowlen;
		if (array_row(tmp, col, rowlen, &str[start]) == 0)
			return (NULL);
		col++;
	}
	tmp[col] = NULL;
	return (tmp);
}

static void	*ft_free(char **str, size_t col)
{
	size_t	i;

	i = 0;
	while (i < col)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

// int	main(void)
// {
// 	char	**test1;
// 	char	*str;
// 	char	**test2;
// 	char	**test3;

// 	test1 = ft_split("hello,world,42,tokyo", ',');
// 	printf("*expected[] = {hello,world,42,tokyo, NULL}\n");
// 	printf("The result is: %s\n", test1[0]);
// 	printf("The result is: %s\n", test1[1]);
// 	printf("The result is: %s\n", test1[2]);
// 	printf("The result is: %s\n", test1[3]);
// 	printf("The result is: %s\n", test1[4]);
// 	// char *expected[] = {"hello","world","42","tokyo", NULL};
// 	str = "aa  bb cc";
// 	test2 = ft_split(str, ' ');
// 	printf("*expected[] = {aa,bb,cc, NULL}\n");
// 	printf("The result is: %s\n", test2[0]);
// 	printf("The result is: %s\n", test2[1]);
// 	printf("The result is: %s\n", test2[2]);
// 	printf("The result is: %s\n", test2[3]);
// 	printf("The result is: %s\n", test2[4]);
// 	printf("The result is: %s\n", test2[5]);
// 	printf("The result is: %s\n", test2[6]);
// 	test3 = ft_split("", ',');
// 	printf("The result is: %s\n", test3[0]);
// 	printf("The result is: %s\n", test3[1]);
// 	printf("The result is: %s\n", test3[2]);
// 	return (0);
// }
