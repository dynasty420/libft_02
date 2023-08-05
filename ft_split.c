/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yut <yut@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:53:38 by yut               #+#    #+#             */
/*   Updated: 2023/08/05 22:50:52 by yut              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwrd(char const *s, char c);
static int	store_word(char **ans, int k, int strlen, char *src);
static char	**ft_setwords(char **ans, char *str, char c, int strs_count);
static void	*ft_free(char **str, int cntr);

char	**ft_split(char const *s, char c)
{
	int		strs_count;
	char	**ans;
	char	**result;

	if (s == NULL)
		return (NULL);
	strs_count = ft_cntwrd(s, c);
	ans = (char **)malloc(sizeof(char *) * (strs_count + 1));
	if (ans == NULL)
		return (NULL);
	result = ft_setwords(ans, (char *)s, c, strs_count);
	if (result == NULL)
		return (NULL);
	return (result);
}

static int	ft_cntwrd(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			cntr++;
			i++;
		}
		while (s[i] != '\0' && (s[i] != c))
			i++;
	}
	return (cntr);
}

static int	store_word(char **ans, int k, int strlen, char *src)
{
	int	i;

	ans[k] = malloc(sizeof(char) * (strlen + 1));
	if (ans[k] == NULL)
	{
		ft_free(ans, k);
		return (0);
	}
	i = 0;
	while (i < strlen)
	{
		ans[k][i] = src[i];
		i++;
	}
	ans[k][i] = '\0';
	return (1);
}

static char	**ft_setwords(char **ans, char *str, char c, int strs_count)
{
	int	i;
	int	k;
	int	strlen;

	i = 0;
	k = 0;
	while (k < strs_count)
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		strlen = 0;
		while (str[i] != '\0' && str[i] != c)
		{
			strlen++;
			i++;
		}
		if (store_word(ans, k, strlen, &str[i - strlen]) == 0)
			return (NULL);
		k++;
	}
	ans[k] = NULL;
	return (ans);
}

static void	*ft_free(char **str, int cntr)
{
	int	i;

	i = 0;
	while (i < cntr)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

// int	main(void)
// {
// 	char	**expected = ft_split("daadbbb", 'd');
// 	printf("The result is: %s\n", expected[0]);
// 	printf("The result is: %s\n", expected[1]);
// 	char *str = "aa  bbb cc";
// 	char **result = ft_split(str, ' ');
// 	printf("The result is: %s\n", result[0]);
// 	printf("The result is: %s\n", result[1]);
// 	printf("The result is: %s\n", result[2]);
// 	printf("The result is: %s\n", result[3]);
// 	printf("The result is: %s\n", result[4]);
// 	printf("The result is: %s\n", result[5]);
// 	printf("The result is: %s\n", result[6]);

// 	return (0);
// }