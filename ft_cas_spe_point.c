/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cas_spe_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:13:14 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/19 15:39:12 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utils	*ft_cas_spe_point(t_utils *utils)
{
	if (utils->index[ft_search(utils->index, '.') + 1] == '-'
			&& ft_search(utils->index, '.') >= 0)
	{
		if (utils->index[0] == '0')
		{
			while (utils->index[ft_search(utils->index, '.') + 1] != utils->c)
				if (!(utils->index = ft_suppr_char(utils->index,
								ft_search(utils->index, '.') + 1)))
					return (NULL);
			if (!(utils->index = ft_suppr_char(utils->index,
							ft_search(utils->index, '.'))))
				return (NULL);
			return (utils);
		}
		if (!(utils->index = ft_suppr_char(utils->index,
						ft_search(utils->index, '.') + 1)))
			return (NULL);
		if (!(utils = ft_cas_spe_point_2(utils)))
			return (NULL);
	}
	if (!(utils = ft_cas_spe_point_x(utils)))
		return (NULL);
	return (utils);
}

t_utils	*ft_cas_spe_point_2(t_utils *utils)
{
	while (utils->index[ft_search(utils->index, '.') + 1] >= 48
			&& utils->index[ft_search(utils->index, '.') + 1] <= 57)
	{
		if (!(utils->index = ft_suppr_char(utils->index,
						ft_search(utils->index, '.') + 1)))
			return (NULL);
	}
	if (utils->c == 's')
		if (!(utils->index = ft_suppr_char(utils->index,
						ft_search(utils->index, '.'))))
			return (NULL);
	if (utils->c == 'x' || utils->c == 'X')
		if (!(utils->index = ft_add_char(utils->index,
						ft_search(utils->index, '.') + 1, '1')))
			return (NULL);
	if (ft_atoi(utils->result) == 0 &&
			(utils->c == 'd' || utils->c == 'u' || utils->c == 'i'))
	{
		if (!(utils->index = ft_add_char(utils->index,
						ft_search(utils->index, '.') + 1, '1')))
			return (NULL);
	}
	return (ft_cas_spe_point_3(utils));
}

t_utils	*ft_cas_spe_point_3(t_utils *utils)
{
	if (ft_search(utils->index, '.') > 0 && ft_search(utils->index, '-')
			< ft_search(utils->index, '.'))
	{
		if (ft_nbr_after_index(utils, '.') >= ft_nbr_after_index(utils, '-'))
		{
			while (ft_search(utils->index, '.') > 0)
				if (!(utils->index = ft_suppr_char(utils->index, 0)))
					return (NULL);
		}
	}
	return (utils);
}

t_utils	*ft_cas_spe_point_x(t_utils *utils)
{
	if (ft_search(utils->index, '.') >= 0)
	{
		if ((utils->c == 'x' || utils->c == 'X')
				&& utils->index[ft_search(utils->index, '.') + 1] == '0')
		{
			if (!(utils->index = ft_suppr_char(utils->index,
							ft_search(utils->index, '.') + 1)))
				return (NULL);
			if (!(utils->index = ft_add_char(utils->index,
							ft_search(utils->index, '.') + 1, '1')))
				return (NULL);
			if (ft_strlen(utils->result) == 1 && utils->result[0] == '0')
				if (!(utils->index = ft_suppr_char(utils->index,
								ft_search(utils->index, '.') + 1)))
					return (NULL);
		}
	}
	return (utils);
}
