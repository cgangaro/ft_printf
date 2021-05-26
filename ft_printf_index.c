/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:40:28 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/20 12:30:41 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utils	*ft_point_int(t_utils *utils)
{
	int		i;
	int		n;
	char	*retour;

	if ((n = ft_nbr_after_index(utils, '.')) < 0)
		return (NULL);
	i = n - ft_strlen(utils->result);
	if (ft_atoi(utils->result) == 0 && n == 0 &&
	(utils->c == 'd' || utils->c == 'i' || utils->c == 'u' || utils->c == 'x'
	|| utils->c == 'X'))
	{
		if (!(retour = ft_substr(utils->result, 0, 1)))
			return (NULL);
		free(utils->result);
		utils->result = retour;
		utils->result[0] = '\0';
		return (utils);
	}
	if (!(utils = ft_cas_spe_point_nbr_neg(utils, i)))
		return (NULL);
	return (utils);
}

t_utils	*ft_point_string(t_utils *utils)
{
	int		i;
	char	*retour;
	int		n;

	if ((n = ft_nbr_after_index(utils, '.')) < 0)
		return (NULL);
	i = n - ft_strlen(utils->result);
	if (i < 0)
	{
		if (!(retour = ft_substr(utils->result, 0, n)))
			return (NULL);
		free(utils->result);
		utils->result = retour;
	}
	return (utils);
}

t_utils	*ft_moins(t_utils *utils)
{
	int		i;
	int		n;
	char	*space;

	if (utils->result[0] == 0 && utils->c == 'c')
		return (utils);
	if ((n = ft_nbr_after_index(utils, '-')) < 0)
		return (NULL);
	i = n - ft_strlen(utils->result);
	if (i > 0)
	{
		if (!(space = ft_string_filled(' ', i)))
			return (NULL);
		if (!(utils->result = ft_strjoin(utils->result, space)))
			return (NULL);
		free(space);
	}
	return (utils);
}

int		ft_nbr_after_index(t_utils *utils, char c)
{
	int		i;
	char	*nbr;
	int		n;
	int		spe;

	spe = 1;
	if (c >= 49 && c <= 57)
		spe = 0;
	if (!(nbr = ft_calloc(sizeof(char), 1)))
		return (-1);
	i = ft_search(utils->index, c) + spe;
	while (utils->index[i] >= 48 && utils->index[i] <= 57)
	{
		if (!(nbr = ft_strjoin_one(nbr, utils->index[i])))
			return (-1);
		i++;
	}
	n = ft_atoi(nbr);
	free(nbr);
	return (n);
}

int		ft_nbr_index(char *index)
{
	int		i;
	char	*nbr;
	int		n;

	if (!(nbr = ft_calloc(sizeof(char), 1)))
		return (-1);
	i = 0;
	while (index[i] >= 48 && index[i] <= 57)
	{
		if (!(nbr = ft_strjoin_one(nbr, index[i])))
			return (-1);
		i++;
	}
	n = ft_atoi(nbr);
	free(nbr);
	return (n);
}
