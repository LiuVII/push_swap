/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:04:43 by mfilipch          #+#    #+#             */
/*   Updated: 2016/12/11 15:04:44 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_print_arr(int *a, int n)
{
	int		k;

	k = -1;
	while (++k < n)
	{
		ft_putnbr(a[k]);
		ft_putchar(' ');
	}
	ft_putstr("\n");
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

int		ft_rev(int i)
{
	if (i < 3)
		return (i);
	else if (i > 2 && i < 7)
		return (i + 4);
	else
		return (i - 4);
}

int		ft_brute_sort(int *a[2], int n[2], int iter, t_list **list)
{
	int	i;
	int	j;
	int	tmp;

	if ((!ft_issort(a[0], n[0], 1) || n[1] > 0) && (j = -1))
	{
		i = -1;
		(!(*list) && iter) ? *list = ft_lstnew("", 1) : 0;
		while (++i < 11 && iter)
			if ((i != 6 || n[0]) && (i != 10 || n[1]))
			{
				ft_apply_isnstr(a, ft_get_instr(i), n, 0);
				if ((tmp = ft_brute_sort(a, n, iter - 1, &((*list)->next))) >= 0
					&& (j = i) >= 0)
					iter = tmp;
				ft_apply_isnstr(a, ft_get_instr(ft_rev(i)), n, 0);
			}
		if (j < 0)
			return (-1);
		free((*list)->content);
		(*list)->content = ft_strdup(ft_get_instr(j));
		return (1 + iter);
	}
	((*list)) ? ft_lstclr(&(*list)) : 0;
	return (0);
}
