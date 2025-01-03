/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:02:42 by bama              #+#    #+#             */
/*   Updated: 2024/11/17 17:27:27 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdelete(char *str, int start, int del_len)
{
	char	*ret;
	int		size;
	int		i;
	int		j;

	if (del_len > (int)ft_strlen(str))
		return (NULL);
	size = ft_strlen(str) - del_len;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && i < start)
	{
		ret[i] = str[i];
		i++;
	}
	j = i;
	i += del_len;
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = 0;
	return (ret);
}

char	*ft_strfdelete(char *str, int start, int del_len)
{
	char	*ret;
	int		size;
	int		i;
	int		j;

	if (del_len > (int)ft_strlen(str))
		return (NULL);
	size = ft_strlen(str) - del_len;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && i < start)
	{
		ret[i] = str[i];
		i++;
	}
	j = i;
	i += del_len;
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = 0;
	free(str);
	return (ret);
}
