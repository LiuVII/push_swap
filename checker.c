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

#include "push_swap.h"

/*
**Still need error checker for input: numbers, out of integer range, duplicates
*/

int		main(int argc, char **argv)
{
	int		*a[2];
	int		n[2];
	int		ret;
	char	*line;

	if (argc < 2)
		return (0);
	n[0] = 0;
	n[1] = 0;
	if (!(a[0] = ft_atoi_tab(ft_strsplit(argv[1], ' '), &n[0])) || 
		!(a[1] = (int*)malloc(sizeof(int) * n[0])))
	{
		(a[0]) ? free(a[0]) : 0;
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}	
	while ((ret = get_next_line(0, &line)) > 0)
		ft_apply_isnstr(a, line, n, 1);
	if (ret == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (ft_issorted(a[0], n[0], 1))
		ft_putstr_fd("OK\n", 1);	
	else
	{
		ft_putstr_fd("KO\n", 1);
		ft_print_arr(a[0], n[0]);
	}
	return (0);
}