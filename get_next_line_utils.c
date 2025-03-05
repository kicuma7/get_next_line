/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:46:09 by jquicuma          #+#    #+#             */
/*   Updated: 2025/03/05 16:02:03 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	str_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*str_join_and_free(char *freeded_str, const char *str2)
{
	size_t	i;
	size_t	k;
	char	*str_joined;

	if (!freeded_str || !str2)
		return (NULL);
	i = 0;
	k = 0;
	str_joined = NULL;
	str_joined = malloc(str_len(freeded_str) + str_len(str2) + 1);
	if (!str_joined)
		return (NULL);
	while (freeded_str[i])
		str_joined[k++] = freeded_str[i++];
	i = 0;
	while (str2[i])
		str_joined[k++] = str2[i++];
	str_joined[k] = '\0';
	free(freeded_str);
	return (str_joined);
}

char	*str_chr(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)searchedChar)
			return ((char *)(string + i));
		i++;
	}
	if (string[i] == (char)searchedChar)
		return ((char *)(string + i));
	return (NULL);
}

char	*str_dup(const char *s1)
{
	size_t		i;
	char		*str;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
