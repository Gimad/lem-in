/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:34:43 by jconcent          #+#    #+#             */
/*   Updated: 2020/11/11 14:02:36 by Gimad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_lem(t_lem *lem)
{
	if (lem)
		if (lem->map)
			free_map(lem->map);
	if (lem->begin_room)
		free_room_list(&lem->begin_room);
	if (lem->rooms)
		free(lem->rooms);
	if (lem->solutions)
		free_solutions(lem->solutions);
	free(lem);
}

/*
**	Two main parts of program:
**	parsing - filling (lem) structure
**	and finding_paths, that running the algorithm
*/

int		main(void)
{
	t_lem	*lem;

	if (!(lem = (t_lem*)malloc(sizeof(t_lem))))
		end_with_error(lem);
	ft_bzero(lem, sizeof(lem));
	if (!parsing(lem))
		end_with_error(lem);
	finding_paths(lem);
	free_lem(lem);
	return (0);
}
