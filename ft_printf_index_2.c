/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_index_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:40:03 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/20 11:37:59 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utils	*ft_zero(t_utils *utils)
{
	int		i;
	int		n;
	char	*zero;
	char	*retour;

	if (ft_search(utils->index, '.') != -1)
		return (ft_zero_2(utils));
	if ((n = ft_nbr_after_index(utils, '0')) < 0)
		return (NULL);
	i = n - ft_strlen(utils->result);
	if (i > 0)
	{
		if (!(zero = ft_string_filled('0', i)))
			return (NULL);
		if (!(retour = ft_strjoin(zero, utils->result)))
			return (NULL);
		free(utils->result);
		utils->result = retour;
	}
	if (!(utils = ft_zero_3(utils)))
		return (NULL);
	return (utils);
}

t_utils	*ft_zero_2(t_utils *utils)
{
	int		n;
	int		i;
	char	*retour;
	char	*zero;

	if ((n = ft_nbr_after_index(utils, '0')) < 0)
		return (NULL);
	i = n - ft_strlen(utils->result);
	if (i > 0)
	{
		if (!(zero = ft_string_filled(' ', i)))
			return (NULL);
		if (!(retour = ft_strjoin(zero, utils->result)))
			return (NULL);
		free(utils->result);
		utils->result = retour;
	}
	return (utils);
}

t_utils	*ft_zero_3(t_utils *utils)
{
	if (ft_search(utils->result, '-') > 0)
	{
		if (!(utils->result = ft_suppr_char(utils->result,
						ft_search(utils->result, '-'))))
			return (NULL);
		if (!(utils->result = ft_add_char(utils->result, 0, '-')))
			return (NULL);
	}
	return (utils);
}

t_utils	*ft_nbr(t_utils *utils)
{
	int		n;
	int		i;
	char	*retour;
	char	*space;

	if ((n = ft_nbr_index(utils->index)) < 0)
		return (NULL);
	i = n - ft_strlen(utils->result);
	if (i > 0)
	{
		if (!(space = ft_string_filled(' ', i)))
			return (NULL);
		if (!(retour = ft_strjoin(space, utils->result)))
			return (NULL);
		free(utils->result);
		utils->result = retour;
	}
	return (utils);
}

t_utils	*ft_p(t_utils *utils)
{
	if (utils->c == 'p')
	{
		if (!(utils->result = ft_add_char(utils->result, 0, 'x')))
			return (NULL);
		if (!(utils->result = ft_add_char(utils->result, 0, '0')))
			return (NULL);
	}
	return (utils);
}
