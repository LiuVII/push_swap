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

void	ft_apply_isnstr(int *a[2], char *line, int n[2], int debug)
{
	if (!ft_strcmp(line, "ss") || !ft_strcmp(line, "sa") || !ft_strcmp(line, "sb"))
	{
		(n[0] > 1 && ft_strcmp(line, "sb")) ? ft_swap(&a[0][0], &a[0][1]) : 0;
		(n[1] > 1 && ft_strcmp(line, "sa")) ? ft_swap(&a[1][0], &a[1][1]) : 0;
	}
	if (!ft_strcmp(line, "rr") || !ft_strcmp(line, "ra") || !ft_strcmp(line, "rb"))
	{
		(ft_strcmp(line, "rb")) ? ft_rot(a[0], n[0], 1) : 0;
		(ft_strcmp(line, "ra")) ? ft_rot(a[1], n[1], 1) : 0;
	}	
	(!ft_strcmp(line, "pb")) ? ft_push(a[0], a[1], &n[0], &n[1]) : 0;
	(!ft_strcmp(line, "pa")) ? ft_push(a[1], a[0], &n[1], &n[0]) : 0;
	if (!ft_strcmp(line, "rrr") || !ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb"))
	{
		(ft_strcmp(line, "rrb")) ? ft_rot(a[0], n[0], -1) : 0;
		(ft_strcmp(line, "rra")) ? ft_rot(a[1], n[1], -1) : 0;
	}
	if (debug)
	{
		ft_putstr(line);
		ft_putstr(":\nStack A: ");
		ft_print_arr(a[0], n[0]);
		ft_putstr("Stack B: ");
		ft_print_arr(a[1], n[1]);
	}
}
