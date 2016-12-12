/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 02:09:50 by mfilipch          #+#    #+#             */
/*   Updated: 2016/12/01 02:09:52 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_apply_isnstr(int *a[2], char *s, int n[2], int debug)
{
	if (!ft_strcmp(s, "ss") || !ft_strcmp(s, "sa") || !ft_strcmp(s, "sb"))
	{
		(n[0] > 1 && ft_strcmp(s, "sb")) ? ft_swap(&a[0][0], &a[0][1]) : 0;
		(n[1] > 1 && ft_strcmp(s, "sa")) ? ft_swap(&a[1][0], &a[1][1]) : 0;
	}
	if (!ft_strcmp(s, "rr") || !ft_strcmp(s, "ra") || !ft_strcmp(s, "rb"))
	{
		(ft_strcmp(s, "rb")) ? ft_rot(a[0], n[0], 1) : 0;
		(ft_strcmp(s, "ra")) ? ft_rot(a[1], n[1], 1) : 0;
	}
	(!ft_strcmp(s, "pb")) ? ft_push(a[0], a[1], &n[0], &n[1]) : 0;
	(!ft_strcmp(s, "pa")) ? ft_push(a[1], a[0], &n[1], &n[0]) : 0;
	if (!ft_strcmp(s, "rrr") || !ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb"))
	{
		(ft_strcmp(s, "rrb")) ? ft_rot(a[0], n[0], -1) : 0;
		(ft_strcmp(s, "rra")) ? ft_rot(a[1], n[1], -1) : 0;
	}
	if (debug)
	{
		ft_putstr(s);
		ft_putstr(":\nStack A: ");
		ft_print_arr(a[0], n[0]);
		ft_putstr("Stack B: ");
		ft_print_arr(a[1], n[1]);
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rot(int *a, int n, int shift)
{
	int	i;
	int	tmp;

	if (shift == 0 || n < 2)
		return ;
	if (shift == 1)
	{
		tmp = a[(shift - 1) % n];
		i = -1;
		while (++i < n - 1)
		{
			a[i] = a[(i + shift) % n];
		}
		a[n - 1] = tmp;
	}
	else if (shift == -1)
	{
		tmp = a[n - 1];
		i = n;
		while (i-- > 1)
		{
			a[i] = a[i - 1];
		}
		a[0] = tmp;
	}
}

void	ft_push(int *a, int *b, int *n, int *m)
{
	if (*n > 0)
	{
		ft_rot(b, *m, -1);
		b[*m] = b[0];
		b[0] = a[0];
		(*m)++;
		ft_rot(a, *n, 1);
		(*n)--;
		a[*n] = 0;
	}
}
