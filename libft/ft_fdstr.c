/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 05:07:28 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:40:27 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		*ft_fdstr(const int fd, uint64_t *len)
{
	unsigned char	buf[BUFF_SIZE + 1];
	unsigned char	*tmp;
	unsigned char	*ret;
	int				bytes;

	tmp = NULL;
	if (!(ret = (unsigned char *)malloc(sizeof(unsigned char))))
		return (NULL);
	*len = 0;
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		tmp = ret;
		ret = (unsigned char *)ft_strnjoin((char *)tmp, \
		(char *)buf, *len, bytes);
		free(tmp);
		*len += bytes;
	}
	return (ret);
}
