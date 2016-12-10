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
		(i == 6) ? (tmp = "pb") : 0;
		(i == 7) ? (tmp = "rra") : 0;
		(i == 8) ? (tmp = "rrb") : 0;
		(i == 9) ? (tmp = "rrr") : 0;
		(i == 10) ? (tmp = "pa") : 0;
	}
	else
	{
		(i == 3) ? (tmp = "rra") : 0;
		(i == 4) ? (tmp = "rrb") : 0;
		(i == 5) ? (tmp = "rrr") : 0;
		(i == 6) ? (tmp = "pa") : 0;
		(i == 7) ? (tmp = "ra") : 0;
		(i == 8) ? (tmp = "rb") : 0;
		(i == 9) ? (tmp = "rr") : 0;		
		(i == 10) ? (tmp = "pb") : 0;
	}
	return (tmp);
}

int ft_iscomb(int *a)
{
	if (a[0] == 2 && a[1] == 7 && a[2] == 8 && a[3] == 3 && a[4] == 1 &&
		a[5] == 9 && a[6] == 4 && a[7] == 5 && a[8] == 6)
		return (1);
	return (0);
}

// int merge_sort(int *a[2], int n[2], t_list **list)
// {

// }


// int	ft_brute_sort(int *a[2], int n[2], int iter, t_list **list, int iprev)
// {
// 	int	i;
// 	int	j;
// 	int	tmp;
// 	// char	*instr;
// 	// t_list	*new;

// 	// if (!ft_issorted(a[0], n[0], 1))
// 	if (!ft_iscomb(a[0]))
// 	{
// 		if (iter)
// 		{
// 			i = -1;
// 			j = -1;
// 			// tmp = 0;
// 			(!(*list)) ? *list = ft_lstnew("", 1) : 0;
// 			while (++i < 3)
// 				if ((i == 0 && iprev != 0) || (i == 1 && iprev != 2) || (i == 2 && iprev != 1))
// 				{
// 					// printf("OUT it: %d i: %d j: %d, tmp %d, imax %d |", iter, i, j, tmp, imax);
// 					ft_apply_isnstr(a, ft_get_instr(i, 1), n, 0);
// 					if ((tmp = ft_brute_sort(a, n, iter - 1, &((*list)->next), i)))
// 					{
// 						// printf("BEFORE it: %d j: %d, tmp %d, imax %d |\n", iter, j, tmp, imax);
// 						free((*list)->content);
// 						(*list)->content = strdup(ft_get_instr(i, 1));
// 						j = i;
// 						iter = tmp;
// 						// printf("AFTER j: %d, tmp %d |\n", j, tmp);
// 						// ft_lstprint(*list);
// 					}
// 					ft_apply_isnstr(a, ft_get_instr(i, -1), n, 0);
// 				}
// 			if (j < 0)
// 				return (0);
// 			return (1 + iter);
// 		}
// 		return (0);
// 	}
// 	// printf("clear list tail\n");
// 	((*list)) ? ft_lstclr(&(*list)) : 0;
// 	*list = NULL;
// 	return (1);
// }
int	ft_getmin(int *rtab, int n)
{
	int		sum;
	int		j;
	int		k;
	int		pos;
	int		neg;

	j = -1;
	pos = 0;
	neg = 0;
	sum = 0;
	while (++j < n)
	{
		sum += ABS(rtab[j]);
		if (rtab[j] > 0)
			++pos;
		else if (rtab[j] < 0)
			++neg;
	}
	sum /= 2;
	k = 0;
	while((2 * pos - n) > 0 || (2 * neg - n) > 0)
	{
		j = -1;
		k += (pos > neg) ? 1 : -1; 
		pos = 0;
		neg = 0;
		sum = 0;
		while (++j < n)
		{
			sum += ABS(rtab[j] - k);
			if (rtab[j] - k > 0)
				++pos;
			else if (rtab[j] - k < 0)
				++neg;
		}
		sum = sum / 2 + ABS(k);
	}
	return (sum);
}

