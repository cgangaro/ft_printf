/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:42:21 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/14 14:46:48 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_cpt_p(int n)
{
	unsigned int	nb;
	int				i;

	i = 0;
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_recursive_p(char *s, unsigned long int nb, int y, char *base)
{
	int	i;

	i = ft_strlen(base);
	if (nb >= (unsigned long)i)
	{
		s = ft_recursive_p(s, ((nb - (nb % i)) / i), y - 1, base);
		if (nb >= (unsigned long)i)
			nb = nb % i;
	}
	s[y] = base[nb];
	return (s);
}

int		ft_nb_caract_p(unsigned long n, int i)
{
	int					nb_caract;
	unsigned long int	nb;
	unsigned long int	nb2;

	nb = n;
	nb2 = nb;
	nb_caract = 1;
	while ((nb = (nb / i)) >= (unsigned long)i)
		nb_caract++;
	if (nb < (unsigned long)i && nb2 >= (unsigned long)i && nb2 != 0)
		nb_caract++;
	return (nb_caract);
}

char	*ft_itoa_base_p(unsigned long n, char *base)
{
	char			*s;
	unsigned long	nb;
	int				i;
	int				y;

	i = ft_strlen(base);
	y = ft_nb_caract_p(n, i);
	if (!(s = ft_calloc(sizeof(char), y + 1)))
		return (0);
	nb = n;
	s = ft_recursive_p(s, nb, y - 1, base);
	s[y] = '\0';
	return (s);
}
