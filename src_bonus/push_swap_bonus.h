/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:22:14 by francfer          #+#    #+#             */
/*   Updated: 2024/02/27 18:13:07 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}					t_node;

t_node				*fill_stack_values(char **av);
t_node				*fill_stack_values1(int ac, char **av);
void				assign_index(t_node *stack_a, int ac);

int					is_sorted(t_node *stack);
void				tiny_sort(t_node **stack);
void				sort(t_node **stack_a, t_node **stack_b);

int					get_lowest_index_position(t_node **stack);
void				get_target_position(t_node **stack_a, t_node **stack_b);

void				get_cost(t_node **stack_a, t_node **stack_b);
void				do_cheapest_move(t_node **stack_a, t_node **stack_b);

void				do_move(t_node **a, t_node **b, int cost_a, int cost_b);

void				push(t_node **src, t_node **dest);
void				do_pa(t_node **stack_a, t_node **stack_b);
void				do_pb(t_node **stack_a, t_node **stack_b);
void				swap(t_node *stack);
void				do_sa(t_node **stack_a);
void				do_sb(t_node **stack_b);
void				do_ss(t_node **stack_a, t_node **stack_b);
void				rotate(t_node **stack);
void				do_ra(t_node **stack_a);
void				do_rb(t_node **stack_b);
void				rev_rotate(t_node **stack);
void				do_rr(t_node **stack_a, t_node **stack_b);
void				do_rrr(t_node **stack_a, t_node **stack_b);
void				do_rra(t_node **stack_a);
void				do_rrb(t_node **stack_b);

t_node				*get_stack_bottom(t_node *stack);
t_node				*get_stack_before_bottom(t_node *stack);
t_node				*stack_new(int value);
void				stack_add_bottom(t_node **stack, t_node *new);
int					get_stack_size(t_node *stack);

void				free_stack(t_node **stack);
long int			ft_atoi(const char *str);
void				ft_putstr(char *str);
int					nb_abs(int nb);

void				exit_error(t_node **stack_a, t_node **stack_b);

int					is_correct_input(char **av);
int					is_correct_input1(char **av);
int					is_digit(char c);
int					is_sign(char c);
int					nbstr_cmp(const char *s1, const char *s2);
int					determinesign(const char **s);
void				skipzeros(const char **s);
int					length(const char *s, int sign);

char				**ft_split(char *str);
int					word_count(char *str);
int					splited_size(char **words);
void				free_list(char **list);

char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(char *s);
char				*ft_strchr(char *s, int c);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_free(char **str);
char				*clean_storage(char *storage);
char				*new_line(char *storage);
char				*readbuf(int fd, char *storage);
char				*get_next_line(int fd);

void				print_checker_res(t_node **stack_a, t_node **stack_b);
void				do_commands(char *line, t_node **stack_a, t_node **stack_b);
int					ft_strcmp(const char *s1, const char *s2);
int					check_line(char *line);
void				commands(t_node *stack_a, t_node *stack_b);

#endif