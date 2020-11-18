/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:46:05 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/15 13:46:06 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSES_H
# define PROCESSES_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <ncurses.h>
# define TYPE_INDEX 1
# define TYPE_DIRECT 2
# define TYPE_INDIRECT 3
# define VM_SIZE (1024 * 4)
# define CURSE_ON 1
# define IDX_MOD (VM_SIZE / 8)
# define CYCLE_TO_DIE 10000 + 1399
# define CYCLE_DELTA 50
# define NBR_LIVE 21
# define MAX_CHECKS 10
# define NEW 100
# define SLEEP 500
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0x00ea83f3

unsigned char	g_vm[VM_SIZE];
char			g_vm_player[VM_SIZE];
char			g_vm_new[VM_SIZE];
char			g_vm_track[VM_SIZE];

typedef struct	s_process
{
	int					c;
	int					carry;
	int					reg[16];
	int					addr;
	int					params[3];
	char				type_p[3];
	int					cycles_to_next;
	char				player;
	int					age;
	char				*filename;
	char				ready_for_next;
	int					nb_lived_display__;
	struct s_process	*next;
}				t_process;

typedef struct		s_header
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					t_header;

int				g_lives;
t_process		*g_processes;
int				g_total_processes;
int				g_total_cycles;

t_process		*new_process(int addr, char *filename, int jr, int a);
void			param_handle(t_process *proc);
void			show_vm(void);
void			show_process_list(void);
void			color_vm(void);
void			add_cooldown(t_process *proc);
void			sub_cooldown(t_process *proc);
void			timed_task(t_process *proc);
int				parsing(int argc, char **argv);
int				relative_addr(t_process *proc, int i);
int				relative_addr_long(t_process *proc, int i);
/*
** // =================== tasks ======================//
*/
void			zero(t_process *proc);
void			live(t_process *proc);
void			load_direct(t_process *proc);
void			store_direct(t_process *proc);
void			cw_add(t_process *proc);
void			cw_sub(t_process *proc);
void			cw_and(t_process *proc);
void			cw_or(t_process *proc);
void			cw_xor(t_process *proc);
void			zjmp(t_process *proc);
void			load_indirect(t_process *proc);
void			store_indirect(t_process *proc);
void			cw_fork(t_process *proc);
void			long_load(t_process *proc);
void			long_load_indirect(t_process *proc);
void			long_fork(t_process *proc);
void			aff(t_process *proc);
/*
** //=================================================//
*/
int				highest_player(void);
void			curse_display(int cycles_to_die, int x, int cycles);
void			new_quadret(int dst, int caller);
void			cadre_a_b(int ax, int ay, int bx, int by);
/*
** //========== anciennes static display.c ===========//
*/
void			horizontal(int x, int y1, int y2, int c);
void			live_display(int final);
void			colors(void);
void			player_cadre(void);
/*
** //============ anciennes static main.c ============//
*/
void			delete_one_proc(t_process *p, t_process *t, t_process *b);
void			check_survive(int cycle_to_die);
int				check_end(int cycles_to_die);
void			check_delta(int *cycle_to_die, int *checks);
/*
** //======== anciennes static ocp_handling.c ========//
*/
int				extra_ph_1(int tn, t_process *proc);
void			extra_ph_2(int ocp, t_process *p, int *param_counter, int d2_4);
void			extra_ph_3(t_process *proc, int *tn, int *param_counter);
void			task_tab(int index, t_process *proc);
/*
** //================== parsing.c ====================//
*/
int				next_nb();
int				fdp(int sp, int total_champ);
void			ntm(int sp, int total_champ, char *argvi, int *nb_champ);
/*
** //================== parsing2.c ====================//
*/
int read_header(int fd, t_process *proc);

/*
** //=================== victory.c ===================//
*/
void			end_of_the_game();
void			interpretation(int *pc, int i, t_process *p, int d2_4);
int				blindage_registres(t_process *proc);
void			clear_square(int ax, int ay, int bx, int by);

/*
** //=================== victory2.c ===================//
*/
int				draw(void);

#endif
