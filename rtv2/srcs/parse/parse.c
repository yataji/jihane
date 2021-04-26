/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:48:30 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/09 15:04:12 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	parse_objs(t_rtv1 *rt, char *str)
{
	if (ft_strcmp(str, "sphere:") == 0)
	{
		if (ft_sphere(rt, str) == -1)
			return (-1);
	}
	else if (ft_strcmp(str, "cylinder:") == 0)
	{
		if (ft_cylinder(rt, str) == -1)
			return (-1);
	}
	else if (ft_strcmp(str, "cone:") == 0)
	{
		if (ft_cone(rt, str) == -1)
			return (-1);
	}
	else if (ft_strcmp(str, "plane:") == 0)
	{
		if (ft_plane(rt, str) == -1)
			return (-1);
	}
	else
		return (-1);
	return (1);
}

int	parse(t_rtv1 *rt)
{
	int			c;

	c = 0;
	while (++c && get_next_line(rt->fd, &rt->str) > 0)
	{
		if (ft_strcmp(rt->str, "camera:") == 0)
		{
			if (ft_cam(rt, rt->str) == -1)
				return (-1);
		}
		else if (ft_strcmp(rt->str, "lights:") == 0)
		{
			if (ft_lights(rt, rt->str) == -1)
				return (-1);
		}
		else if (parse_objs(rt, rt->str) == -1)
		{
			free(rt->str);
			return (-1);
		}
		free(rt->str);
	}
	if (c == 1)
		return (-1);
	return (1);
}