/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:52:36 by bento             #+#    #+#             */
/*   Updated: 2024/07/19 10:25:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*get_token(t_data *data, char *lexstr, char *path, t_tokentype type)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
	{
		write(2, "Error: bad malloc\n", 19);
		exit(clean_exit(data, 1));
	}
	token->lexstr = lexstr;
	token->path = path;
	token->type = type;
	token->next = NULL;
	token->prev = NULL;
	token->heredoc = NULL;
	return (token);
}

char	*get_substr(char *input, size_t start_idx)
{
	char	*substr;
	size_t	i;

	i = start_idx;
	while (input[i] && !is_space(input[i]) && !in(input[i], "()|<>=\"\'"))
		i++;
	substr = ft_substr(input, start_idx, i - start_idx);
	if (!substr)
		return (NULL);
	return (substr);
}

bool	var_in_str(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i] == '$' && s[i + 1] && !in(s[i + 1], "$=()\"\' \t\n\v\f\r"))
			return (true);
		i++;
	}
	return (false);
}
