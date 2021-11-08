/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_maps.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 16:37:31 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/08 16:00:52 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_up_down(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_left_right(char *data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	if (data[0] == '1' && data[i - 1] == '1')
		return (0);
	return (-1);
}