void	ft_update_rank(int *rtab[2], int n[2], int i, int sum[2])
{
	int		j;
	int		tmp;

	if (i < 3)
	{
		if ((i == 0 || i == 2) && n[0] > 1)
		{
			tmp = rtab[0][0];
			rtab[0][0] = rtab[0][1] - 1;
			rtab[0][1] = tmp + 1;
		}
		if ((i == 1 || i == 2) && n[1] > 1)
		{
			tmp = rtab[1][0];
			rtab[1][0] = rtab[1][1] - 1;
			rtab[1][1] = tmp + 1;
		}		
	}
//how rotation should affect b and a ranks? 
	else if (i < 6)
	{
		if ((i == 3 || i == 5) && n[0] > 1)
		{
			j = -1;
			tmp = rtab[0][0];
			while (++j < n[0] - 1)
				rtab[0][j] = rtab[0][j + 1] - 1;
			rtab[0][n[0] - 1] = tmp + n[0] - 1;
		}
		if ((i == 4 || i == 5) && n[1] > 1)
		{
			j = -1;
			tmp = rtab[1][0];
			while (++j < n[1] - 1)
				rtab[1][j] = rtab[1][j + 1] - 1;
			rtab[1][n[1] - 1] = tmp + n[1] - 1;			
		}
	}
	else if (i > 6 && i < 10)
	{
		if ((i == 7 || i == 9) && n[0] > 1)
		{
			j = n[0] - 1;
			tmp = rtab[0][n[0] - 1];
			while (j--)
				rtab[0][j + 1] = rtab[0][j] + 1;
			rtab[0][0] = tmp - n[0] + 1;
		}
		if ((i == 8 || i == 9) && n[1] > 1)
		{
			j = n[1] - 1;
			tmp = rtab[1][n[1] - 1];
			while (j--)
				rtab[1][j + 1] = rtab[1][j] + 1;
			rtab[1][0] = tmp - n[1] + 1;
		}
	}
	else
	{
//how rank should change when we push a to b or b to a?
		if (i == 6)
		{
			j = n[1] - 1;
			while (j--)
				rtab[1][j + 1] = rtab[1][j];
			rtab[1][0] = -rtab[0][0];
			j = -1;
			while (++j < n[0])
				rtab[0][j] = rtab[0][j + 1];	
		}
		if (i == 10)
		{
			j = n[0] - 1;
			while (j--)
				rtab[0][j + 1] = rtab[0][j];
			rtab[0][0] = -rtab[1][0];
			j = -1;
			while (++j < n[1])
				rtab[1][j] = rtab[1][j + 1];			
		}
	}
	sum[0] = ft_getmin(rtab[0], n[0]);
	sum[1] = ft_getmin(rtab[1], n[1]);
}

int	ft_rev(int i)
{
	if (i < 3)
		return (i);
	else if (i > 2 && i < 7)
		return (i + 4);
	else
		return (i - 4);
}

// t_list	*ft_move(int *a[2], int n[2], int *rtab[2], int k, t_list **list)
// {
// 	int		i;
// 	int		j;
// 	int		min;
// 	t_list	*new;
// 	char	*str;

// 	j = 1;
// 	// min = a[k][0] + a[k][1];
// 	// while (++j < n)
// 	// 	if (a[k][0] + a[k][j] < min && (i = j))
// 	// 		min = a[k][0] + a[k][j];
// 	// j = a[k][0];
// 	// a[k][0] = a[k][i - 1];
// 	// a[k][i - 1]= a[k][0]; 
// 	min = (k) ? 10 : 6;
// 	new = *t_list;
// 	str = ft_get_instr(min, 1);
// 	ft_apply_isnstr(a, str, n, 0);
// 	ft_update_rank(rtab, n, min, sum);
// 	free(new->next->content);
// 	new->next->content = ft_strdup(str);
// 	new = new->next;
// 	j = -1;
// 	min = (k) ? 4 : 3;
// 	str = ft_get_instr(min, 1);
// 	while (++j < i - 1)
// 	{
// 		ft_apply_isnstr(a, str, n, 0);
// 		ft_update_rank(rtab, n, min, sum);
// 		free(new->next->content);
// 		new->next = ft_lstnew("", 1);

// 	}
// }
int ft_find_shift(int *a, int num, int n, int order)
{
	int		j;
	int		prev;

	j = -1;
	if (n == 0)
		return (0);
	if (order == -1)
		while (++j < n)
		{
			prev = (j - 1 < 0) ? a[n - 1] : a[j - 1];
			if ((num > a[j] && num < prev) || (num > a[j] && a[j] > prev))
				break;
			if ((num < a[j] && a[j] > prev && num < prev))
				break;
		}
	else if (order == 1)
		while (++j < n)
		{
			prev = (j - 1 < 0) ? a[n - 1] : a[j - 1];
			if ((num < a[j] && num > prev) || (num < a[j] && a[j] < prev))
				break;
			if ((num > a[j] && a[j] < prev && num > prev))
				break;
		}
	prev = MIN(j, n - j);
	prev = (prev == j) ? prev : -prev;
	return (prev);
}

void	ft_push_to_pos(int *a[2], int n[2], int shift, int order)
{
	char	*str;	

	if (order == 1)
	{
		str = (shift < 0) ? ft_get_instr(8, 1) : ft_get_instr(4, 1);
		shift = (shift < 0) ? -shift : shift;
		while (shift--)
			ft_apply_isnstr(a, str, n, 0);
		str = ft_get_instr(6, 1);
		ft_apply_isnstr(a, str, n, 0);
	}
	else if (order == -1)
	{
		str = ft_get_instr(10, 1);
		ft_apply_isnstr(a, str, n, 0);
		str = (shift < 0) ? ft_get_instr(4, 1) : ft_get_instr(8, 1);
		shift = (shift < 0) ? -shift : shift;
		while (shift--)
			ft_apply_isnstr(a, str, n, 0);
	}
}

void	ft_rot_to_pos(int *a[2], int n[2], int shift, int order)
{
	char	*str;	

	if (order == 1)
	{
		str = (shift < 0) ? ft_get_instr(7, 1) : ft_get_instr(3, 1);
		shift = (shift < 0) ? -shift : shift;
		while (shift--)
			ft_apply_isnstr(a, str, n, 0);
	}
	else if (order == -1)
	{
		str = (shift < 0) ? ft_get_instr(3, 1) : ft_get_instr(7, 1);
		shift = (shift < 0) ? -shift : shift;
		while (shift--)
			ft_apply_isnstr(a, str, n, 0);
	}
}

