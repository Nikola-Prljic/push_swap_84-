/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:11:14 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/07 23:38:58 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(t_stack *n1, t_stack *n2, int len)
{
	int	i;
	int	x;

	x = 0;
	while (x < len)
	{
		i = 0;
		while (n1->num < n2->num)
		{
			i++;
			if (len - 1 == i)
				return (x);
			n2 = n2->next;
		}
		n1 = n1->next;
		n2 = n1->next;
		x++;
	}
	return (-69);
}

int	biggest(t_stack *n1, t_stack *n2, int len)
{
	int	i;
	int	x;

	x = 0;
	while (x < len)
	{
		i = 0;
		while (n1->num > n2->num)
		{
			i++;
			if (len - 1 == i)
				return (x);
			n2 = n2->next;
		}
		n1 = n1->next;
		n2 = n1->next;
		x++;
	}
	return (-69);
}

void	rotate_up_down(t_data *data, int len, int pos, char stack)
{
	int	rrr;

	rrr = len - pos;
	if (len / 2 >= pos)
	{
		while (pos > 0)
		{
			ra_rb_rr(data, stack);
			pos--;
		}
	}
	else
	{
		while (rrr > 0)
		{
			rra_rrb_rrr(data, stack);
			rrr--;
		}
	}
}

int	something_in_range(t_data *data, t_stack *top, char c)
{
	int	i;
	int	x;
	int	len;

	x = 0;
	len = data->a_len;
	while (x < len)
	{
		i = 0;
		if (c == 'b' && top->num >= data->median)
			return (0);
		if (c == 's' && top->num < data->median)
			return (0);
		top = top->next;
		x++;
	}
	return (1);
}
