#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_node
{
    int				val;
    int				move_a;
    int				move_b;
    int				score;
    struct s_node	*next;
}	t_node;

typedef struct s_stacks
{
    t_node	*a;
    int		size_a;
    t_node 	*b;
    int		size_b;
}	t_stacks;

typedef struct	s_chunk
{
    int 	max_size;
    int 	size;
    int 	min;
    int 	max;
    t_node	*nodes;
}	t_chunk;

// analyze.c
t_node	*analyze(char **input, int size);

// presort.c
void	presort(t_stacks **stacks);

// basic_sort.c
void	basic_sort(t_stacks **stacks);

// node.c
t_node	*new_node(int val);
void	node_addback(t_node **list, t_node *new);
void	node_addfront(t_node **list, t_node *new);
void	ins_node(t_list **lst, t_list *new, t_list *prev, t_list *curr);
t_node	*get_best_node(t_node *stack);

// math.c
int 	abs(int x);
int 	max(int x, int y);
int 	min(int x, int y);

// chunks.c
t_list *init_chunks(int chunk_size, int nb_chunks, int last_chunk_size);
void	rotate_chunks(t_list **chunks);
void	reverse_rotate_chunks(t_list **chunks);
bool	is_in_chunk(t_node *node, t_chunk *chunk);
int		move_to_chunk(t_node *node, t_list *chunks, int stack_size);

// errors.c
void 	raise_error(int errcode);

// rotate.c
void	r(char *cmd, t_stacks **stacks);
void	chunks_r(char *cmd, t_stacks **stacks);

// push.c
void	p(char stack, t_stacks **stacks);
void	p_chunk(t_stacks **stacks, t_list **chunks);

// swap.c
void	s(char stack, t_node **stk);
void	ss(t_stacks **stacks);

// move_utils.c
int     move_to_top(int index, int stack_size);
int     calc_score(t_node *node);
void	exec_rotates(t_stacks **stacks, char stack, int moves, bool chunk);
void	exec_rotates_together(t_stacks **stacks, t_node *best_node, bool chunk);
t_node	*node_last(t_node *stk);

void	sort(t_stacks **stacks);
#endif