int		ft_find_path(int *a[2], int n[2], int depth)
{
	int		i;
	// int		prev;
	int		curr;	
	int		tot;

	i = -1;
	// prev = 0;
	tot = 0;
	if (!ft_issorted(a[0], n[0], 2) && depth)
		while (++i < n[0])
		{
			// s += MIN(i, n[0] - i);
			curr = ft_find_shift(a[1], a[0][i], n[1], -1);
			if ((i <= n[0] - i && curr >=0) || (i > n[0] - i && curr < 0))
				curr = MAX(MIN(i, n[0] - i), ABS(curr));
			else if (i <= n[0] - i || i > n[0] - i)
				curr = MIN(i, n[0] - i) + ABS(curr);
			if (i == 0 || curr < tot)
				tot = curr;
		}
	// if (!ft_issorted(a[0], n[0], 2) && depth)
	// {
	// 	curr = ft_find_shift(a[1], a[0][0], n[1], -1);
	// 	// ft_push_to_pos(a, n, curr, 1);
	// 	tot = ABS(curr)/* + ((depth > 0) ? ft_find_path(a, n, depth - 1) : 0)*/;
	// 	// ft_push_to_pos(a, n, curr, -1);		
	// }
	return (tot + 1);
}

int		ft_find_path_2(int *a[2], int n[2], int depth, int *rota)
{
	int		i;
	int		prev;
	int		tmp;
	int		curr;	
	int		rotb;

	i = -1;
	prev = 0;
	rotb = 0;
	curr = 0;
	if (!ft_issorted(a[0], n[0], 2) && depth)
		while (++i < n[0])
		{
			// s += MIN(i, n[0] - i);
			tmp = ft_find_shift(a[1], a[0][i], n[1], -1);
			if ((i <= n[0] - i && tmp >=0) || (i > n[0] - i && tmp < 0))
				curr = MAX(MIN(i, n[0] - i), ABS(tmp));
			else if (i <= n[0] - i || i > n[0] - i)
				curr = MIN(i, n[0] - i) + ABS(tmp);
			if (i == 0 || curr < prev)
			{
				rotb = tmp;
				*rota = (i < n[0] - i) ? i : i - n[0];
				prev = curr;
			}
		}
	// if (!ft_issorted(a[0], n[0], 2) && depth)
	// {
	// 	curr = ft_find_shift(a[1], a[0][0], n[1], -1);
	// 	// ft_push_to_pos(a, n, curr, 1);
	// 	tot = ABS(curr)/* + ((depth > 0) ? ft_find_path(a, n, depth - 1) : 0)*/;
	// 	// ft_push_to_pos(a, n, curr, -1);		
	// }
	return (rotb);
}
// int	ft_smart_sort(int *a[2], int n[2], int *rtab[2], t_list **list)
// {
// 	int		i;
// 	int		j;
// 	int		sum[2];
// 	int		op;
// 	int		tmp[2];
// 	char	*str;
// 	int		flag;
// 	t_list	*new;

// 	ft_update_rank(rtab, n, -1, sum);
// 	// ft_find_path(a, n, sum);
// 	printf("n[0] %d, a[0] ", n[0]);
// 	ft_print_arr(a[0], n[0]);
// 	printf("rank a[0] ");
// 	ft_print_arr(rtab[0], n[0]);
// 	printf("n[1] %d, a[1] ", n[1]);
// 	ft_print_arr(a[1], n[1]);
// 	printf("rank a[1] ");
// 	ft_print_arr(rtab[1], n[1]);
// 	printf("\n");
// 	op = 0;
// 	flag = 0;
// 	*list = ft_lstnew("", 1);
// 	new = *list;
// 	new->next = NULL;
// 	int steps = 20000;
// 	while (steps-- && (!ft_issorted(a[0], n[0], 1) || n[1]) && ++op)
// 	{
// 		new->next = ft_lstnew("", 1);
// 		i = -1;
// 		j = -1;
// 		tmp[0] = -1;
// 		tmp[1] = -1;
// 		while (++i < 10)
// 			if (i != 6 && i != 1 && i != 2)
// 			{
// 				str = ft_get_instr(i, 1);
// 				ft_apply_isnstr(a, str, n, 0);
// 				ft_update_rank(rtab, n, i, tmp);
// 				// ft_find_path(a, n, tmp);
// 				if (tmp[0] + tmp[1] < sum[0] + sum[1])
// 				{
// 					sum[0] = tmp[0];
// 					// sum[1] = tmp[1];
// 					j = i;
// 					free(new->next->content);
// 					new->next->content = ft_strdup(str);
// 				}
// 				// else
// 				// {
// 				// if (steps == 0)
// 				// {
// 				// 	printf("Sums sum[0]: %d - tmp[0]: %d\n sum[1]: %d - tmp[1] %d\n", sum[0], tmp[0], sum[1], tmp[1]);
// 				// 	printf("i %d\n,n[0] %d, a[0] ", i, n[0]);
// 				// 	ft_print_arr(a[0], n[0]);
// 				// 	printf("rank a[0] ");
// 				// 	ft_print_arr(rtab[0], n[0]);
// 				// 	printf("n[1] %d, a[1] ", n[1]);
// 				// 	ft_print_arr(a[1], n[1]);
// 				// 	printf("rank a[1] ");
// 				// 	ft_print_arr(rtab[1], n[1]);
// 				// 	printf("\n");
// 				// }
// 					ft_apply_isnstr(a, ft_get_instr(ft_rev(i), 1), n, 0);	
// 					ft_update_rank(rtab, n, ft_rev(i), tmp);
// 				// }
// 				// if (steps == 3)
// 				// {


