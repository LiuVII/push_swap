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

#include "push_swap.h"
#include <math.h>

void	ft_print_arr(int *a, int n)
{
	int	k;

	k = -1;
	// printf("j: %d |", j);
	while (++k < n)
		printf("%d ", a[k]);
	printf("\n");	
}

int ft_maxi(int n)
{
	return ((double)n * sqrt(n));
}

char	*ft_get_instr(int i, int rev)
{
	char	*tmp;

	tmp = NULL;
	(i == 0) ? (tmp = "sa") : 0;
	(i == 1) ? (tmp = "sb") : 0;
	(i == 2) ? (tmp = "ss") : 0;
	if (rev > 0)
	{
		(i == 3) ? (tmp = "ra") : 0;
		(i == 4) ? (tmp = "rb") : 0;
		(i == 5) ? (tmp = "rr") : 0;
		// (i == 6) ? (tmp = "pb") : 0;
		// (i == 7) ? (tmp = "pa") : 0;
		(i == 8) ? (tmp = "rra") : 0;
		(i == 9) ? (tmp = "rrb") : 0;
		(i == 10) ? (tmp = "rrr") : 0;
	}
	else
	{
		(i == 3) ? (tmp = "rra") : 0;
		(i == 4) ? (tmp = "rrb") : 0;
		(i == 5) ? (tmp = "rrr") : 0;
		// (i == 6) ? (tmp = "pa") : 0;
		// (i == 7) ? (tmp = "pb") : 0;
		(i == 8) ? (tmp = "ra") : 0;
		(i == 9) ? (tmp = "rb") : 0;
		(i == 10) ? (tmp = "rr") : 0;		
	}
	return (tmp);
}

int	ft_brute_sort(int *a[2], int n[2], int iter, int imax, t_list **list)
{
	int	i;
	int	j;
	int	tmp;
	t_list	*new;

	if (imax < 0)
		imax = ft_maxi(n[0] + n[1]); 
	if (!ft_issorted(a[0], n[0], 1) || n[1])
	{
		if (iter + 1 < imax)
		{
			i = -1;
			j = -1;
			tmp = 0;
			new = NULL;
			while (++i < 11)
			{
				printf("it: %d i: %d j: %d, tmp %d, imax %d |", iter, i, j, tmp, imax);
				ft_apply_isnstr(a, ft_get_instr(i, 1), n, 1);
				if ((tmp = ft_brute_sort(a, n, iter + 1, imax, list)) && iter + tmp < imax)
				{
					if (j < 0)
					{
						new = ft_lstnew(ft_get_instr(i, 1), ft_strlen(ft_get_instr(i, 1)));
						new->next = *list;
						*list = new;
					}
					else
					{
//						you're deliting a list even if it's a solution you want
						new = (*list)->next;
						(new) ? ft_lstclr(&new) : 0;
						(*list)->next = NULL;
						free((*list)->content);
						(*list)->content = strdup(ft_get_instr(i, 1));
					}
					j = i;
					imax = iter + tmp;
				}
				ft_apply_isnstr(a, ft_get_instr(i, -1), n, 0);
			}
			if (j < 0)
			{
				
				return (0);
			}
			return (1 + imax - iter);
		}
		return (0);
	}
	return (1);
}

// int	ft_sort(int *a, int *b, int *r, int n)
// {
// 	int	i;
// 	int	j;
// 	int	tmp;
// 	int	res;

// 	j = -1;
// 	if (!b || !r)
// 		return (0);
// 	if (res > 0)
// 		return (res - 1);
// 	return (res);
// }

/*
**basic bubble two way sorting
*/

int	ft_bb_sort(int *a, int *b, int *r, int n)
{
	int	i;
	int	j;
	int	tmp;
	int	res;

	j = -1;
	if (!b || !r)
		return (0);
	res = 0;
	while (++j < n / 2)
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
	while (--j)
	{
		res++;
		ft_putstr("rra\n");		
	}
	if (res > 0)
		return (res - 1);
	return (res);
}
