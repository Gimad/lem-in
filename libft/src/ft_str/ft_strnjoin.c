/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:46:03 by jconcent          #+#    #+#             */
/*   Updated: 2020/11/02 14:46:33 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*str;

	tmp = NULL;
	str = NULL;
	if (s1 && s2)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1 + 1))))
			return (NULL);
		tmp = ft_strcpy(tmp, s1);
		tmp[ft_strlen(s1)] = '\n';
		tmp[ft_strlen(s1) + 1] = '\0';
		str = ft_strjoin(tmp, s2);
		free(tmp);
		return (str);
	}
	return (NULL);
}
