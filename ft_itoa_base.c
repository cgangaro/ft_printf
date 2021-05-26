/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:48:51 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/14 14:14:37 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_recursive(char *s, long long int nb, int y, char *base)
{
	int	i;

	i = ft_strlen(base);
	if (nb >= i)
	{
		s = ft_recursive(s, ((nb - (nb % i)) / i), y - 1, base);
		if (nb >= i)
			nb = nb % i;
	}
	s[y] = base[nb];
	return (s);
}

int		ft_nb_caract(long int n, int i)
{
	int				nb_caract;
	long long int	nb;
	long long int	nb2;

	nb_caract = 1;
	if (n < 0)
	{
		nb = n * -1;
		nb_caract++;
	}
	else
		nb = n;
	nb2 = nb;
	while ((nb = (nb / i)) >= i)
		nb_caract++;
	if (nb < i && nb2 >= i && nb2 != 0)
		nb_caract++;
	return (nb_caract);
}

char	*ft_itoa_base(long long n, char *base)
{
	char					*s;
	unsigned long long int	nb;
	int						i;
	int						y;

	i = ft_strlen(base);
	y = ft_nb_caract(n, i);
	if (!(s = ft_calloc(sizeof(char), y + 1)))
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		nb = n * -1;
	}
	else
		nb = n;
	s = ft_recursive(s, nb, y - 1, base);
	s[y] = '\0';
	return (s);
}
