/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytorigoe <ytorigoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:20:36 by yut               #+#    #+#             */
/*   Updated: 2023/08/06 20:36:20 by ytorigoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	res_len(ssize_t nbr);
static char	*res_dup(size_t len);

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	ssize_t	nbr;
	char	*result;

	nbr = n;
	len = res_len(nbr);
	result = res_dup(len);
	if (result == NULL)
		return (NULL);
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

static char	*res_dup(size_t len)
{
	char	*result;

	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	return (result);
}

static int	res_len(ssize_t nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

// int main()
// {
//  	printf("The result is: %s\n", ft_itoa(0));
//  	printf("The result is: %s\n", ft_itoa(-0));
//  	printf("The result is: %s\n", ft_itoa(+0));

//  	return (0);
// }