// 				// }
// 			}
// 		if (j >= 0)
// 		{
// 			// printf("applying %s\n", ft_get_instr(j, 1));
// 			str = ft_get_instr(j, 1);
// 			ft_apply_isnstr(a, str, n, 0);
// 			// ft_find_path(a, n, sum);
// 			ft_update_rank(rtab, n, j, sum);
// 		}
// 		if (ft_strcmp(new->next->content, "") == 0)
// 		{
// //DEBUG
// 			// printf("Sums sum[0]: %d - tmp[0]: %d\n sum[1]: %d - tmp[1] %d\n", sum[0], tmp[0], sum[1], tmp[1]);
// 			// printf("i %d\n,n[0] %d, a[0] ", i, n[0]);
// 			// printf("before combo\nn[0] %d, a[0] ", n[0]);
// 			// ft_print_arr(a[0], n[0]);
// 			// printf("rank a[0] ");
// 			// ft_print_arr(rtab[0], n[0]);
// 			// printf("n[1] %d, a[1] ", n[1]);
// 			// ft_print_arr(a[1], n[1]);
// 			// printf("rank a[1] ");
// 			// ft_print_arr(rtab[1], n[1]);
// 			// printf("\n");
// //DEBUG END
// 			if (!ft_issorted(a[0], n[0], 2) && (j = -1))
// 			{
// 				// printf("applying mov_n_push\n");
// 				if (n[1] > 0)
// 				{
// 					j = ft_find_shift(a[1], a[0][0], n[1], -1);
// 					i = (j < 0) ? 8 : 4;
// 					str = ft_get_instr(i, 1);
// 					j = (j < 0) ? -j : j;
// 					while (j--)
// 					{
// 						// printf("a %d, b %d, j %d\n", a[0][0], a[1][j], j);
// 						ft_apply_isnstr(a, str, n, 0);
// 						ft_update_rank(rtab, n, i, sum);
// 						// ft_find_path(a, n, sum);
// 						op++;
// 					}
// 				}
// 				str = ft_get_instr(6, 1);
// 				ft_apply_isnstr(a, str, n, 0);
// 				// ft_find_path(a, n, sum);
// 				ft_update_rank(rtab, n, 6, sum);
// 				free(new->next->content);
// 				new->next->content = ft_strdup("mov_n_push");
// 			}
// 			else
// 			{
// 				// printf("applying merge\n");
// 				// while (n[1])
// 				// {
// 				if (flag == 0)
// 				{
// 					j = ft_find_shift(a[1], n[0] + n[1] + 1, n[1], -1);
// 					// printf("shift on stack B %d\n", j);
// 					i = (j < 0) ? 8 : 4;
// 					str = ft_get_instr(i, 1);
// 					j = (j < 0) ? -j : j;
// 					while (j--)
// 					{
// 						ft_apply_isnstr(a, str, n, 0);
// 						ft_update_rank(rtab, n, i, sum);
// 						op++;
// 					}		
// 					j = ft_find_shift(a[0], 0, n[0], 1);
// 					// printf("shift on stack A %d\n", j);
// 					i = (j < 0) ? 7 : 3;
// 					str = ft_get_instr(i, 1);
// 					str = (j < 0) ? ft_get_instr(7, 1) : ft_get_instr(3, 1);
// 					j = (j < 0) ? -j : j;
// 					while (j--)
// 					{
// 						ft_apply_isnstr(a, str, n, 0);
// 						ft_update_rank(rtab, n, i, sum);
// 						op++;
// 					}						
// 				}
// 				flag = 1;
// 				j = ft_find_shift(a[0], a[1][0], n[0], 1);
// 				// printf("before placing shift on stack A %d\n", j);
// 				i = (j < 0) ? 7 : 3;
// 				str = ft_get_instr(i, 1);
// 				j = (j < 0) ? -j : j;
// 				while (j--)
// 				{
// 					// printf("a %d, b %d, j %d\n", a[0][0], a[1][j], j);
// 					ft_apply_isnstr(a, str, n, 0);
// 					ft_update_rank(rtab, n, i, sum);
// 					// ft_find_path(a, n, sum);
// 					op++;
// 				}
// 				str = ft_get_instr(10, 1);
// 				ft_apply_isnstr(a, str, n, 0);
// 				// ft_find_path(a, n, sum);
// 				ft_update_rank(rtab, n, 10, sum);
// 				// }
// 				free(new->next->content);
// 				new->next->content = ft_strdup("merge");
// 			}						
// 		}
// 		new = new->next;
// 		// if (steps == 1)
// 		// {
// 			// printf("Sums sum[0]: %d - tmp[0]: %d\n sum[1]: %d - tmp[1] %d\n", sum[0], tmp[0], sum[1], tmp[1]);
// 			// printf("i %d\n,n[0] %d, a[0] ", j, n[0]);
// 			// printf("n[0] %d, a[0] ", n[0]);
// 			// ft_print_arr(a[0], n[0]);
// 			// printf("n[1] %d, a[1] ", n[1]);
// 			// ft_print_arr(a[1], n[1]);
// 			// printf("\n");
// 		// }
// 	}
// 	return (op);
// }

