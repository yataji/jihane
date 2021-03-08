/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:20:08 by yataji            #+#    #+#             */
/*   Updated: 2021/03/08 16:24:38 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int lights(t_lights *lights, char *str, int fd)
{
	char **value;
	int l;

	l = 0;
	while (l < 3)
	{
		if (get_next_line(fd, &str) < 0)
			return (-1);
		l++;
		if (checkval(str, "\tintensity: ", 12) > 0 || checkval(str, "\tintensity:\t", 12) > 0)
		{
			value = ft_strsplit(str, ':');
			free(str);
			if (ft_strlend(value) != 2)
				return (-1);
			lights->intensity = ft_atoi(value[1]);
		}
		else if (checkval(str, "\tcolor: ", 8) > 0 || checkval(str, "\tcolor:\t", 8) > 0)
		{
			value = ft_strsplit(str, ':');
			free(str);
			if (ft_strlend(value) != 4)
				return (-1);
			lights->color.x = ft_atoi(value[1]);
			lights->color.y = ft_atoi(value[2]);
			lights->color.z = ft_atoi(value[3]);
		}
		else if (checkval(str, "\tpos: ", 6) > 0 || checkval(str, "\tpos:\t", 6) > 0)
		{
			value = ft_strsplit(str, ':');
			free(str);
			if (ft_strlend(value) != 4)
				return (-1);
			lights->pos.x = ft_atoi(value[1]);
			lights->pos.y = ft_atoi(value[2]);
			lights->pos.z = ft_atoi(value[3]);
		}
		else
			return (-1);
	}
	return (1);
}