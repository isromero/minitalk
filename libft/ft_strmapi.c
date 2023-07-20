/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:20:25 by isromero          #+#    #+#             */
/*   Updated: 2023/07/20 15:20:25 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*m;

	i = 0;
	if (!s)
		return (0);
	m = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!m)
		return (0);
	while (s[i])
	{
		m[i] = (*f)(i, s[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
