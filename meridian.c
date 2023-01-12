/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meridian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:16:19 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/07 20:41:10 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *i, int *x)
{
	int	tmp;

	tmp = *i;
	*i = *x;
	*x = tmp;
}

int	*make_array(t_data *data)
{
	int		i;
	int		*ary;
	t_stack	*top;

	i = 0;
	top = data->a;
	ary = malloc(data->a_len * sizeof(int));
	while (data->a_len > i)
	{
		ary[i] = top->num;
		top = top->next;
		i++;
	}
	return (ary);
}

int	is_ary_sorted(int *ary, int len)
{
	int	i;

	i = 0;
	while (len > 1)
	{
		if (ary[i] > ary[i + 1])
			return (1);
		len--;
		i++;
	}
	return (0);
}

int	sort_array(t_data *data, int *ary)
{
	int	i;

	i = 0;
	while (data->a_len - 1 > i)
	{
		if (ary[i] > ary[i + 1])
			ft_swap(&ary[i], &ary[i + 1]);
		i++;
	}
	return (0);
}

void	meridian(t_data *data)
{
	int	i;
	int	*ary;

	i = 0;
	ary = make_array(data);
	while (is_ary_sorted(ary, data->a_len))
		sort_array(data, ary);
	data->one_eighth = ary[data->a_len / 8];
	data->one_quater = ary[data->a_len / 4];
	data->three_eighth = ary[data->a_len / 8 * 3];
	data->median = ary[data->a_len / 2];
	data->five_eighth = ary[data->a_len / 8 * 5];
	data->three_quater = ary[data->a_len / 4 * 3];
	data->seven_eighth = ary[data->a_len / 8 * 7];
	free(ary);
}
