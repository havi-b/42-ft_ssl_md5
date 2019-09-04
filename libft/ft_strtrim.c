/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 01:15:01 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/19 20:23:42 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	i;
	char	*t;

	if (!s)
		return (NULL);
	while (*s && ft_iswspace(*s))
		s++;
	i = ft_strlen(s) - 1;
	while (*s && ft_iswspace(s[i]))
		i--;
	if (!(t = ft_strnew(i + 1)))
		return (NULL);
	ft_strncpy(t, s, i + 1);
	return (t);
}
