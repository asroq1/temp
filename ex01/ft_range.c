/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 23:43:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/27 10:30:32 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*new_arr;
	int	i;

	if (min >= max)
	{
		return (0);
	}
	i = 0;
	new_arr = malloc(sizeof(int) * (max - min));
	if (new_arr == 0)
	{
		return (0);
	}
	while (max > min)
	{
		new_arr[i] = min;
		min++;
		i++;
	}
	return (new_arr);
}
