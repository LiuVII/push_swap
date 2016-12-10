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

int		main(int argc, char **argv)
{
	int		*a[2];
	int		n[2];
	t_list	*list;

	// if ((i = -1) && argc < 2)
	// 	return (0);
	if (!argc && !argv[0])
		return (0);
	n[0] = 0;
	char *line;
	line = NULL;
	get_next_line(0, &line);
	a[0] = ft_atoi_tab(ft_strsplit(line, ' '), &n[0]);
	// a[0] = ft_atoi_tab(ft_strsplit(argv[1], ' '), &n[0]);
	if (!(a[0] = ft_arr_simpl(a[0], n[0]))
		|| !(a[1] = (int*)malloc(sizeof(int) * n[0])))
	{
		(a[0]) ? free(a[0]) : 0;
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	list = NULL;
	n[1] = 0;
	list = ft_lstnew("", 1);
	printf("Smart sort op num: %d\n",ft_smart_sort(a, n, &list));
	// printf("Smart sort op num: %d\n",ft_smart_sort(a, n, a, &list));
	ft_lstprint(list);
	ft_lstclr(&list);
	free(a[0]);
	free(a[1]);
	return (0);
}
