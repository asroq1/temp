/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:40:58 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/26 20:32:01 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*new_arr;
	int	i;

	if (min >= max)
	{
		new_arr = 0;
		return (0);
	}
	new_arr = malloc(sizeof(int) * (max - min));
	if (new_arr == 0)
	{
		return (-1);
	}
	i = 0;
	while (max > min)
	{
		new_arr[i] = min;
		min++;
		i++;
	}
	*range = new_arr;
	return (i);
}
