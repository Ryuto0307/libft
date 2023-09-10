/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryamagis <ryamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:48:20 by ryamagis          #+#    #+#             */
/*   Updated: 2023/09/10 20:06:14 by ryamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if(!s)
		return (NULL);
	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
