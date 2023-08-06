/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytorigoe <ytorigoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:12:19 by yut               #+#    #+#             */
/*   Updated: 2023/08/06 20:37:15 by ytorigoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, (char *)s1, len);
	return (dest);
}

// int main()
// {
// 	char *ptr1 = ft_strdup("hello");
// 	char *ptr2 = strdup("hello");

// 	printf("%d\n",(ptr1 == ptr2));
// }