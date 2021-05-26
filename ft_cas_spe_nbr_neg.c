/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cas_spe_nbr_neg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:34:29 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/19 15:41:50 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utils	*ft_cas_spe_point_nbr_neg(t_utils *utils, int nb_zero)
{
	int		i;

	i = 0;
	if (!(i <= (nb_zero + 1)))
		return (utils);
	if (ft_atoi(utils->result) < 0)
	{
		while (i < (nb_zero + 1))
		{
			if (!(utils->result = ft_add_char(utils->result, 1, '0')))
				return (NULL);
			i++;
		}
	}
	else
	{
		if (!(utils = ft_cas_spe_point_nbr_neg_2(utils, nb_zero)))
			return (NULL);
	}
	return (utils);
}

t_utils	*ft_cas_spe_point_nbr_neg_2(t_utils *utils, int nb_zero)
{
	char *zero;
	char *retour;

	if (!(zero = ft_string_filled('0', nb_zero)))
		return (NULL);
	if (!(retour = ft_strjoin(zero, utils->result)))
		return (NULL);
	free(utils->result);
	utils->result = retour;
	return (utils);
}

int		ft_nbr_or_not(char *str, int x)
{
	int i;

	i = x;
	if (str[i] == 48)
	{
		while (str[i] >= 48 && str[i] <= 57)
		{
			if (str[i] != 48)
				return (-1);
			i--;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			if (str[i] != 48)
				return (-1);
			i++;
		}
		return (1);
	}
	else
		return (-1);
}

int		ft_cpt_char(char *str, char c, int max)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (str[i] && i < max)
	{
		if (str[i] == c)
			cpt++;
		i++;
	}
	return (cpt);
}

char	*ft_putstr_null(void)
{
	char *s;

	if (!(s = malloc(sizeof(char) * 5)))
		return (NULL);
	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	s[6] = '\0';
	return (s);
}
