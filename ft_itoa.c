/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yut <yut@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:20:36 by yut               #+#    #+#             */
/*   Updated: 2023/07/23 15:49:36 by yut              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr);
static char	*pre_conv(int len);

char	*ft_itoa(int n)
{
	int			len;
	int			i;
	char		*result;
	long long	nbr;

	nbr = n;
	len = int_len(nbr);
	result = pre_conv(len);
	if (result == NULL)
		return (NULL);
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

static char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

// int main()
// {
//  	int a = -5;
//  	char *result = ft_itoa(a);
//  	printf("The result is: %s\n", result);
//  	return (0);
// }