/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:01:07 by hece              #+#    #+#             */
/*   Updated: 2023/02/16 17:09:12 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int				nbr;
	struct s_stack	*next;
}				t_stack;

// ps_rotate_and_push.c 

int		ft_make_rarb(t_stack **stack_a, t_stack **stack_b, int nbr, char s);
int		ft_make_rrarrb(t_stack **stack_a, t_stack **stack_b, int nbr, char s);
int		ft_make_rrarb(t_stack **stack_a, t_stack **stack_b, int nbr, char s);
int		ft_make_rarrb(t_stack **stack_a, t_stack **stack_b, int nbr, char s);

// ps_rotate_type.c

int		ft_rotate_type_ba(t_stack *stack_a, t_stack *stack_b);
int		ft_rotate_type_ab(t_stack *stack_a, t_stack *stack_b);

// ps_solver.c

int		ft_calc_rarb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod);
int		ft_calc_rrarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod);
int		ft_calc_rrarb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod);
int		ft_calc_rarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod);

// push_swap_check.c

int		ft_is_sorted(t_stack *stack);
int		ft_is_duplicate(t_stack *stack);
int		ft_check_args(int ac, char *av[]);

// push_swap_find.c

int		ft_find_index(t_stack *stack, int nbr);
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
int		ft_find_place_a(t_stack *stack_a, int nbr_push);

// push_swap_rules.c

void	ft_sa(t_stack **stack_a, int num);
void	ft_sb(t_stack **stack_b, int num);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int num);

// push_swap_rules_two.c

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int num);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int num);
void	ft_ra(t_stack **stack_a, int num);
void	ft_rb(t_stack **stack_b, int num);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int num);

// push_swap_rules_three.c

void	ft_rra(t_stack **stack_a, int num);
void	ft_rrb(t_stack **stack_b, int num);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int num);

// push_swap_sort.c

void	ft_sort_three(t_stack **stack_a);
void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
t_stack	**ft_sort_b(t_stack **stack_a, t_stack **stack_b);
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);

// push_swap_split.c

char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	word_count(const char *s, char c);
char	*ft_strcreate(const char *s, char c, size_t counter);
char	**ft_split(char const *s, char c);

// push_swap_split_utils.c

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

// push_swap_stack_utils.c

void	ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		ft_stack_min(t_stack *stack);
int		ft_stack_max(t_stack *stack);

// push_swap_utils.c

t_stack	*ft_create_new_stack(int nbr);
int		ft_atoi(const char *str);
t_stack	*ft_split_check(char *av[]);
t_stack	*ft_create_and_fill_stack(int ac, char *av[]);

// push_swap_utils_two.c

void	ft_error(void);
void	ft_free(t_stack *stack);
void	ft_free_str(char **str);

#endif
