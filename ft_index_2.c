/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:20:14 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/19 16:10:39 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utils	*ft_index_2(t_utils *utils, int i, int y, va_list ap)
{
	if (utils->str[i] == 'c' || utils->str[i] == 's' || utils->str[i] == 'd'
			|| utils->str[i] == 'i' || utils->str[i] == 'p'
			|| utils->str[i] == 'u' || utils->str[i] == 'x'
			|| utils->str[i] == 'X' || utils->str[i] == '%')
	{
		utils->index[y] = utils->str[i];
	}
	utils->i = utils->i + ft_strlen(utils->index);
	if (!(utils = index_etoile(ap, utils)))
		return (NULL);
	if (!(utils = ft_index_2_annexe(utils)))
		return (NULL);
	if (!(utils = ft_index_2_annexe_2(utils)))
		return (NULL);
	return (utils);
}

t_utils	*ft_index_2_annexe(t_utils *utils)
{
	if (ft_search(utils->index, '.') >= 0)
	{
		utils->index_annexe = 1;
		if (ft_cpt_char(utils->index, '-', ft_search(utils->index, '.')) > 1)
		{
			while (ft_cpt_char(utils->index, '-',
						ft_search(utils->index, '.')) > 1)
				if (!(utils->index = ft_suppr_char(utils->index, 0)))
					return (NULL);
		}
		else if (ft_cpt_char(utils->index, '0',
					ft_search(utils->index, '.')) > 1)
			if (!(utils = ft_index_2_annexe_3(utils)))
				return (NULL);
	}
	return (utils);
}

t_utils	*ft_index_2_annexe_2(t_utils *utils)
{
	if (ft_cpt_char(utils->index, '-', ft_strlen(utils->index)) > 1
			&& utils->index_annexe == 0)
	{
		while (ft_cpt_char(utils->index, '-', ft_strlen(utils->index) - 1) > 1)
			if (!(utils->index = ft_suppr_char(utils->index, 0)))
				return (NULL);
	}
	else if (ft_cpt_char(utils->index, '0', ft_strlen(utils->index) - 1) > 1
			&& utils->index_annexe == 0)
	{
		if (!(utils = ft_index_2_annexe_3(utils)))
			return (NULL);
	}
	return (utils);
}

t_utils	*ft_index_2_annexe_3(t_utils *utils)
{
	int i;

	i = ft_first_char(utils->index, '0', 0);
	while (ft_nbr_or_not(utils->index, i) == -1 && i > 0)
		i = ft_first_char(utils->index, '0', i + 1);
	if (ft_nbr_or_not(utils->index, i) > 0)
	{
		while (i > 0)
		{
			if (!(utils->index = ft_suppr_char(utils->index, 0)))
				return (NULL);
			i--;
		}
	}
	return (utils);
}

int		ft_first_char(char *str, char c, int start)
{
	int i;

	i = start;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}
