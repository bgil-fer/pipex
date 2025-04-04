/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:10:25 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/04/02 14:28:37 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env, char *cmd)
{
	char	**paths;
	char	*path;
	char	*segmented_path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		segmented_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(segmented_path, cmd);
		free(segmented_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_mem(paths);
	return (0);
}

void	execute(char *cmd, char **env)
{
	char	**command;
	char	*path;
	int		i;

	command = ft_split(cmd, ' ');
	path = find_path(env, command[0]);
	i = 0;
	if (!path)
	{
		while (command[i])
		{
			free(command[i]);
			i++;
		}
		free(command);
		ft_exit("\033[33mPath not found\n"); //colores?
	}
	if (execve(path, command, env) == -1)
		ft_exit("Command not found\n");
	free_mem(command);
}

void	child_process(char **av, int *p_fd, char **env)
{
	int	infd;

	infd = open(av[1], O_RDONLY);
	if (infd == -1)
		ft_exit("Error opening infile\n");
	dup2(infd, STDIN_FILENO); // sustituyo el stdin por mi fd
	dup2(p_fd[1], STDOUT_FILENO); // sustituyo la salida de este proceso por p_fd[1]
	close(p_fd[0]);
	execute(av[2], env);
}

void	parent_process(char **av, int *p_fd, char **env)
{
	int	outfd;

	outfd = open(av[4], O_WRONLY);
	if (outfd == -1)
		ft_exit("Error opening outfile\n");
	dup2(outfd, STDOUT_FILENO); // sustituyo el stdout por el segundo fd
	dup2(p_fd[0], STDIN_FILENO); // sustituyo la entrada del proceso del termianl (stdin) a p_fd[0]
	close(p_fd[1]);
	execute(av[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_exit("Invalid number of arguments\n"); //crear función
	if (pipe(p_fd) == -1)
		ft_exit("Pipe failed\n");
	pid = fork();
	if (pid == -1)
		ft_exit("Pid failed\n");
	if (!pid)
		child_process(argv, p_fd, env);
	waitpid(pid, NULL, 0);
	parent_process(argv, p_fd, env);
	return (0);
}
