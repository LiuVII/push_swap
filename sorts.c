/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:41:46 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/30 20:41:47 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_arr(int *a, int n)
{
	int	k;

	k = -1;
	// printf("j: %d |", j);
	while (++k < n)
		printf("%d ", a[k]);
	printf("\n");	
}

char	*ft_get_instr(int i)
{
	char	*tmp;

	tmp = NULL;
	(i == 0) ? (tmp = "sa") : 0;
	(i == 1) ? (tmp = "sb") : 0;
	(i == 2) ? (tmp = "ss") : 0;
	(i == 3) ? (tmp = "ra") : 0;
	(i == 4) ? (tmp = "rb") : 0;
	(i == 5) ? (tmp = "rr") : 0;
	(i == 6) ? (tmp = "pb") : 0;
	(i == 7) ? (tmp = "rra") : 0;
	(i == 8) ? (tmp = "rrb") : 0;
	(i == 9) ? (tmp = "rrr") : 0;
	(i == 10) ? (tmp = "pa") : 0;
	return (tmp);
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

int		ft_find_path(int *a[2], int n[2], int depth)
{
	int		i;
	int		curr;	
	int		tot;

	i = -1;
	tot = 0;
	if (!ft_issorted(a[0], n[0], 2) && depth)
		while (++i < n[0])
		{
			curr = ft_find_shift(a[1], a[0][i], n[1], -1);
			if ((i <= n[0] - i && curr >=0) || (i > n[0] - i && curr < 0))
				curr = MAX(MIN(i, n[0] - i), ABS(curr));
			else if (i <= n[0] - i || i > n[0] - i)
				curr = MIN(i, n[0] - i) + ABS(curr);
			if (i == 0 || curr < tot)
				tot = curr;
		}
	return (tot + 1);
}

int	ft_smart_sort(int *a[2], int n[2], t_list **list)
{
	int		i;
	int		j;
	int		sum[2];
	int		op;
	int		tmp[2];
	char	*str;
	int		flag;
	t_list	*new;

	printf("n[0] %d, a[0] ", n[0]);
	ft_print_arr(a[0], n[0]);
	printf("\n");
	op = 0;
	flag = 0;
	*list = ft_lstnew("", 1);
	new = *list;
	new->next = NULL;
	while ((!ft_issorted(a[0], n[0], 1) || n[1]) && ++op)
	{
		new->next = ft_lstnew("", 1);
		i = -1;
		j = -1;
		tmp[0] = -1;
		sum[0] = ft_find_path(a, n, 1);
		while (++i < 10)
			if (i != 6 && i != 1 && i != 2)
			{
				str = ft_get_instr(i);
				ft_apply_isnstr(a, str, n, 0);
				tmp[0] = 1 + ft_find_path(a, n, 1);
				if (tmp[0] <= sum[0])
				{
					sum[0] = tmp[0];
					j = i;
				}
				ft_apply_isnstr(a, ft_get_instr(ft_rev(i)), n, 0);
			}
		if (j >= 0)
		{
			str = ft_get_instr(j);
			ft_apply_isnstr(a, str, n, 0);
			free(new->next->content);
			new->next->content = ft_strdup(str);
		}
		if (ft_strcmp(new->next->content, "") == 0)
		{
			if (!ft_issorted(a[0], n[0], 2) && (j = -1))
			{
				if (n[1] > 0)
				{
					j = ft_find_shift(a[1], a[0][0], n[1], -1);
					str = (j < 0) ? ft_get_instr(8) : ft_get_instr(4);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						free(new->next->content);
						new->next->content = ft_strdup(str);
						new = new->next;
						new->next = ft_lstnew("", 1);
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}
				}
				str = ft_get_instr(6);
				ft_apply_isnstr(a, str, n, 0);
				free(new->next->content);
				new->next->content = ft_strdup(str);
			}
			else
			{
				if (flag == 0)
				{
					j = ft_find_shift(a[1], 214748364, n[1], -1);
					str = (j < 0) ? ft_get_instr(8) : ft_get_instr(4);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						free(new->next->content);
						new->next->content = ft_strdup(str);
						new = new->next;
						new->next = ft_lstnew("", 1);
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}		
					j = ft_find_shift(a[0], -214748364, n[0], 1);
					str = (j < 0) ? ft_get_instr(7) : ft_get_instr(3);
					j = (j < 0) ? -j : j;
					while (j--)
					{
						free(new->next->content);
						new->next->content = ft_strdup(str);
						new = new->next;
						new->next = ft_lstnew("", 1);
						ft_apply_isnstr(a, str, n, 0);
						op++;
					}						
				}
				flag = 1;
				j = ft_find_shift(a[0], a[1][0], n[0], 1);
				str = (j < 0) ? ft_get_instr(7) : ft_get_instr(3);
				j = (j < 0) ? -j : j;
				while (j--)
				{
					free(new->next->content);
					new->next->content = ft_strdup(str);
					new = new->next;
					new->next = ft_lstnew("", 1);
					ft_apply_isnstr(a, str, n, 0);
					op++;
				}
				str = ft_get_instr(10);
				ft_apply_isnstr(a, str, n, 0);
				free(new->next->content);
				new->next->content = ft_strdup(str);
			}						
		}
		new = new->next;
	}
	return (op);
}