int		ft_find_optimum_elem(int *a[2], int n[2], int depth, int elem)
{
	int		i;
	int		j;
	int		prev;
	int		tot;
	int		curr;
	int		tmp;
	char	*str;

	// i = -1;
	prev = 0;
	tmp = 0;
	tot = 0;
	if (!ft_issorted(a[0], n[0], 2) && elem > 0)
	{
		i = -1;
		j = -1;
		curr = ft_find_path_2(a, n, 1, &tmp);
		// curr = ft_find_path(a, n, 1);
		// curr = ABS(ft_find_shift(a[1], a[0][0], n[1], -1)) + 1;
		(elem > 1) ? ft_rot_to_pos(a, n, tmp, 1) : 0;
		(elem > 1) ? ft_push_to_pos(a, n, curr, 1) : 0;
		tot = ((tmp * curr >= 0) ? MAX(ABS(tmp), ABS(curr)) : ABS(tmp - curr)) + 1;
		// if (tot != ft_find_path(a, n, 1))
		// 	printf("DIFF 1 %d | path_2 %d, rota %d, rotb %d\n", tot - ft_find_path(a, n, 1), tot, tmp, curr);
		tot += ((elem > 1) ? ft_find_optimum_elem(a, n, depth, elem - 1) : 0);
		// tot = ABS(curr);
		(elem > 1) ? ft_push_to_pos(a, n, curr, -1) : 0;
		(elem > 1) ? ft_rot_to_pos(a, n, tmp, -1) : 0;
		tmp = 0;
		while (++i < 10)
			if (i != 6 && i != 1 && i != 2)
			{
				str = ft_get_instr(i, 1);
				ft_apply_isnstr(a, str, n, 0);
				if (depth > 0)
					tmp = 1 + ft_find_optimum_elem(a, n, depth - 1, elem);
				else
				{
					curr = ft_find_path_2(a, n, 1, &prev);
					// curr = ft_find_path(a, n, 1);
					// curr = ABS(ft_find_shift(a[1], a[0][0], n[1], -1)) + 1;
					(elem > 1) ? ft_rot_to_pos(a, n, prev, 1) : 0;
					(elem > 1) ? ft_push_to_pos(a, n, curr, 1) : 0;
					tmp = ((prev * curr >= 0) ? MAX(ABS(prev), ABS(curr)) : ABS(prev - curr)) + 1;
					// if (tmp != ft_find_path(a, n, 1))
					// 	printf("DIFF 2 %d | path_2 %d, rota %d, rotb %d\n", tmp - ft_find_path(a, n, 1), tmp, prev, curr);
					tmp += 1 + ((elem > 1) ? ft_find_optimum_elem(a, n, depth, elem - 1) : 0);
					// tmp = 1 + ABS(curr) + ((elem > 1) ? ft_find_optimum_elem(a, n, depth, elem - 1) : 0);
					(elem > 1) ? ft_push_to_pos(a, n, curr, -1) : 0;
					(elem > 1) ? ft_rot_to_pos(a, n, prev, -1) : 0;
				}
				if (tmp <= tot)
				{
					tot = tmp;
					j = i;
				}	
				ft_apply_isnstr(a, ft_get_instr(ft_rev(i), 1), n, 0);
			}		
	}
	if (elem == 1 && depth == 1)
		return (j);
	return (tot);
}


int		ft_find_optimum(int *a[2], int n[2], int depth)
{
	int		i;
	int		j;
	// int		prev;
	int		tot;
	// int		curr;
	int		tmp;
	char	*str;

	// i = -1;
	// prev = 0;
	// prev = 0;
	tot = 0;
	if (!ft_issorted(a[0], n[0], 2) && depth >= 0)
	{
		i = -1;
		j = -1;
		tmp = 0;
		tot = ABS(ft_find_shift(a[1], a[0][0], n[1], -1)) + 1 /*+ ft_find_optimum(a, n, depth - 1, -1)*/;
		// tot = ABS(ft_find_shift(a[1], a[0][0], n[1], -1)) + ABS(ft_find_shift(a[1], a[0][1], n[1], -1)) + 2 /*+ ft_find_optimum(a, n, depth - 1, -1)*/;
		while (++i < 10)
			if (i != 6 && i != 1 && i != 2)
			{
				str = ft_get_instr(i, 1);
				ft_apply_isnstr(a, str, n, 0);
				tmp = 1 + ((depth > 0) ? ft_find_optimum(a, n, depth - 1) : ABS(ft_find_shift(a[1], a[0][0], n[1], -1)) + 1);
				// tmp = 1 + ((depth > 0) ? ft_find_optimum(a, n, depth - 1, i) : ABS(ft_find_shift(a[1], a[0][0], n[1], -1))
					 // + ABS(ft_find_shift(a[1], a[0][1], n[1], -1)) + 2);
				if (tmp <= tot)
				{
					tot = tmp;
					j = i;
				}	
				ft_apply_isnstr(a, ft_get_instr(ft_rev(i), 1), n, 0);
			}		
	}
	if (depth == 2)
		return (j);
	return (tot);
}

