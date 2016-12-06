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

int		*ft_atoi_tab(char **tab, int *len)
{
	int		i;
	int		*itab;

	if (!tab)
		return (0);
	i = 0;
	while(tab[i])
		i++;
	*len = i;
	itab = NULL;
	if (!(itab = (int*)malloc(sizeof(int) * (*len))))
	{
		ft_mapfree(&tab);
		return (0);
	}
	i = -1;
	while (++i < *len)
	{
		if (!ft_strcheck(tab[i]))
			return (0);
		itab[i] = ft_atoi(tab[i]);
		free(tab[i]);
	}
	free(tab);
	return (itab);
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
