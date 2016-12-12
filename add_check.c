/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:25:58 by mfilipch          #+#    #+#             */
/*   Updated: 2016/12/01 14:25:59 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**Still need error checker for input: numbers, out of integer range
*/

int		ft_strcheck(const char *str)
{
	int			sign;
	long		num;

	sign = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		sign = 44 - *str;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
		if (num + (sign - 1) / 2 > INT_MAX)
			return (0);
	}
	if (*str)
		return (0);
	return (1);
}

int		ft_arrcheck(int *a, int n)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (a[i] == a[j])
				return (0);
	}
	return (1);
}

int		*ft_atoi_tab(char **tab, int *len, int mode)
{
	int		i;
	int		*itab;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	*len = i;
	itab = NULL;
	if (!(itab = (int*)malloc(sizeof(int) * (*len))))
	{
		(mode) ? ft_mapfree(&tab) : 0;
		return (0);
	}
	i = -1;
	while (++i < *len)
	{
		if (!ft_strcheck(tab[i]))
			return (0);
		itab[i] = ft_atoi(tab[i]);
		(mode) ? free(tab[i]) : 0;
	}
	(mode) ? free(tab) : 0;
	return (itab);
}

int		ft_issort(int *arr, int n, int order)
{
	int		i;

	i = -1;
	if (order == 1)
	{
		while (++i < n - 1)
			if (arr[i] > arr[i + 1])
				return (0);
		return (1);
	}
	else if (order == 2)
	{
		order = 0;
		while (++i < n - 1)
			if (arr[i] > arr[i + 1] && ++order && order >= 2)
				return (0);
		if (order == 1 && arr[0] < arr[n - 1])
			return (0);
		return (1);
	}
	while (++i < n - 1)
		if (arr[i] < arr[i + 1])
			return (0);
	return (1);
}
