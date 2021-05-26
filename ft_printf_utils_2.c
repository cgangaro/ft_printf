/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:54:11 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/12 18:29:46 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_replace_first(char a, char *b, char *str)
{
	int		i;
	char	*first;
	char	*second;
	char	*retour;

	i = 0;
	while (str[i] && str[i] != a)
		i++;
	first = ft_substr(str, 0, i);
	second = ft_substr(str, i + 1, ft_strlen(str + i + 1));
	retour = ft_strjoin(first, b);
	retour = ft_strjoin(retour, second);
	free(second);
	free(str);
	free(b);
	return (retour);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		y;
	char	*retour;
	int		taille;

	taille = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	y = 0;
	if (!(retour = malloc(sizeof(char) * (taille + 1))))
		return (0);
	while (s1[i])
	{
		retour[i] = s1[i];
		i++;
	}
	while (s2[y] && s2 != NULL)
	{
		retour[i] = s2[y];
		i++;
		y++;
	}
	retour[i] = '\0';
	free(s1);
	return (retour);
}

char	*ft_strjoin_one(char *s1, char c)
{
	int		i;
	int		y;
	char	*retour;
	int		taille;

	taille = ft_strlen(s1) + 1;
	i = 0;
	y = 0;
	if (!(retour = malloc(sizeof(char) * (taille + 1))))
		return (0);
	while (s1[i])
	{
		retour[i] = s1[i];
		i++;
	}
	retour[i] = c;
	retour[i + 1] = '\0';
	free(s1);
	return (retour);
}

char	*ft_string_filled(char c, int size)
{
	int		i;
	char	*retour;

	i = 0;
	if (!(retour = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		retour[i] = c;
		i++;
	}
	retour[i] = '\0';
	return (retour);
}

char	*ft_putchar(char c)
{
	char *s;

	if (!(s = malloc(sizeof(char) * 2)))
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}
