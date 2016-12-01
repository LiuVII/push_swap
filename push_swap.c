/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:21:41 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/30 22:21:42 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#define MALLOC_G(x, y) ((!x) ? {return (y);} : 0)

int		ft_sort(int *a, int *b, int *r, int n);
int		*ft_atoi_tab(char **tab, int *len);

/*
**convert array to natural numbers permutations
**Also check for duplicates here
*/

int		*ft_arr_simpl(int *arr, int n)
{
	if (n > 0)
		return (arr);
	return (0);
}

/*
**determintes shift of each element from sorted position
**Also check for duplicates here ("sum" must be == 0)
*/

int		*ft_fillrank(int *arr, int n)
{
	int *rtab;
	int	i;
	int	sum;

	if (!(rtab = (int*)malloc(sizeof(int) * n)))
		return (0);
	i = -1;
	sum = 0;
	while (++i < n)
	{
		rtab[i] = i + 1 - arr[i];
		sum += rtab[i];
	}
	if (!sum)
		return (rtab);
	free(rtab);
	printf("Sum %d\n", sum);
	return (0);
}

int		main(int argc, char **argv)
{
	int		*arr;
	int		*brr;
	int		*rtab;
	int		n;
	int		i;

	if ((i = -1) && argc < 2)
		return (0);
	n = 0;
	rtab = NULL;
	arr = ft_atoi_tab(ft_strsplit(argv[1], ' '), &n);
	// printf("%d\n", n);
	if (!(arr = ft_arr_simpl(arr, n))
		|| !(rtab = ft_fillrank(arr, n))
		|| !(brr = (int*)malloc(sizeof(int) * n)))
	{
		(arr) ? free(arr) : 0;
		(rtab) ? free(rtab) : 0;
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}		
	printf("Op num: %d\n",ft_sort(arr, brr, rtab, n));
	while (++i < n)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
	free(rtab);
	free(brr);
	return (0);
}