int	ft_vsmart_sort(int *a[2], int n[2], t_list **list)
{
	int		i;
	int		j;
	int		op;
	char	*str;
	int		flag;
	t_list	*new;
	int dcount;

	// sum[0] = ft_find_path(a, n, 100);
	printf("n[0] %d, a[0] ", n[0]);
	ft_print_arr(a[0], n[0]);
	printf("n[1] %d, a[1] ", n[1]);
	ft_print_arr(a[1], n[1]);
	printf("\n");
	op = 0;
	flag = 0;
	dcount = 0;
	*list = ft_lstnew("", 1);
	new = *list;
	new->next = NULL;
	int steps = 20000;
	while (steps-- && (!ft_issorted(a[0], n[0], 1) || n[1]) && ++op)
	{
		new->next = ft_lstnew("", 1);
		i = -1;
		// j = ft_find_optimum(a, n, 2);
		j = ft_find_optimum_elem(a, n, 1, 1);
		if (j >= 0)
		{
			// printf("applying %d\n", j);
			str = ft_get_instr(j, 1);
			ft_apply_isnstr(a, str, n, 0);
			free(new->next->content);
			new->next->content = ft_strdup(str);
			if (ft_strcmp(new->content, ft_get_instr(ft_rev(j), 1)) == 0)
				dcount++;
		}
		if (ft_strcmp(new->next->content, "") == 0)
		{
			if (!ft_issorted(a[0], n[0], 2) && (j = -1))
			{
				// printf("applying mov_n_push\n");
				if (n[1] > 0)
				{
					j = ft_find_shift(a[1], a[0][0], n[1], -1);
					str = (j < 0) ? ft_get_instr(8, 1) : ft_get_instr(4, 1);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}
				}
				str = ft_get_instr(6, 1);
				ft_apply_isnstr(a, str, n, 0);
				// ft_find_path(a, n, sum);
				free(new->next->content);
				new->next->content = ft_strdup("mov_n_push");
			}
			else
			{
				// printf("applying merge\n");
				if (flag == 0)
				{
					j = ft_find_shift(a[1], n[0] + n[1] + 1, n[1], -1);
					str = (j < 0) ? ft_get_instr(8, 1) : ft_get_instr(4, 1);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}		
					j = ft_find_shift(a[0], 0, n[0], 1);
					str = (j < 0) ? ft_get_instr(7, 1) : ft_get_instr(3, 1);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}						
				}
				flag = 1;
				j = ft_find_shift(a[0], a[1][0], n[0], 1);
				str = (j < 0) ? ft_get_instr(7, 1) : ft_get_instr(3, 1);
				j = (j < 0) ? -j : j;
				while (j--)
				{
					ft_apply_isnstr(a, str, n, 0);
					op++;
				}
				str = ft_get_instr(10, 1);
				ft_apply_isnstr(a, str, n, 0);
				free(new->next->content);
				new->next->content = ft_strdup("merge");
			}						
			j = -1;
		}
		// printf("i %d\n,n[0] %d, a[0] ", j, n[0]);
		// printf("n[0] %d, a[0] ", n[0]);
		// ft_print_arr(a[0], n[0]);
		// printf("n[1] %d, a[1] ", n[1]);
		// ft_print_arr(a[1], n[1]);
		// printf("\n");
		new = new->next;
	}
	printf("DOUBLES %d\n", dcount);
	return (op);
}

