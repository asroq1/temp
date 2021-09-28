/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:51:24 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/26 20:25:40 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_whitespace(char c);
int			is_correct(char *base, int *len);
int			ft_strlen(long long nbr, int base_len);

long long	n_to_b(char *str, char *base, int len)
{
	long long	val;
	int			sign;
	int			i;

	 val = 0;
	sign = 1;
	while (is_whitespace(*str))
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		i = -1;
		while (++i < len)
		{
			if (*str == base[i])
				break ;
		}
		if (i == len)
			break ;
		 val = val * len + (sign * i);
		++str;
	}
	return (val);
}

char	*b_to_b(long long nbr, char *base, int len)
{
	long long		tmp;
	char			*val;
	int				size;

	if (nbr == 0)
	{
		val = (char *)malloc(2);
		val[0] = base[0];
		val[1] = 0;
		return (val);
	}
	tmp = nbr;
	size = ft_strlen(tmp, len);
	val = (char *)malloc(size + 1);
	val[size] = 0;
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		val[--size] = base[tmp % len];
		tmp = tmp / len;
	}
	if (nbr < 0)
		val[0] = '-';
	return (val);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		fr_len;
	int		to_len;

	if (!is_correct(base_from, &fr_len) || !(is_correct(base_to, &to_len)))
		return (0);
	return (b_to_b(n_to_b(nbr, base_from, fr_len), base_to, to_len));
}
