/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:10:38 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/08 01:24:17 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_num(t_data *data, int i)
{
	t_stack	*tmp;

	tmp = data->a;
	if (i > data->a_len)
		return (-1);
	while (i > 0)
	{
		tmp = tmp->next;
		i--;
	}
	return (tmp->num);
}

void	sort_3(t_data *data)
{
	if (lst_num(data, 0) > lst_num(data, 1))
	{
		if (lst_num(data, 0) < lst_num(data, 2))
			sa_sb_ss(data, 'a');
		else if (lst_num(data, 1) < lst_num(data, 2))
			ra_rb_rr(data, 'a');
		else
		{
			sa_sb_ss(data, 'a');
			rra_rrb_rrr(data, 'a');
		}
	}
	else if (lst_num(data, 0) < lst_num(data, 1))
	{
		if (lst_num(data, 0) > lst_num(data, 2))
			rra_rrb_rrr(data, 'a');
		else
		{
			sa_sb_ss(data, 'a');
			ra_rb_rr(data, 'a');
		}
	}
}

void	sort_4(t_data *data)
{
	rotate_up_down(data, data->a_len, smallest(data->a, data->a->next,
			data->a_len), 'a');
	ft_pb(data);
	sort_3(data);
	ft_pa(data);
}

void	sort_5(t_data *data)
{
	rotate_up_down(data, data->a_len, smallest(data->a, data->a->next,
			data->a_len), 'a');
	ft_pb(data);
	rotate_up_down(data, data->a_len, smallest(data->a, data->a->next,
			data->a_len), 'a');
	ft_pb(data);
	if (is_sorted(data))
		sort_3(data);
	ft_pa(data);
	ft_pa(data);
}

void	sort(t_data *data)
{
	if (data->a_len == 1)
		return ;
	else if (data->a_len == 2)
	{
		if (data->a->num > data->a->next->num)
			sa_sb_ss(data, 'a');
	}
	else if (data->a_len == 3)
		sort_3(data);
	else if (data->a_len == 4)
		sort_4(data);
	else if (data->a_len == 5)
		sort_5(data);
	else if (data->a_len < 15)
		sort_15(data);
	else if (data->a_len < 200)
		sort_small(data);
	else
		sort_big(data);
}
