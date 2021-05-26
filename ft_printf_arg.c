/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:24:59 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/21 14:52:48 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utils	*ft_arg(va_list ap, t_utils *utils)
{
	if (utils->c == 'c')
		if (!(utils->result = ft_putchar(va_arg(ap, int))))
			return (NULL);
	if (utils->c == 's')
		if (!(utils->result = ft_putstr(va_arg(ap, char *))))
			return (NULL);
	if (utils->c == 'd')
		if (!(utils->result = ft_itoa_base(va_arg(ap, int), "0123456789")))
			return (NULL);
	if (utils->c == 'i')
		if (!(utils->result = ft_itoa_base(va_arg(ap, int), "0123456789")))
			return (NULL);
	if (utils->c == 'u')
		if (!(utils->result = ft_itoa_base(va_arg(ap, unsigned int),
							"0123456789")))
			return (NULL);
	if (utils->c == 'x' || utils->c == 'X' ||
			utils->c == '%' || utils->c == 'p')
		if (!(utils = ft_arg_annexe(ap, utils)))
			return (NULL);
	return (utils);
}

t_utils	*ft_arg_annexe(va_list ap, t_utils *utils)
{
	if (utils->c == 'p')
	{
		if (!(utils->result = ft_itoa_base_p(va_arg(ap, unsigned long),
						"0123456789abcdef")))
			return (NULL);
		if (!(utils = ft_arg_annexe_p(utils)))
			return (NULL);
	}
	if (utils->c == 'x')
		if (!(utils->result = ft_itoa_base(va_arg(ap, unsigned int),
					"0123456789abcdef")))
			return (NULL);
	if (utils->c == 'X')
		if (!(utils->result = ft_itoa_base(va_arg(ap, unsigned int),
					"0123456789ABCDEF")))
			return (NULL);
	if (utils->c == '%')
		if (!(utils->result = ft_putchar('%')))
			return (NULL);
	return (utils);
}

t_utils	*ft_arg_annexe_p(t_utils *utils)
{
	if (ft_atoi(utils->result) == 0 && ft_search(utils->index, '.') != -1)
	{
		if (utils->index[ft_search(utils->index, '.') + 1] == utils->c ||
		utils->index[ft_search(utils->index, '.') + 1] == '0')
		{
			if (!(utils->result = ft_suppr_char(utils->result, 0)))
				return (NULL);
		}
	}
	if (!(utils->result = ft_add_char(utils->result, 0, 'x')))
		return (NULL);
	if (!(utils->result = ft_add_char(utils->result, 0, '0')))
		return (NULL);
	return (utils);
}

char	*ft_putstr(char *str)
{
	int		i;
	int		taille;
	char	*s;

	if (!str)
		return (ft_putstr_null());
	taille = ft_strlen(str);
	if (!(s = malloc(sizeof(char) * (taille + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
