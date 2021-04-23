/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:19:19 by yataji            #+#    #+#             */
/*   Updated: 2021/04/22 20:33:58 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

int	ft_cube(t_rt *rt, char *str)
{
	rt->tmpo = initobj();
	rt->tmpo->type = CUBE;
	if (stockobj(rt->tmpo, rt->tmpo->type, str, rt->fd) == -1)
		return (-1);
	rt->tmpo->center = plus(rt->tmpo->center, rt->tmpo->trs);
	rt->tmpo->next = rt->obj;
	rt->obj = rt->tmpo;
	return (0);
}