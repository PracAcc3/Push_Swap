/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:13:14 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/09 17:13:14 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}	t_stack_node;

int				ft_isspace(int c);
int				ft_issign(int c);
void			free_argv(char **argv);
int				ps_error(void);
int				error_syntax(char *token);
int				error_duplicate(t_stack_node *stack, int nbr);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **stack);
char			**split(char *s, char c);
void			init_stack_a(t_stack_node **stack_a, char **argv,
					bool free_args_on_error);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack,
					t_stack_node *node_to_top, char stack_id);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *stack_a, t_stack_node *stack_b);
void			init_nodes_b(t_stack_node *stack_a, t_stack_node *stack_b);
void			ps_rotate_both_stacks(t_stack_node **stack_a,
					t_stack_node **stack_b, t_stack_node *node);
void			ps_rev_rotate_both_stacks(t_stack_node **stack_a,
					t_stack_node **stack_b, t_stack_node *node);
void			ps_push_cheapest_a_to_b(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			ps_rotate_min_to_top(t_stack_node **stack_a);
void			ps_push_min_to_b(t_stack_node **stack_a,
				t_stack_node **stack_b);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b, bool silent);
void			pb(t_stack_node **stack_b, t_stack_node **stack_a, bool silent);
void			sa(t_stack_node **stack_a, bool silent);
void			ra(t_stack_node **stack_a, bool silent);
void			rb(t_stack_node **stack_b, bool silent);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b, bool silent);
void			rra(t_stack_node **stack_a, bool silent);
void			rrb(t_stack_node **stack_b, bool silent);
void			rrr(t_stack_node **stack_a,
					t_stack_node **stack_b, bool silent);
void			sort_three(t_stack_node **stack_a);
void			sort_four(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_five(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b);

#endif