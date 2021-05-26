/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:10:34 by cgangaro          #+#    #+#             */
/*   Updated: 2021/01/21 14:52:27 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_utils
{
	char	*str;
	char	*index;
	char	*result;
	int		i;
	int		cpt;
	char	c;
	int		index_annexe;
}				t_utils;

int				ft_printf(const char *str, ...);
t_utils			*ft_printf_annexe(va_list ap, t_utils *utils);
t_utils			*ft_printf_annexe_2(va_list ap, t_utils *utils);
t_utils			*ft_index(t_utils *utils, va_list ap);
t_utils			*ft_index_2(t_utils *utils, int i, int y, va_list ap);
t_utils			*ft_index_2_annexe(t_utils *utils);
t_utils			*ft_index_2_annexe_2(t_utils *utils);
t_utils			*ft_index_2_annexe_3(t_utils *utils);
t_utils			*ft_cas_spe_index(t_utils *utils);
t_utils			*verif_index(t_utils *utils);
t_utils			*ft_cas_spe_index_etoile(t_utils *utils);
t_utils			*index_etoile(va_list ap, t_utils *utils);
t_utils			*ft_arg(va_list ap, t_utils *utils);
t_utils			*ft_arg_annexe(va_list ap, t_utils *utils);
t_utils			*ft_arg_annexe(va_list ap, t_utils *utils);
t_utils			*ft_arg_annexe_p(t_utils *utils);
t_utils			*ft_cas_spe_point(t_utils *utils);
t_utils			*ft_cas_spe_point_2(t_utils *utils);
t_utils			*ft_cas_spe_point_3(t_utils *utils);
t_utils			*ft_cas_spe_point_x(t_utils *utils);
t_utils			*ft_printf_2(va_list ap, t_utils *utils);
t_utils			*ft_printf_3(t_utils *utils);
t_utils			*ft_point_int(t_utils *utils);
t_utils			*ft_cas_spe_point_nbr_neg(t_utils *utils, int nb_zero);
t_utils			*ft_cas_spe_point_nbr_neg_2(t_utils *utils, int nb_zero);
t_utils			*ft_point_string(t_utils *utils);
t_utils			*ft_moins(t_utils *utils);
t_utils			*ft_zero(t_utils *utils);
t_utils			*ft_zero_2(t_utils *utils);
t_utils			*ft_zero_3(t_utils *utils);
t_utils			*ft_nbr(t_utils *utils);
t_utils			*ft_p(t_utils *utils);
int				ft_fin(t_utils *utils);
int				ft_cpt_char(char *str, char c, int max);
int				ft_first_char(char *str, char c, int start);
int				ft_nbr_or_not(char *str, int x);
t_utils			*ft_putstr_aff(t_utils *utils);
t_utils			*ft_putstr_aff_c_moins(t_utils *utils);
t_utils			*ft_putstr_aff_c_zero(t_utils *utils);
int				ft_nbr_after_index(t_utils *utils, char c);
int				ft_strlen(char *s);
char			*ft_putstr(char *str);
char			*ft_putstr_null();
char			*ft_putchar(char c);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(char *s, size_t n);
char			*ft_itoa_base(long long n, char *base);
char			*ft_itoa_base_p(unsigned long n, char *base);
char			*ft_substr(char const *s, int start, size_t len);
char			*ft_replace_first(char a, char *b, char *str);
char			*ft_strjoin(char *s1, char *s2);
int				cpt_index(t_utils *utils);
int				cpt_index_2(t_utils *utils, int i, int cpt);
char			*ft_string_filled(char c, int size);
int				ft_search(char *str, char c);
long long int	ft_atoi(const char *str);
char			*ft_strjoin_one(char *s1, char c);
void			ft_putchar_aff(char c);
int				ft_nbr_index(char *index);
char			*ft_suppr_char(char *str, int x);
char			*ft_add_char(char *str, int x, char c);

#endif
