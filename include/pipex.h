/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:10:38 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/31 13:44:50 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h> //para el pid_t
# include <sys/wait.h>
# include "../libft/libft.h"
# include <fcntl.h>  
# include <stdlib.h>

void	ft_exit(char *error_msg);
void	parent_process(char **av, int *p_fd, char **env);
void	child_process(char **av, int *p_fd, char **env);
void	execute(char *cmd, char **env);
char	*find_path(char **env, char *cmd);

#endif