/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:52:35 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/19 15:40:42 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_char(char *str, int x, char c)
{
	int		i;
	char	*first;
	char	*second;
	char	*retour;

	i = 0;
	if (!(first = malloc(sizeof(char) * (x + 1))))
		return (NULL);
	while (i < x)
	{
		first[i] = str[i];
		i++;
	}
	first[i] = '\0';
	if (!(first = ft_strjoin_one(first, c)))
		return (NULL);
	if (!(second = ft_substr(str, x, ft_strlen(str) - x)))
		return (NULL);
	if (!(retour = ft_strjoin(first, second)))
		return (NULL);
	free(second);
	free(str);
	return (retour);
}
