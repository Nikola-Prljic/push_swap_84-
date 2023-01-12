/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_ulties.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:20:00 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/08 01:22:40 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_if_smaller(t_data *data)
{
	if (data->b != NULL && data->a->num < data->b->num)
		ra_rb_rr(data, 'b');
	ft_pb(data);
}

void	smaller_quater(t_data *data, int quater)
{
	if (quater == 7)
	{
		if (data->a->num >= data->one_eighth && data->a->num < data->one_quater)
			rotate_if_smaller(data);
		else
			ra_rb_rr(data, 'a');
	}
	else
	{
		if (data->a->num < data->one_eighth)
			rotate_if_smaller(data);
		else
			ra_rb_rr(data, 'a');
	}
}

void	smaller_median(t_data *data, int quater)
{
	if (quater == 5)
	{
		if (data->a->num >= data->three_eighth && data->a->num < data->median)
			rotate_if_smaller(data);
		else
			ra_rb_rr(data, 'a');
	}
	else if (quater == 6)
	{
		if (data->a->num >= data->one_quater
			&& data->a->num < data->three_eighth)
			rotate_if_smaller(data);
		else
			ra_rb_rr(data, 'a');
	}
	else
		smaller_quater(data, quater);
}

void	smaller_tree_quater(t_data *data, int quater)
{
	if (quater == 3)
	{
		if (data->a->num >= data->five_eighth
			&& data->a->num < data->three_quater)
			rotate_if_smaller(data);
		else
			ra_rb_rr(data, 'a');
	}
	else if (quater == 4)
	{
		if (data->a->num >= data->median && data->a->num < data->five_eighth)
			rotate_if_smaller(data);
		else
			ra_rb_rr(data, 'a');
	}
	else
		smaller_median(data, quater);
}

void	bigger_median(t_data *data, int eighth)
{
	if (eighth == 1)
	{
		if (data->a->num >= data->seven_eighth)
			rotate_if_smaller(data);
		else
			ra_rb_rr(data, 'a');
	}
	else if (eighth == 2)
	{
		if (data->a->num >= data->three_quater
			&& data->a->num < data->seven_eighth)
			rotate_if_smaller(data);
		else
			ra_rb_rr(data, 'a');
	}
	else
		smaller_tree_quater(data, eighth);
}
