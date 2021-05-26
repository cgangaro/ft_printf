/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:24:07 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/20 15:34:41 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utils	*ft_putstr_aff(t_utils *utils)
{
	int		i;

	i = 0;
	if (utils->result[0] == 0 && utils->c == 'c')
	{
		if (ft_search(utils->index, '-') >= 0)
			utils = ft_putstr_aff_c_moins(utils);
		else if (utils->index[0] >= 49 && utils->index[0] <= 57)
			utils = ft_putstr_aff_c_zero(utils);
		else
		{
			ft_putchar_aff(0);
			utils->cpt++;
		}
		return (utils);
	}
	while (utils->result[i] != '\0')
	{
		ft_putchar_aff(utils->result[i]);
		i++;
	}
	utils->cpt = utils->cpt + ft_strlen(utils->result);
	return (utils);
}

t_utils	*ft_putstr_aff_c_zero(t_utils *utils)
{
	int	n;

	if ((n = ft_nbr_after_index(utils, utils->index[0])) == -1)
		return (NULL);
	while ((n - 1) > 0)
	{
		ft_putchar_aff(' ');
		n--;
		utils->cpt++;
	}
	ft_putchar_aff(0);
	utils->cpt++;
	return (utils);
}

t_utils	*ft_putstr_aff_c_moins(t_utils *utils)
{
	int	n;

	ft_putchar_aff(0);
	utils->cpt++;
	if ((n = ft_nbr_after_index(utils, '-')) < 0)
		return (NULL);
	while ((n - 1) > 0)
	{
		ft_putchar_aff(' ');
		n--;
		utils->cpt++;
	}
	return (utils);
}

void	ft_putchar_aff(char c)
{
	write(1, &c, 1);
}
