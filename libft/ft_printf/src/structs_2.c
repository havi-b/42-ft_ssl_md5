/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 12:41:05 by havi              #+#    #+#             */
/*   Updated: 2019/08/05 05:32:06 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_size		*new_size(void)
{
	t_size	*size;

	size = NULL;
	if (!(size = (t_size *)malloc(sizeof(t_size))))
		return (NULL);
	size->width = 0;
	size->dot = 0;
	size->prcsn = 0;
	return (size);
}
