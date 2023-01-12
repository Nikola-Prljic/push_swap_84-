/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:25:32 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/08 01:02:45 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_tester(t_data *data, char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		while (argv[i] == ' ')
			i++;
		if (argv[i] == '-')
		{
			if (argv[i + 1] < '0' || argv[i + 1] > '9')
				push_swap_error(data);
			i++;
		}
		while (argv[i] && argv[i] != ' ')
		{
			if (argv[i] < '0' || argv[i] > '9')
				push_swap_error(data);
			i++;
		}
	}
	return (0);
}

int	is_dubblue(t_data *data, t_stack *lst, int x, int y)
{
	int		count;
	t_stack	*temp;

	temp = lst;
	while (y > 0)
	{
		x = data->a_len;
		count = 0;
		while (x > 0)
		{
			if (lst->num == temp->num)
			{
				count++;
				if (count > 1)
					push_swap_error(data);
			}
			temp = temp->next;
			x--;
		}
		lst = lst->next;
		y--;
	}
	return (0);
}

int	is_sorted(t_data *data)
{
	t_stack	*n1;
	t_stack	*n2;
	int		len;

	n1 = data->a;
	n2 = data->a->next;
	len = data->a_len;
	while (len > 1)
	{
		if (n1->num > n2->num)
			return (1);
		n1 = n1->next;
		n2 = n2->next;
		len--;
	}
	return (0);
}

int	only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	argv_to_stack(t_data *data, int y, char **argv)
{
	y = 1;
	while (argv[y])
	{
		if (only_spaces(argv[y]))
			push_swap_error(data);
		str_tester(data, argv[y]);
		extract_number(data, argv, y);
		y++;
	}
	is_dubblue(data, data->a, data->a_len, data->a_len);
	return (0);
}
