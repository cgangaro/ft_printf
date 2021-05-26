/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:24:53 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/19 16:03:51 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utils		*ft_index(t_utils *utils, va_list ap)
{
	int		i;
	int		y;
	int		t;

	i = utils->i;
	y = 0;
	t = cpt_index(utils);
	if (!(utils->index = ft_calloc(t + 1, sizeof(char))))
		return (NULL);
	if (utils->str[i] == '%')
	{
		i++;
		while (utils->str[i] && (utils->str[i] == '.' ||
					utils->str[i] == '-' || utils->str[i] == '*'
					|| (utils->str[i] >= 48 && utils->str[i] <= 57)))
		{
			utils->index[y] = utils->str[i];
			i++;
			y++;
		}
	}
	if (!(utils = ft_index_2(utils, i, y, ap)))
		return (NULL);
	return (utils);
}

t_utils		*verif_index_2(t_utils *utils, int i)
{
	while (utils->index[i] && (utils->index[i] == '.'
				|| utils->index[i] == '-' || utils->index[i] == '*'
				|| (utils->index[i] >= 48 && utils->index[i] <= 57)))
	{
		if (i > 0)
			if (utils->index[i] == '*' && (utils->index[i - 1] >= 49
						&& utils->index[i - 1] <= 57))
				return (NULL);
		i++;
	}
	if (utils->index[i] != 'c' && utils->index[i] != 's'
			&& utils->index[i] != 'd' && utils->index[i] != 'i'
			&& utils->index[i] != 'p' && utils->index[i] != 'u'
			&& utils->index[i] != 'x' && utils->index[i] != 'X'
			&& utils->index[i] != '%')
		return (NULL);
	if (utils->index[i + 1] != '\0')
		return (NULL);
	if (ft_search(utils->index, '.') > 0
			&& (utils->index[i] == 'c' || utils->index[i] == 'p'))
		return (NULL);
	return (utils);
}

t_utils		*verif_index(t_utils *utils)
{
	int i;

	i = 0;
	if (utils->index[i] == '-')
	{
		i++;
		while ((utils->index[i] >= 48 && utils->index[i] <= 57) ||
				utils->index[i] == '-')
		{
			if ((utils->index[i - 1] >= 48 && utils->index[i - 1] <= 57)
					&& utils->index[i] == '-')
				return (NULL);
			i++;
		}
	}
	if (!(utils = verif_index_2(utils, i)))
		return (NULL);
	return (utils);
}

t_utils		*index_etoile(va_list ap, t_utils *utils)
{
	int		i;
	char	*s_etoile;
	char	*s_etoile2;

	i = 0;
	while (utils->index[i])
	{
		if (utils->index[i] == '*')
		{
			if (!(s_etoile2 = ft_itoa_base(va_arg(ap, int), "0123456789")))
				return (NULL);
			if (!(s_etoile = ft_substr(s_etoile2, 0, ft_strlen(s_etoile2) + 1)))
				return (NULL);
			free(s_etoile2);
			if (!(utils->index = ft_replace_first('*', s_etoile, utils->index)))
				return (NULL);
		}
		i++;
	}
	if (!(utils = ft_cas_spe_index_etoile(utils)))
		return (NULL);
	return (utils);
}
