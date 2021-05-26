/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cas_spe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:12:12 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/19 14:30:54 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utils	*ft_cas_spe_index(t_utils *utils)
{
	int		i;

	i = 0;
	if (utils->index[0] == '0' && utils->index[1] == '-')
		if (!(utils->index = ft_suppr_char(utils->index, 0)))
			return (NULL);
	while (utils->index[0] == '0' && utils->index[1] == '0')
		if (!(utils->index = ft_suppr_char(utils->index, 0)))
			return (NULL);
	if (utils->index[0] == '0' && (utils->index[1] < 48 ||
				utils->index[1] > 57) && utils->index[1] != '-')
		if (!(utils->index = ft_suppr_char(utils->index, 0)))
			return (NULL);
	return (utils);
}

t_utils	*ft_cas_spe_index_etoile(t_utils *utils)
{
	while (utils->index[0] == '-' && utils->index[1] == '-')
		if (!(utils->index = ft_suppr_char(utils->index, 0)))
			return (NULL);
	return (utils);
}
