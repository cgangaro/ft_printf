/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:00:54 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/20 11:38:51 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cpt_index(t_utils *utils)
{
	int i;
	int cpt;

	i = utils->i;
	cpt = 0;
	if (utils->str[i] == '%')
	{
		cpt = cpt_index_2(utils, i, cpt);
	}
	return (cpt);
}

int		cpt_index_2(t_utils *utils, int i, int cpt)
{
	i++;
	while (utils->str[i] && (utils->str[i] == '.' || utils->str[i] == '-'
				|| utils->str[i] == '*' ||
				(utils->str[i] >= 48 && utils->str[i] <= 57)))
	{
		i++;
		cpt++;
	}
	if (utils->str[i] == 'c' || utils->str[i] == 's' ||
			utils->str[i] == 'd' || utils->str[i] == 'i' ||
			utils->str[i] == 'p' || utils->str[i] == 'u' ||
			utils->str[i] == 'x' || utils->str[i] == 'X' ||
			utils->str[i] == '%')
	{
		i++;
		cpt++;
	}
	else
		cpt = 0;
	return (cpt);
}
