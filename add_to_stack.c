/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:09:50 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/04 14:59:50 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addstack_end(t_stack **top, int num)
{
	t_stack	*tmp;

	if (*top)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			exit(1);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->num = num;
	}
	else
	{
		*top = (t_stack *)malloc(sizeof(t_stack));
		if (!*top)
			exit(1);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->num = num;
	}
}

void	ad_top(t_stack **lst, int num)
{
	t_stack	*tmp;

	if (*lst != NULL)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			exit(1);
		tmp->next = *lst;
		tmp->prev = (*lst)->prev;
		(*lst)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->num = num;
		*lst = (*lst)->prev;
	}
	else
	{
		*lst = (t_stack *)malloc(sizeof(t_stack));
		if (!lst)
			exit(1);
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
		(*lst)->num = num;
	}
}

void	rm_top(t_stack **lst)
{
	t_stack	*tmp;

	if ((*lst)->next == *lst)
		free(*lst);
	else
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->prev->next = *lst;
		(*lst)->prev = tmp->prev;
		free(tmp);
	}
}
