/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yut <yut@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 05:29:44 by yut               #+#    #+#             */
/*   Updated: 2023/07/22 18:18:44 by yut              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("%zu\n", strlen("Hello"));
//     printf("%zu\n", ft_strlen("Hello"));
// }
