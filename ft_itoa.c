/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryamagis <ryamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:59:03 by ryamagis          #+#    #+#             */
/*   Updated: 2023/09/11 16:19:09 by ryamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digits(int n)
{
	size_t	i;

	i = 1;

	while (n /= 10)
		i++;
	return(i);
}

char *ft_itoa(int n)
{
	char	*str;
	int	digits;
	int	negative;
	long int	num;

	num = n;
	digits = count_digits(n);
	negative = 0;
	if (num < 0)
	{
		num *= -1;
		negative = -1;
		digits++;
	}
	str = (char*)malloc(sizeof(char) * (digits + 1));
	if(!str)
		return (NULL);
	*(str + digits) = '\0';
	digits--;
	while((digits > 0 && negative == -1) || (digits >= 0 && negative == 0))
	{
		*(str + digits) = num % 10 + '0';
		num /= 10;
		digits--;
	}
	if(negative == -1)
		*(str + digits) = '-';
	return (str);
}
