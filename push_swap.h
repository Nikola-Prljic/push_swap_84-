/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:05:13 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/08 01:22:18 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf_libft/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	long int		num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				a_len;
	int				b_len;
	int				one_eighth;
	int				one_quater;
	int				three_eighth;
	int				median;
	int				five_eighth;
	int				three_quater;
	int				seven_eighth;
}					t_data;

// check numbers and num to stack
int					argv_to_stack(t_data *data, int y, char **argv);
void				extract_number(t_data *data, char **str, int y);

// add to stacks
void				ad_top(t_stack **lst, int num);
void				rm_top(t_stack **lst);
void				addstack_end(t_stack **top, int num);

// free and error
void				push_swap_error(t_data *data);
void				free_stacks(t_data *data);

//OPARATIONS
void				ft_pa(t_data *data);
void				ft_pb(t_data *data);
void				ra_rb_rr(t_data *data, char c);
void				rra_rrb_rrr(t_data *data, char c);
void				sa_sb_ss(t_data *data, char stack);
void				rotate_up_down(t_data *data, int len, int pos, char stack);

//sort actions
int					is_sorted(t_data *data);
void				move_to_a(t_data *data);
void				rotate_if_smaller(t_data *data);
int					biggest(t_stack *n1, t_stack *n2, int len);
int					smallest(t_stack *n1, t_stack *n2, int len);
int					something_in_range(t_data *data, t_stack *top, char c);
void				bigger_median(t_data *data, int eighth);

//sort
void				sort(t_data *data);
void				sort_3(t_data *data);
void				sort_5(t_data *data);
void				sort_15(t_data *data);
void				sort_small(t_data *data);
void				sort_big(t_data *data);

//median
void				meridian(t_data *data);

#endif