int	ft_smart_sort(int *a[2], int n[2], int *rtab[2], t_list **list)
{
	int		i;
	int		j;
	int		sum[2];
	int		op;
	int		tmp[2];
	char	*str;
	int		flag;
	t_list	*new;

	sum[0] = rtab[0][0];
	// sum[0] = ft_find_path(a, n, 100);
	printf("n[0] %d, a[0] ", n[0]);
	ft_print_arr(a[0], n[0]);
	printf("n[1] %d, a[1] ", n[1]);
	ft_print_arr(a[1], n[1]);
	printf("\n");
	op = 0;
	flag = 0;
	*list = ft_lstnew("", 1);
	new = *list;
	new->next = NULL;
	int steps = 20000;
	while (steps-- && (!ft_issorted(a[0], n[0], 1) || n[1]) && ++op)
	{
		new->next = ft_lstnew("", 1);
		i = -1;
		j = -1;
		tmp[0] = -1;
		// tmp[1] = -1;
		sum[0] = ft_find_path(a, n, 1);
		while (++i < 10)
			if (i != 6 && i != 1 && i != 2)
			{
				str = ft_get_instr(i, 1);
				ft_apply_isnstr(a, str, n, 0);
				tmp[0] = 1 + ft_find_path(a, n, 1);
				if (tmp[0] <= sum[0])
				{
					sum[0] = tmp[0];
					j = i;
					free(new->next->content);
					new->next->content = ft_strdup(str);
				}
				// printf("Sums sum[0]: %d - tmp[0]: %d\n", sum[0], tmp[0]);
				// printf("i %d\n,n[0] %d, a[0] ", i, n[0]);
				// printf("n[0] %d, a[0] ", n[0]);
				// ft_print_arr(a[0], n[0]);
				// printf("n[1] %d, a[1] ", n[1]);
				// ft_print_arr(a[1], n[1]);
				// printf("\n");
				ft_apply_isnstr(a, ft_get_instr(ft_rev(i), 1), n, 0);
			}
		if (j >= 0)
		{
			// printf("applying %d\n", j);
			str = ft_get_instr(j, 1);
			ft_apply_isnstr(a, str, n, 0);
			free(new->next->content);
			new->next->content = ft_strdup(str);
		}
		if (ft_strcmp(new->next->content, "") == 0)
		{
			if (!ft_issorted(a[0], n[0], 2) && (j = -1))
			{
				// printf("applying mov_n_push\n");
				if (n[1] > 0)
				{
					j = ft_find_shift(a[1], a[0][0], n[1], -1);
					str = (j < 0) ? ft_get_instr(8, 1) : ft_get_instr(4, 1);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}
				}
				str = ft_get_instr(6, 1);
				ft_apply_isnstr(a, str, n, 0);
				// ft_find_path(a, n, sum);
				free(new->next->content);
				new->next->content = ft_strdup("mov_n_push");
			}
			else
			{
				// printf("applying merge\n");
				if (flag == 0)
				{
					j = ft_find_shift(a[1], n[0] + n[1] + 1, n[1], -1);
					str = (j < 0) ? ft_get_instr(8, 1) : ft_get_instr(4, 1);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}		
					j = ft_find_shift(a[0], 0, n[0], 1);
					str = (j < 0) ? ft_get_instr(7, 1) : ft_get_instr(3, 1);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}						
				}
				flag = 1;
				j = ft_find_shift(a[0], a[1][0], n[0], 1);
				str = (j < 0) ? ft_get_instr(7, 1) : ft_get_instr(3, 1);
				j = (j < 0) ? -j : j;
				while (j--)
				{
					ft_apply_isnstr(a, str, n, 0);
					op++;
				}
				str = ft_get_instr(10, 1);
				ft_apply_isnstr(a, str, n, 0);
				free(new->next->content);
				new->next->content = ft_strdup("merge");
			}						
		}
		// printf("Sums sum[0]: %d - tmp[0]: %d\n", sum[0], tmp[0]);
		// printf("i %d\n,n[0] %d, a[0] ", j, n[0]);
		// printf("n[0] %d, a[0] ", n[0]);
		// ft_print_arr(a[0], n[0]);
		// printf("n[1] %d, a[1] ", n[1]);
		// ft_print_arr(a[1], n[1]);
		// printf("\n");
		new = new->next;
	}
	return (op);
}

int	ft_ksmart_sort(int *a[2], int n[2], t_list **list)
{
	int		i;
	int		j;
	// int		sum[2];
	int		op;
	// int		tmp[2];
	char	*str;
	int		flag;
	t_list	*new;

	// ft_find_path(a, n, sum);
	printf("n[0] %d, a[0] ", n[0]);
	ft_print_arr(a[0], n[0]);
	printf("n[1] %d, a[1] ", n[1]);
	ft_print_arr(a[1], n[1]);
	printf("\n");
	op = 0;
	flag = 0;
	*list = ft_lstnew("", 1);
	new = *list;
	new->next = NULL;
	int steps = 20000;
	while (steps-- && (!ft_issorted(a[0], n[0], 1) || n[1]) && ++op)
	{
		new->next = ft_lstnew("", 1);
		i = -1;
		j = -1;
/*		tmp[0] = -1;
		tmp[1] = -1;
		while (++i < 10)
			if (i != 6 && i != 1 && i != 2)
			{
				str = ft_get_instr(i, 1);
				ft_apply_isnstr(a, str, n, 0);
				ft_find_path(a, n, tmp);
				if (tmp[0] < sum[0])
				{
					sum[0] = tmp[0];
					j = i;
					free(new->next->content);
					new->next->content = ft_strdup(str);
				}
				ft_apply_isnstr(a, ft_get_instr(ft_rev(i), 1), n, 0);
			}
		if (j >= 0)
		{
			ft_apply_isnstr(a, str, n, 0);
			ft_find_path(a, n, sum);
		}*/
		if (ft_strcmp(new->next->content, "") == 0)
		{
			if (!ft_issorted(a[0], n[0], 2) && (j = -1))
			{
				if (n[1] > 0)
				{
					j = ft_find_shift(a[1], a[0][0], n[1], -1);
					str = (j < 0) ? ft_get_instr(8, 1) : ft_get_instr(4, 1);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}
				}
				str = ft_get_instr(6, 1);
				ft_apply_isnstr(a, str, n, 0);
				// ft_find_path(a, n, sum);
				free(new->next->content);
				new->next->content = ft_strdup("mov_n_push");
			}
			else
			{
				if (flag == 0)
				{
					j = ft_find_shift(a[1], n[0] + n[1] + 1, n[1], -1);
					str = (j < 0) ? ft_get_instr(8, 1) : ft_get_instr(4, 1);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}		
					j = ft_find_shift(a[0], 0, n[0], 1);
					str = (j < 0) ? ft_get_instr(7, 1) : ft_get_instr(3, 1);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}						
				}
				flag = 1;
				j = ft_find_shift(a[0], a[1][0], n[0], 1);
				str = (j < 0) ? ft_get_instr(7, 1) : ft_get_instr(3, 1);
				j = (j < 0) ? -j : j;
				while (j--)
				{
					ft_apply_isnstr(a, str, n, 0);
					op++;
				}
				str = ft_get_instr(10, 1);
				ft_apply_isnstr(a, str, n, 0);
				free(new->next->content);
				new->next->content = ft_strdup("merge");
			}						
		}
		// printf("Sums sum[0]: %d - tmp[0]: %d\n sum[1]: %d - tmp[1] %d\n", sum[0], tmp[0], sum[1], tmp[1]);
		// printf("i %d\n,n[0] %d, a[0] ", j, n[0]);
		// printf("n[0] %d, a[0] ", n[0]);
		// ft_print_arr(a[0], n[0]);
		// printf("n[1] %d, a[1] ", n[1]);
		// ft_print_arr(a[1], n[1]);
		// printf("\n");
		new = new->next;
	}
	return (op);
}

