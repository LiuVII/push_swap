/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:21:41 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/30 22:21:42 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_n_exit(int *a[2], char *line, t_list *list, int err)
{
	(line) ? free(line) : 0;
	(a && a[0]) ? free(a[0]) : 0;
	(a && a[1]) ? free(a[1]) : 0;
	(list) ? ft_lstclr(&list) : 0;
	(err) ? ft_putstr_fd("Error\n", 2) : 0;
	exit(-err);
}

int		*read_from_file(int flag, char *filename, int *n)
{
	int		*arr;
	char	*line;
	int		fd;

	fd = 0;
	line = NULL;
	if (flag == 1)
		fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_free_n_exit(NULL, NULL, NULL, 1);
	if (get_next_line(fd, &line) < 0)
		ft_free_n_exit(NULL, NULL, NULL, 1);
	if (fd > 0 && close(fd) < 0)
		ft_free_n_exit(NULL, line, NULL, 1);
	arr = ft_atoi_tab(ft_strsplit(line, ' '), n, 1);
	free(line);
	return (arr);
}

int		main(int ac, char **av)
{
	int		*a[2];
	int		n[2];
	t_list	*list;
	int		flag;

	flag = 0;
	if (ac < 2 || (!ft_strcmp(av[1], "-f") && (flag = 1) && ac != 3))
		return (0);
	n[0] = 0;
	if ((flag > 0 && !(a[0] = read_from_file(flag, av[flag + 1], &n[0]))) ||
		(ac == 2 && !(a[0] = ft_atoi_tab(ft_strsplit(av[1], ' '), &n[0], 1)))
		|| (ac > flag + 2 && !(a[0] = ft_atoi_tab(&(av[1]), &n[0], 0))) ||
		!ft_arrcheck(a[0], n[0]) || !(a[1] = (int*)malloc(sizeof(int) * n[0])))
	{
		a[1] = NULL;
		ft_free_n_exit(a, NULL, NULL, 1);
	}
	n[1] = 0;
	list = ft_lstnew("", 1);
	(n[0] > 5) ? ft_smart_sort(a, n, &list)
	: ft_brute_sort(a, n, 10, &(list->next));
	ft_lstprint(list->next);
	ft_free_n_exit(a, NULL, list, 0);
	return (0);
}
