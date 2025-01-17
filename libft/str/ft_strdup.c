/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:37 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/17 17:27:32 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*ret;
	unsigned long	alloc_size;
	unsigned long	i;

	if (!str)
		return (NULL);
	alloc_size = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (alloc_size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strfdup(char *str)
{
	char	*ret;

	ret = ft_strdup(str);
	free(str);
	return (ret);
}
