/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:45:05 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/20 11:39:58 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_emptystring(void)
{
	char *retour;

	if (!(retour = malloc(sizeof(char) * 1)))
		return (NULL);
	retour[0] = '\0';
	return (retour);
}

char				*ft_annexe(void)
{
	char *retour;

	if (!(retour = malloc(sizeof(char))))
		return (NULL);
	retour[0] = 0;
	return (retour);
}

char				*ft_substr(char const *s, int start, size_t len)
{
	int		i;
	int		y;
	char	*retour;

	if (!s)
		return (0);
	y = 0;
	i = 0;
	if (len == 0)
		return (ft_annexe());
	if (start >= ft_strlen((char *)s))
		return (ft_emptystring());
	while (i < start)
		i++;
	if (!(retour = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (y < (int)len)
	{
		retour[y] = s[i];
		i++;
		y++;
	}
	retour[y] = '\0';
	return (retour);
}
