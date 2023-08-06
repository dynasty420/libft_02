/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytorigoe <ytorigoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:27:01 by yut               #+#    #+#             */
/*   Updated: 2023/08/06 20:08:47 by ytorigoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
//     {
//     char str11[1024] = "0123456789";
//     char str12[1024] = "0123456789";
//     char dst[1024] = "ABCDEFGHIJ";
//     ft_memcpy(str11, dst, 6);
//     memcpy(str12, dst, 6);
//     printf("jisaku  : %s\n", str11);
//     printf("library : %s\n", str12);

// }