// int	ft_brute_sort(int *a[2], int n[2], int iter, t_list **list, int iprev)
// {
// 	int	i;
// 	int	j;
// 	int	tmp;
// 	// char	*instr;
// 	// t_list	*new;

// 	if (iprev == -1)
// 		printf("max iter %d\n", iter);
// 	if (!ft_issorted(a[0], n[0], 1) || n[1] > 0)
// 	{
// 		if (iter)
// 		{
// 			i = -1;
// 			j = -1;
// 			tmp = 0;
// 			(!(*list)) ? *list = ft_lstnew("", 1) : 0;
// 			// (*list)->next = ft_lstnew("", 1);
// 			while (++i < 11 && iter)
// 				if ((i == 6 && n[0] && iprev != 10) || (i == 10 && n[1] && iprev != 6) || (i < 3 && iprev != i)
// 					|| (i >= 3 && i < 6 && iprev != i + 4) || ( i >= 7 && i < 10 && iprev != i - 4))
// 				{
// 					// instr = ft_get_instr(i, 1);
// 					ft_apply_isnstr(a, ft_get_instr(i, 1), n, 0);
// 					// printf("OUT it: %d i: %d j: %d, tmp %d, n[0] %d\n", iter, i, j, tmp, n[0]);
// 					if ((tmp = ft_brute_sort(a, n, iter - 1, &((*list)->next), i)) >= 0)
// 					{
// 						// printf("BEFORE j: %d, iter %d |\n", j, iter);
// 						// if (j >= 0)
// 						// {
// 						// 	((*list)->next) ? ft_lstclr(&((*list)->next)) : 0;
// 						// 	(*list)->next = NULL;
// 						// }
// 						free((*list)->content);
// 						(*list)->content = ft_strdup(ft_get_instr(i, 1));
// 						j = i;
// 						iter = tmp;
// 						// printf("AFTER j: %d, tmp %d |\n", j, tmp);
// 						// ft_lstprint(*list);
// 						// ft_print_arr(a[0], n[0]);
// 						// ft_print_arr(a[1], n[1]);
// 					}
// 					ft_apply_isnstr(a, ft_get_instr(i, -1), n, 0);
// 					// if (tmp == 1)
// 					// 	return (2);
// 				}
// 			if (j < 0)
// 				return (-1);
// 			return (1 + iter);
// 		}
// 		return (-1);
// 	}
// 	// printf("clear list tail\n");
// 	((*list)) ? ft_lstclr(&(*list)) : 0;
// 	*list = NULL;
// 	return (0);
// }

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

int	ft_bb_sort(int *a, int *b, int n)
{
	int	i;
	int	j;
	int	tmp;
	int	res;

	j = -1;
	if (!b)
		return (0);
	res = 0;
	while (++j < n / 2)
	{
		i = j - 1;
		if (j > 0 && j * 2 < n - 1)
		{
			res++;
			// ft_putstr("ra\n");
		}
		while (++i < n - j - 1)
		{
			if (a[i] > a[i + 1])
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				res++;
				// ft_putstr("sa\n");
				// ft_print_arr(a, n);
			}
			if (i != n - j - 2)
			{
				res++;
				// ft_putstr("ra\n");
			}
			// ft_checksort(a, i);
		}
		while (i-- > j + 1)
		{
			res++;
			// ft_putstr("rra\n");
			if (a[i] < a[i - 1])
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				res++;
				// ft_putstr("sa\n");
				// ft_print_arr(a, n);
			}
		}
	}
	while (--j)
	{
		res++;
		// ft_putstr("rra\n");		
	}
	if (res > 0)
		return (res - 1);
	return (res);
}
