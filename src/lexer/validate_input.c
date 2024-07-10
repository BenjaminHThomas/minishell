/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:48:14 by bthomas           #+#    #+#             */
/*   Updated: 2024/07/10 14:11:50 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	unclosed_quotes(char *input, size_t len)
{
	size_t			i;
	unsigned char	quote;

	i = 0;
	while (i < len)
	{
		if (input[i] == "\"" || input[i] == "\'")
		{
			quote = input[i];
			i++;
			while (i < len && input[i] != quote)
				i++;
			if (i == len)
				return (true);
		}
		i++;
	}
	return (false);
}

/* special chars are allowed within quotes, e.g., echo "hello;" */
static bool	special_chars(char *input, size_t len)
{
	size_t	i;
	char	quote;

	i = 0;
	while (i < len)
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			quote = input[i];
			while (i < len && input[i] != quote)
				i++;
		}
		if (input[i] == "\\" || input[i] == ";" || !ft_isascii(input[i]))
			return (true);
		i++;
	}
	return (false);
}

/* Not interpret unclosed quotes or special characters which are not required 
by the subject such as \ (backslash) or ; (semicolon) */
bool	valid_input(char *input)
{
	size_t	len;

	len = ft_strlen(input);
	return (unclosed_quotes(input, len) || special_chars(input, len)
			|| non_n_flag(input) || incorrect_cd(input) );
}
