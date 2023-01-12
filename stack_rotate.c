/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:02:43 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/05 16:06:35 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_stack *stack, int len, char c)
{
	int	tmp;

	tmp = stack->num;
	while (len > 0)
	{
		stack->num = stack->next->num;
		stack = stack->next;
		len--;
	}
	stack->prev->num = tmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	ra_rb_rr(t_data *data, char c)
{
	if (c == 'a' && data->a)
		rotate_up(data->a, data->a_len, c);
	if (c == 'b' && data->b)
		rotate_up(data->b, data->b_len, c);
	else if (c == 'r' && data->a && data->b)
	{
		rotate_up(data->a, data->a_len, c);
		rotate_up(data->b, data->b_len, c);
		write(1, "rr\n", 3);
	}
}

void	rotate_down(t_stack *stack, int len, char c)
{
	int	tmp;

	tmp = stack->num;
	while (len > 0)
	{
		stack->num = stack->prev->num;
		stack = stack->prev;
		len--;
	}
	stack->next->num = tmp;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rra_rrb_rrr(t_data *data, char c)
{
	if (c == 'a' && data->a)
		rotate_down(data->a, data->a_len, c);
	if (c == 'b' && data->b)
		rotate_down(data->b, data->b_len, c);
	else if (c == 'r' && data->a && data->b)
	{
		rotate_down(data->a, data->a_len, c);
		rotate_down(data->b, data->b_len, c);
		write(1, "rrr\n", 4);
	}
}
