/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 02:04:33 by yataji            #+#    #+#             */
/*   Updated: 2019/04/07 03:12:39 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = 0;
	while (str[a] == '\n' || str[a] == ' ' || str[a] == '\t' || str[a] == '\r'
			|| str[a] == '\f' || str[a] == '\v')
		a++;
	if (str[a] == '-')
		b = 1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while (str[a] >= '0' && str[a] <= '9' && str[a] != '\0')
	{
		c = c * 10 + (str[a] - 48);
		a++;
	}
	if (b == 1)
		return (-c);
	else
		return (c);
}
