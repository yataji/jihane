/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:35:11 by yataji            #+#    #+#             */
/*   Updated: 2021/03/29 14:49:33 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	*initobj(void)
{
	t_obj		*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (!(new))
		return (NULL);
	new->type = 0;
	new->angle = 0;
	new->radius = 0;
	new->v = (t_vect){0, 0, 0};
	new->normal = (t_vect){0, 0, 0};
	new->color = (t_color){0, 0, 0};
	new->center = (t_point){0, 0, 0};
	new->trs = (t_point){0, 0, 0};
	new->rot = (t_rot){0, 0, 0};
	new->angle = 0;
	new->next = NULL;
	return (new);
}

t_lights	*initlights(void)
{
	t_lights	*new;

	new = (t_lights *)malloc(sizeof(t_lights));
	if (!(new))
		return (NULL);
	new->intensity = 0;
	new->color = (t_color){0, 0, 0};
	new->pos = (t_point){0, 0, 0};
	new->next = NULL;
	return (new);
}

t_cam	*initcam(void)
{
	t_cam	*new;

	new = (t_cam *)malloc(sizeof(t_cam));
	if (!(new))
		return (NULL);
	new->lokat = (t_point){0, 0, 0};
	new->lokfrm = (t_point){0, 0, 0};
	new->v = (t_point){0, 1, 0};
	new->u = (t_point){0, 0, 0};
	new->w = (t_point){0, 0, 0};
	new->fov = 0;
	new->plnw = 0;
	new->plnh = 0;
	new->next = NULL;
	return (new);
}