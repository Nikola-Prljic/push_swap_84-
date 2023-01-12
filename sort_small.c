/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:37:52 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/07 23:54:41 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns 1 when bigger or smaller change with b or s

void	smaller_median_rotate(t_data *data)
{
	if (data->a->num < data->median)
	{
		if (data->b != NULL && data->a->num < data->b->num)
			ra_rb_rr(data, 'b');
		ft_pb(data);
	}
	else
		ra_rb_rr(data, 'a');
}

void	move_to_b(t_data *data, char big)
{
	int	len;

	len = data->a_len;
	while (len > 0)
	{
		if (something_in_range(data, data->a, 'b'))
			return ;
		if (big == 'b')
		{
			if (data->a->num >= data->median)
			{
				if (data->b != NULL && data->a->num < data->b->num)
					ra_rb_rr(data, 'b');
				ft_pb(data);
			}
			else
				ra_rb_rr(data, 'a');
		}
		else
			smaller_median_rotate(data);
		len--;
	}
}

void	move_to_a(t_data *data)
{
	int	len;

	len = data->b_len;
	while (len > 0)
	{
		rotate_up_down(data, data->b_len, biggest(data->b, data->b->next,
				data->b_len), 'b');
		ft_pa(data);
		len--;
	}
}

void	sort_small(t_data *data)
{
	move_to_b(data, 'b');
	move_to_a(data);
	move_to_b(data, 's');
	move_to_a(data);
}

void	sort_15(t_data *data)
{
	int	len;

	len = data->a_len;
	while (len > 0)
	{
		rotate_up_down(data, data->a_len, smallest(data->a, data->a->next,
				data->a_len), 'a');
		if (len > 5)
			ft_pb(data);
		else
		{
			sort_5(data);
			break ;
		}
		len--;
	}
	len = data->b_len;
	while (len > 0)
	{
		ft_pa(data);
		len--;
	}
}
