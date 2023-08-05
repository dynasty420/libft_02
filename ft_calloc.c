/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yut <yut@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:03:59 by yut               #+#    #+#             */
/*   Updated: 2023/08/05 22:46:33 by yut              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

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
		tmp[i] = '\0';
		i++;
	}
}

// int main()
// {
// 	char *ptr = ft_calloc(10, 10);
// 	printf("%s\n", ptr);
// 	printf("%p\n", ptr);
// 	printf("%lu\n", sizeof(ptr));
// }