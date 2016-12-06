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

#include "push_swap.h"
#include <math.h>

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
	int		*a[2];
	int		*rtab[2];
	int		n[2];
	int		i;
	t_list	*list;

	if ((i = -1) && argc < 2)
		return (0);
	n[0] = 0;
	rtab[0] = NULL;
	a[0] = ft_atoi_tab(ft_strsplit(argv[1], ' '), &n[0]);
	// printf("%d\n", n);
	if (!(a[0] = ft_arr_simpl(a[0], n[0]))
		|| !(rtab[0] = ft_fillrank(a[0], n[0]))
		|| !(a[1] = (int*)malloc(sizeof(int) * n[0]))
		|| !(rtab[1] = (int*)malloc(sizeof(int) * n[0])))
	{
		(a[0]) ? free(a[0]) : 0;
		(rtab[0]) ? free(rtab[0]) : 0;
		(a[1]) ? free(a[1]) : 0;
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	list = NULL;
	n[1] = 0;
	// list = ft_lstnew("", 1);
	// printf("Op num: %d\n",ft_brute_sort(a, n, /*(double)n[0] * sqrt(n[0])*/ ((n[0] * n[0]) * 0.6 - 1.5 * n[0] + 1), &list, -1));
	printf("Op num: %d\n",ft_smart_sort(a, n, rtab, &list));
	// printf("Op num: %d\n",ft_brute_sort(a, n, 0, &list/*, -1*/));
	ft_lstprint(list);
	ft_lstclr(&list);
	while (++i < n[0])
		printf("%d ", a[0][i]);
	printf("\n");
	free(a[0]);
	free(rtab[0]);
	free(rtab[1]);
	free(a[1]);
	return (0);
}
