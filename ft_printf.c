/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:31:12 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/20 15:34:32 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_utils		*utils;

	va_start(ap, str);
	if (!(utils = malloc(sizeof(t_utils))))
		return (-1);
	utils->i = 0;
	utils->cpt = 0;
	utils->str = (char *)str;
	while (utils->str[utils->i])
	{
		utils->index_annexe = 0;
		if (!(utils = ft_printf_annexe(ap, utils)))
			return (-1);
		if (utils->i == -1)
			return (-1);
		utils->i++;
	}
	va_end(ap);
	return (ft_fin(utils));
}

t_utils	*ft_printf_annexe(va_list ap, t_utils *utils)
{
	if (cpt_index(utils) > 0)
	{
		if (!(utils = ft_printf_annexe_2(ap, utils)))
			return (NULL);
		free(utils->index);
		free(utils->result);
	}
	else
	{
		ft_putchar_aff(utils->str[utils->i]);
		utils->cpt++;
	}
	return (utils);
}

t_utils	*ft_printf_annexe_2(va_list ap, t_utils *utils)
{
	if (!(utils = ft_index(utils, ap)))
		return (NULL);
	if (!(utils = ft_printf_2(ap, utils)))
		return (NULL);
	if (!(utils = ft_putstr_aff(utils)))
		return (NULL);
	return (utils);
}

t_utils	*ft_printf_2(va_list ap, t_utils *utils)
{
	utils->c = utils->index[(ft_strlen(utils->index) - 1)];
	if (!(utils = ft_arg(ap, utils)))
		return (NULL);
	if (!(utils = ft_cas_spe_index(utils)))
		return (NULL);
	if (!(utils = ft_cas_spe_point(utils)))
		return (NULL);
	if (!(utils = ft_printf_3(utils)))
		return (NULL);
	return (utils);
}

t_utils	*ft_printf_3(t_utils *utils)
{
	if (utils->c == 'c' && utils->result[0] == 0)
		return (utils);
	if (ft_search(utils->index, '.') >= 0)
	{
		if (utils->c == 'd' || utils->c == 'i' ||
				utils->c == 'x' || utils->c == 'X' || utils->c == 'u')
			if (!(utils = ft_point_int(utils)))
				return (NULL);
		if (utils->c == 's')
			if (!(utils = ft_point_string(utils)))
				return (NULL);
	}
	if (ft_search(utils->index, '-') != -1)
		if (!(utils = ft_moins(utils)))
			return (NULL);
	if (utils->index[0] == '0')
		if (!(utils = ft_zero(utils)))
			return (NULL);
	if (utils->index[0] >= 49 && utils->index[0] <= 57)
		if (!(utils = ft_nbr(utils)))
			return (NULL);
	return (utils);
}
