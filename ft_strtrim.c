/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yut <yut@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:42:05 by yut               #+#    #+#             */
/*   Updated: 2023/08/06 17:29:20 by yut              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(const char *set, char c);
static char	*new_str(const char *str, size_t start, size_t end);
char		*ft_strtrim(const char *str, const char *set);

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	ssize_t	end;
	size_t	len;

	if (str == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(str) - 1;
	while (to_trim(set, str[start]) == 1)
		start++;
	while (to_trim(set, str[end]) == 1)
		end--;
	len = end - start + 1;
	return (new_str(str, start, len));
}

static char	*new_str(const char *str, size_t start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (len == 0 || start >= ft_strlen(str))
		return (ft_strdup(""));
	new_str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[start + i];
		i++;
	}
	return (new_str);
}

static int	to_trim(const char *set, char c)
{
	int	k;

	k = 0;
	while (set[k] != '\0')
	{
		if (set[k] == c)
			return (1);
		k++;
	}
	return (0);
}

// int main()
// {
//  	char str1[100] = "ababaaaMy name is Simonbbaaabbab";
//  	char str2[100] = "ab";

//  	char *result = ft_strtrim(str1,str2);
//  	printf("The result is: %s\n", result);
//  	return (0);
// }