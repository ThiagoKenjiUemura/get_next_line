/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:25:32 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/08/08 17:15:53 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int vopen;
	
	vopen = open(fd, O_RDONLY);
	if(vopen == -1)
		return (-1);
}