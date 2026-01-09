/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:30:35 by synoshah          #+#    #+#             */
/*   Updated: 2026/01/08 15:30:35 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	/* value */
	int					nbr;
	/* metadata recomputed during sorting */
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	/* algorithm links */
	struct s_stack_node	*target_node;
	/* list links */
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* libft / ft_printf */
int				ft_printf(const char *format, ...);
int				ft_isdigit(int c);

/* handle_errors */
int			error_syntax(char *token);
int			error_duplicate(t_stack_node *stack, int nbr);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **stack);

/* split */
char			**split(char *s, char c);

/* stack_init */
void			init_stack_a(t_stack_node **stack_a, char **argv,
					bool free_args_on_error);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack,
					t_stack_node *node_to_top, char stack_id);

/* utils */
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

/* init_a_to_b */
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *stack_a, t_stack_node *stack_b);

/* init_b_to_a */
void			init_nodes_b(t_stack_node *stack_a, t_stack_node *stack_b);

/* push */
void			pa(t_stack_node **stack_a, t_stack_node **stack_b, bool silent);
void			pb(t_stack_node **stack_b, t_stack_node **stack_a, bool silent);

/* swap */
void			sa(t_stack_node **stack_a, bool silent);

/* rotate */
void			ra(t_stack_node **stack_a, bool silent);
void			rb(t_stack_node **stack_b, bool silent);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b, bool silent);

/* rev_rotate */
void			rra(t_stack_node **stack_a, bool silent);
void			rrb(t_stack_node **stack_b, bool silent);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool silent);

/* sort */
void			sort_three(t_stack_node **stack_a);
void			sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b);

#endif