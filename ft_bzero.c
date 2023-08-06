/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytorigoe <ytorigoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:04:56 by yut               #+#    #+#             */
/*   Updated: 2023/08/06 20:37:09 by ytorigoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (n == 0)
		return ;
	tmp = s;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// char str1[1024] = "AAAAA";
// char *str2 = 0;
// bzero(str1, 100);
// str2 = (char *)str1;
// printf("1 : %s\n", (char *)str1);

// char str[50];
// strcpy(str, "This is string.h library function");
// puts(str);
// bzero(str,20);
// puts(str);
// return (0);

// 	bzero(str1("AAAAA",3));
// 	char str2[1024] = bzero(str2("AAAAA",0));
// 	char str3[1024] = bzero(str3("AAAAA",3));
// 	char str4[1024] = bzero(str4("AAAAA",0));

// 	printf("1 : %s\n", str1);
// 	printf("A : %s\n", str2);
// 	printf("A : %s\n", str3);
// 	printf("1 : %s\n", str4);
// }