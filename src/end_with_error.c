/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_with_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:39:10 by jconcent          #+#    #+#             */
/*   Updated: 2020/11/11 13:59:48 by Gimad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	end_with_error(t_lem *lem)
{
	if (lem)
		free_lem(lem);
	ft_putstr_fd("ERROR\n", 2);
	exit(0);
}