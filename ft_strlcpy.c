/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yut <yut@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:42:20 by yut               #+#    #+#             */
/*   Updated: 2023/08/06 16:14:09 by yut              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src == NULL || dst == NULL)
		return (0);
	if (dstsize == 0)
		return (src_len);
	if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else
	{
		ft_memcpy(dst, src, dstsize - 1);
		ft_memcpy(dst + dstsize - 1, "\0", 1);
	}
	return (src_len);
}

// int main()
// {

// 	// char *ptr1 = malloc(10 * sizeof(char));
// 	// char *ptr2 = malloc(100 * sizeof(char));
// 	// char *ptr3 = malloc(10 * sizeof(char));

// 	char ptr1[100] ="AAAAAAA";
// 	char ptr3[100] ="CCCCCCC";

// 	// malloc(10 * sizeof(char));
// 	// char *ptr2 = malloc(10 * sizeof(char));
// 	strlcpy(ptr1, "hello", 3);
// 	ft_strlcpy(ptr3, "hello", 3);
// 	printf("%s\n", ptr1);
// 	printf("%s\n", ptr3);
// }
