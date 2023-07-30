/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yut <yut@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:23:37 by yut               #+#    #+#             */
/*   Updated: 2023/07/21 18:44:59 by yut              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	i;
	size_t	n;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n] != '\0')
	{
		s3[i + n] = s2[n];
		n++;
	}
	s3[i + n] = '\0';
	return (s3);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// void ft_check(const char *s1, const char *s2)
// {
// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	return ;
// }

// #include <string.h>

// int main()
// {
//     printf("%s\n", ft_strjoin("hello", "world"));
// }
