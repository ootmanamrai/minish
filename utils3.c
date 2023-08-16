/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:50:44 by otamrani          #+#    #+#             */
/*   Updated: 2023/08/17 00:34:51 by otamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int noptions(t_list *lst)
{
    t_list *tmp;
    int i;
    i = 0;
    tmp = lst;
    while(tmp)
    {
        if(tmp->token == 0)
            i++;
        tmp = tmp->next;
    }
    return (i);
}
char	*stock(char *av)
{
	char	*line;
	char	*tmp;
    char *all;

    all = NULL;
    printf("av = %s\n", av);
	line = readline("here_doc: ");
	while (line)
	{
		if (ft_strcmp(line, av) == 0)
        {
			break ;
        }
		tmp = ft_strjoin(line, "\n");
        all = ft_strjoin(all, tmp);
		line = readline("here_doc: ");
		free(tmp);
	}
	free(line);
    return (all);
}
int count_x(t_list *lst, int j)
{
    t_list *tmp;
    int i;
    i = 0;
    tmp = lst;
    while(tmp)
    {
        if(tmp->token == j)
            i++;
        tmp = tmp->next;
    }
    return (i);
}
char *get_cont(t_list **lst, int n)
{
    while((*lst))
    {
        if((*lst)->token == n)
        {
            (*lst) = (*lst)->next;
            return ((*lst)->content);
        }
        (*lst) = (*lst)->next;
    }
    return (NULL);
}
int	open_here(t_list *lst, int n)
{
	char	*data;
	char	*tmp;
    int fd;
    tmp = ft_strjoin("/tmp/","here");
    printf("n = %d\n", n);
    while(n > 0)
    {
    data = stock(get_cont(&lst, 5));
    n--;
    }
    if(n == 0 && count_x(lst, 2) == 0)
    {
       fd = open(tmp, O_RDWR | O_CREAT | O_TRUNC, 0644);
        if(fd < 0)
            return (perror("open"),0);
        ft_putstr_fd(data, fd);
    }
    else if(count_x(lst, 2))
    {
        n = count_x(lst, 2);
        while(n > 0 && get_cont(&lst, 2) && n--);
        fd = open(lst->content, O_RDONLY);
        if(fd < 0)
            return (perror("open"),0);
    }
    return (fd);
}
int    convert_lst(t_list *lst)
{
    t_data *data;
    // t_list *tmp;
    // int i;
    // i= 0;
    data = malloc(sizeof(t_data) * count_x(lst, 1) + 1);
    if(!data)
        return (0);
    open_here(lst, count_x(lst, 5));
        // if(lst->token == 2)
        // {
        //     in = open(lst->next->content, O_RDONLY);
        //     rest lst 0 == data->cmd
                // out = > = outfile | = 1 of pipe or null stdin
                // 
        // }
        // if(lst->token == 3)
        // out = open(lst->next->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        //
        // if(lst->token == 4)
        // 
        return (1);
}
// 