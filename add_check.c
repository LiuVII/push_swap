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

int		ft_strcheck(char *str)
{
	if (str)
		return (1);
	return (0);
}

void	ft_lstprint(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		(tmp->content) ? ft_putstr(tmp->content) : 0;
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

int		ft_issorted(int *arr, int n, int order)
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
	while (++i < n - 1)
		if (arr[i] < arr[i + 1])
			return (0);
	return (1);
}

void	ft_apply_isnstr(int *a[2], char *line, int n[2], int debug)
{
	if (!line)
		return ;
	(!ft_strcmp(line, "sa") && n[0] > 1) ? ft_swap(&a[0][0], &a[0][1]) : 0;
	(!ft_strcmp(line, "sb") && n[0] > 1) ? ft_swap(&a[1][0], &a[1][1]) : 0;
	if (!ft_strcmp(line, "ss"))
	{
		(n[0] > 1) ? ft_swap(&a[0][0], &a[0][1]) : 0;
		(n[1] > 1) ? ft_swap(&a[1][0], &a[1][1]) : 0;
	}
	(!ft_strcmp(line, "ra")) ? ft_rot(a[0], n[0], 1) : 0;
	(!ft_strcmp(line, "rb")) ? ft_rot(a[1], n[1], 1) : 0;
	if (!ft_strcmp(line, "rr"))
	{
		ft_rot(a[0], n[0], 1);
		ft_rot(a[1], n[1], 1);
	}	
	(!ft_strcmp(line, "pb")) ? ft_push(a[0], a[1], &n[0], &n[1]) : 0;
	(!ft_strcmp(line, "pa")) ? ft_push(a[0], a[1], &n[1], &n[0]) : 0;
	(!ft_strcmp(line, "rra")) ? ft_rot(a[0], n[0], -1) : 0;
	(!ft_strcmp(line, "rrb")) ? ft_rot(a[1], n[1], -1) : 0;
	if (!ft_strcmp(line, "rrr"))
	{
		ft_rot(a[0], n[0], -1);
		ft_rot(a[1], n[1], -1);
	}
	if (debug)
	{
		printf("%s: ", line);
		ft_print_arr(a[0], n[0]);
	}
}

// void	ft_apply_isnstr_n(int *arr, int *brr, int ins_n, int n[2])
// {
// 	(ins_n == 0) ? ft_swap(&arr[0], &arr[1]) : 0;
// 	(ins_n == 1) ? ft_swap(&brr[0], &brr[1]) : 0;
// 	if (ins_n == 2)
// 	{
// 		ft_swap(&arr[0], &arr[1]);
// 		ft_swap(&brr[0], &brr[1]);
// 	}
// 	(ins_n == 3) ? ft_rot(arr, n[0], 1) : 0;
// 	(ins_n == 4) ? ft_rot(brr, n[1], 1) : 0;
// 	if (ins_n == 5)
// 	{
// 		ft_rot(arr, n[0], 1);
// 		ft_rot(brr, n[1], 1);
// 	}	
// 	(ins_n == 6) ? ft_push(arr, brr, &n[0], &n[1]) : 0;
// 	(ins_n == 7) ? ft_push(brr, arr, &n[1], &n[0]) : 0;
// 	(ins_n == 8) ? ft_rot(arr, n[0], -1) : 0;
// 	(ins_n == 9) ? ft_rot(brr, n[1], -1) : 0;
// 	if (ins_n == 10)
// 	{
// 		ft_rot(arr, n[0], -1);
// 		ft_rot(brr, n[1], -1);
// 	}
// }
