/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:41:53 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/30 20:41:55 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#define MALLOC_G(x, y) ((!x) ? {return (y);} : 0)

int		*ft_atoi_tab(char **tab, int *len);
void	ft_swap(int *a, int *b);
void	ft_rot(int *a, int n, int shift);
void	ft_push(int *a, int *b, int *n, int *m);
void	ft_print_arr(int *a, int n);

void	ft_apply_isnstr(int *arr, int *brr, char *line, int n[2])
{
	(!ft_strcmp(line, "sa")) ? ft_swap(&arr[0], &arr[1]) : 0;
	(!ft_strcmp(line, "sb")) ? ft_swap(&brr[0], &brr[1]) : 0;
	if (!ft_strcmp(line, "ss"))
	{
		ft_swap(&arr[0], &arr[1]);
		ft_swap(&brr[0], &brr[1]);
	}
	(!ft_strcmp(line, "ra")) ? ft_rot(arr, n[0], 1) : 0;
	(!ft_strcmp(line, "rb")) ? ft_rot(brr, n[1], 1) : 0;
	if (!ft_strcmp(line, "rr"))
	{
		ft_rot(arr, n[0], 1);
		ft_rot(brr, n[1], 1);
	}	
	(!ft_strcmp(line, "pb")) ? ft_push(arr, brr, &n[0], &n[1]) : 0;
	(!ft_strcmp(line, "pa")) ? ft_push(brr, arr, &n[1], &n[0]) : 0;
	(!ft_strcmp(line, "rra")) ? ft_rot(arr, n[0], -1) : 0;
	(!ft_strcmp(line, "rrb")) ? ft_rot(brr, n[1], -1) : 0;
	if (!ft_strcmp(line, "rrr"))
	{
		ft_rot(arr, n[0], -1);
		ft_rot(brr, n[1], -1);
	}
	printf("%s: ", line);
	ft_print_arr(arr, n[0]);
}

int		ft_ifsorted(int *arr, int n)
{
	int		i;

	i = -1;
	while (++i < n - 1)
		if (arr[i] > arr[i + 1])
			return (0);
	return (1);
}

/*
**Still need error checker for input: numbers, out of integer range, duplicates
*/

int		main(int argc, char **argv)
{
	int		*arr;
	int		*brr;
	int		n[2];
	int		ret;
	char	*line;

	if (argc < 2)
		return (0);
	n[0] = 0;
	n[1] = 0;
	if (!(arr = ft_atoi_tab(ft_strsplit(argv[1], ' '), &n[0])) || 
		!(brr = (int*)malloc(sizeof(int) * n[0])))
	{
		(arr) ? free(arr) : 0;
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}	
	while ((ret = get_next_line(0, &line)) > 0)
		ft_apply_isnstr(arr, brr, line, n);
	if (ret == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (ft_ifsorted(arr, n[0]))
		ft_putstr_fd("OK\n", 1);	
	else
	{
		ft_putstr_fd("KO\n", 1);
		ft_print_arr(arr, n[0]);
	}
	return (0);
}