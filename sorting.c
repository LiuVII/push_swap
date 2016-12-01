/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:41:46 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/30 20:41:47 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#define MALLOC_G(x, y) ((!x) ? {return (y);} : 0)

/*
**bubble two way sorting with checking
*/
void	ft_print_arr(int *a, int n)
{
	int	k;

	k = -1;
	// printf("j: %d |", j);
	while (++k < n)
		printf("%d ", a[k]);
	printf("\n");	
}


int	ft_sort(int *a, int *b, int *r, int n)
{
	int	i;
	int	j;

	int	tmp;
	int	res;

	j = -1;
	if (!b || !r)
		return (0);
	res = 0;
	while (++j < n - 1)
	{
		i = j - 1;
		if (j > 0 && j * 2 < n - 1)
		{
			res++;
			ft_putstr("ra\n");
		}
		while (++i < n - j - 1)
		{
			if (a[i] > a[i + 1])
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				res++;
				ft_putstr("sa\n");
				// ft_print_arr(a, n);
			}
			if (i != n - j - 2)
			{
				res++;
				ft_putstr("ra\n");
			}
			// ft_checksort(a, i);
		}
		while (i-- > j + 1)
		{
			res++;
			ft_putstr("rra\n");
			if (a[i] < a[i - 1])
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				res++;
				ft_putstr("sa\n");
				// ft_print_arr(a, n);
			}
		}
	}
	while (i--)
	{
		res++;
		ft_putstr("rra\n");		
	}
	if (res > 0)
		return (res - 1);
	return (res);
}

/*
**basic bubble two way sorting
*/
int	ft_bb_sort(int *a, int *b, int *r, int n)
{
	int	i;
	int	j;
	int	k;
	int	tmp;
	int	res;

	j = -1;
	if (!b || !r)
		return (0);
	res = 0;
	while (++j < n - 1)
	{
		i = j - 1;
		while (++i < n - j - 1)
		{
			if (a[i] > a[i + 1])
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				res++;
			}
			res++;
		}
		while (i-- > j + 1)
		{
			res++;
			if (a[i] < a[i - 1])
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				res++;
			}
		}
		k = -1;
		printf("j: %d |", j);
		while (++k < n)
			printf("%d ", a[k]);
		printf("\n");
	}
	if (res > 0)
		return (res - 1);
	return (res);
}
