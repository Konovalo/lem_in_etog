/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:38:25 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 19:41:49 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "dll.h"
# define FALSE	0
# define TRUE	1

typedef enum				e_vertex_type
{
	START, MIDDLE, END
}							t_vertex_type;

typedef struct				s_vertex
{
	int						x;
	int						y;
	char					*name;
	t_vertex_type			type;
	int						bfs_level;
	int						visited;
	t_node					*i_edges;
	int						k;
}							t_vertex;

typedef struct				s_edge
{
	t_vertex				*vertex[2];
	int						visit_count;
}							t_edge;

typedef struct				s_graph
{
	t_node					*vertex;
	t_node					*edges;
}							t_graph;

typedef struct				s_time
{
	char					*s1;
	char					*s2;
	char					*s3;
	t_vertex_type			type;
}							t_time;

typedef struct				s_read
{
	t_time					time;
	int						len;
	int						n;
	int						argc;
	int						k;
	int						ant;
	t_vertex				*v;
	int						tim;
	int						fd;
	int						i;
	int						kol;
	t_node					*paths;
}							t_read;

typedef struct				s_ant_node
{
	int						ant;
	struct s_ant_node		*next;
}							t_ant_node;

typedef enum				e_bfs_work_mode
{
	FIRST_ALG_PASS, SECOND_ALG_PASS
}							t_bfs_work_mode;

typedef struct				s_temp
{
	t_vertex				*v1;
	t_vertex				*v2;
	t_vertex				*v3;
	t_vertex				*v4;
	int						kol;
}							t_temp;

typedef struct				s_int
{
	int						x;
	int						y;
}							t_int;

void						ants2(t_node *et1, t_node *e, t_ant_node **ann,\
			t_ant_node **an);
int							yslovee2(t_node *etog1, t_ant_node *an);
int							yslovee1(t_node *etog1, t_ant_node *an);
void						ants(t_read *read, t_node *etog, t_ant_node *ann);
void						bfs_add_to_lists(t_node **queue,\
			t_node **visited_vertexes, t_vertex *v);
void						bfs_clear_service(t_node	**list, t_node **queue);
void						return_trip(t_vertex *v, t_node **found_paths);
int							edge_get_opp_v1(t_edge *e, t_vertex *v);
void						bfs2(t_node **found_paths,\
			t_node **visited_vertexes, t_node **queue, t_vertex *sv);
void						bfs(t_graph *graph, t_node **found_paths);
void						return_trip2(t_node *curr_edge, t_vertex *v, \
			t_vertex *prev_vert, t_vertex **opp_vert);
void						iterate_edges(t_vertex *curr_vert, t_node **queue, \
			t_node **visited_vertexes);
void						free_visited_vertex(t_node **list);
void						zap_ant(t_ant_node **ant, int y);
void						init(t_read *read, int argc);
void						bfs_null(t_node **v_list);
void						sort_node(t_node **node);
int							read_map(char **a, t_read *re, t_graph *graph);
int							cut_line(char *line, t_read *read,\
		t_node **v, t_node **e);
int							cut_line2(char *l, t_read *read,\
		t_node **v_l, t_node **e_list);
int							cut_line7(char *l, t_read *read,\
		t_node **v_l, t_node **e_list);
int							cut_line4(char *l, t_read **read);
int							cut_line5(char *l, t_read **read);
int							check_cut(t_vertex **ver, t_time *time,
		t_read *read, t_node **v_list);
int							cut_line3(char *line, t_read *re, t_node **v_list);
t_node						*edge_list_add_all(t_node **node, t_edge *e);
t_node						*edge_list_add_first(t_node **node, t_edge *e);
t_ant_node					*dll_add_last_an(t_ant_node **list, int k);
t_node						*vertex_list_add_last(t_node **list, t_vertex *v);
t_ant_node					*vertex_list_add_last_an(t_ant_node **list, int a);
t_edge						*edge_create(t_vertex *v1, t_vertex *v2);
void						edge_reverse(t_edge *e);
t_vertex					*edge_get_opp_v(t_edge *e, t_vertex *v);
void						free_vertex(t_vertex *vertex);
void						free_mem(t_node *v_list, t_node *e_list);
void						free_mem_an(t_ant_node *an);
void						free_paths(t_node *paths);
void						fr_mass(t_node **mass, int *ogi, int kol);
int							poisk3(t_node *vrem2, t_node *vrem1);
void						poisk4(t_node *vrem2, t_node *vrem1);
void						poisk2(t_node **one, t_node *vrem1);
void						poisk(t_node **paths);
int							zap_print_ant(t_node **mass, int *ogi,\
		t_ant_node *anti, t_read *read);
void						print_ant(t_read *read,\
		t_node *paths, t_ant_node *an);
t_vertex					*vertex_list_get_first(t_node **list);
t_node						*vertex_list_push(t_node **stack, t_vertex *v);
t_vertex					*vertex_list_pop(t_node **stack);
t_node						*ver_list_add(t_node **list, t_vertex *v);
t_ant_node					*dll_new_node_an(int k);
int							vertex_cmp_forked(t_vertex *v1, t_vertex *v2);
int							vertex_cmp2(t_vertex *v1, t_vertex *v2);
int							vertex_cmp(t_vertex *v1, t_vertex *v2);
t_vertex					*vertex_create(t_int t,\
		char *name, t_vertex_type type, int k);
void						zap_edge8(t_node **e_list,
		t_vertex **v2, t_vertex **v4);
void						zap_edge7(t_node **e_list,\
		t_vertex **v2, t_vertex **v3);
void						zap_edge6(t_node **e_list,\
		t_vertex **v1, t_vertex **v4);
void						zap_edge5(t_node **e_list,\
		t_vertex **v2, t_vertex **v3, t_vertex **v4);
void						zap_edge4(t_node **e_list,\
		t_vertex **v1, t_vertex **v3, t_vertex **v4);
void						zap_edge3(t_node **e_list,\
		t_vertex **v1, t_vertex **v2, t_vertex **v3);
void						zap_edge2(t_node **e_list,\
		t_vertex **v1, t_vertex **v2, t_vertex **v4);
int							zap_edge_ver(t_node **v_list,\
		t_time *time, t_temp *temp);
void						ini_temp(t_temp *temp);
int							zap_edge(t_node **v_list,\
		t_node **e_list, t_time *time);
t_vertex_type				zap_type(t_read **read);
int							v_n(char *str);
int							check(t_node **new_node, t_time *time);
int							zap_vertex(t_vertex **ver,\
		t_time *time, t_read *read, t_node **v_list);

#endif
