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

int	ft_check_instr(char *line)
{
	if (!ft_strcmp(line, "ss"))
		return (1);
	if (!ft_strcmp(line, "sa"))
		return (1);
	if (!ft_strcmp(line, "sb"))
		return (1);
	if (!ft_strcmp(line, "rr"))
		return (1);
	if (!ft_strcmp(line, "ra"))
		return (1);
	if (!ft_strcmp(line, "rb"))
		return (1);
	if (!ft_strcmp(line, "pa"))
		return (1);
	if (!ft_strcmp(line, "pb"))
		return (1);
	if (!ft_strcmp(line, "rrr"))
		return (1);
	if (!ft_strcmp(line, "rra"))
		return (1);
	if (!ft_strcmp(line, "rrb"))
		return (1);
	return (0);
}

void	ft_free_n_exit(int *a[2], char *line, int err)
{
	(line) ? free(line) : 0;
	(a && a[0]) ? free(a[0]) : 0;
	(a && a[1]) ? free(a[1]) : 0;
	(err) ? ft_putstr_fd("Error\n", 2) : 0;
	exit(-err);
}

int		main(int argc, char **argv)
{
	int		*a[2];
	int		n[2];
	int		ret;
	int		dg;
	char	*line;

	if ((dg = argc - 1) < 1 || (dg == 2 && ft_strcmp(argv[1], "-v")) || dg > 2)
		ft_free_n_exit(NULL, NULL, 1);
	n[0] = 0;
	n[1] = 0;
	if (!(a[0] = ft_atoi_tab(ft_strsplit(argv[dg], ' '), &n[0])) ||
		!ft_arrcheck(a[0], n[0]) || !(a[1] = (int*)malloc(sizeof(int) * n[0])))
		ft_free_n_exit(a, NULL, 1);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		(!line || !ft_check_instr(line)) ? ft_free_n_exit(a, line, 1) : 0;
		ft_apply_isnstr(a, line, n, dg - 1);
		free(line);
	}
	(ret == -1) ? ft_free_n_exit(a, NULL, 1) : 0;
	(ft_issorted(a[0], n[0], 1) && !n[1]) ? ft_putstr_fd("OK\n", 1)
	: ft_putstr_fd("KO\n", 1);
	ft_free_n_exit(a, NULL, 0);
	return (0);
}
