/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_token_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:46:10 by bthomas           #+#    #+#             */
/*   Updated: 2024/07/25 10:53:46 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_tokentype	check_prev_tk(t_data *data)
{
	t_token	*last;

	last = lex_get_last_token(data);
	if (!last)
		return (TK_INVALID);
	return (last->type);
}

t_token	*get_token(t_data *data, char *lexstr, char *path, t_tokentype type)
{
	t_token	*token;

	if (type == TK_PIPE)
	{
		if (!data->token)
			return (free(lexstr), NULL);
		token = data->token;
		while (token->next)
			token = token->next;
		if (token->type == TK_PIPE || token->type == TK_REDIR)
			return (free(lexstr), NULL);
	}
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		write(STDERR_FILENO, "Error: bad malloc\n", 19);
		exit(clean_exit(data, 1));
	}
	token->lexstr = lexstr;
	token->path = path;
	token->type = type;
	return (token);
}

t_token	*lex_get_last_token(t_data *data)
{
	t_token	*curr_tk;

	if (!data->token)
		return (NULL);
	curr_tk = data->token;
	while (curr_tk && curr_tk->next)
		curr_tk = curr_tk->next;
	return (curr_tk);
}

void	lex_add_token(t_data *data, t_token *token)
{
	t_token	*last;

	if (!token)
		return ;
	if (!data->token)
	{
		data->token = token;
		return ;
	}
	last = lex_get_last_token(data);
	if (last)
	{
		last->next = token;
		token->prev = last;
	}
	else
		data->token = token;
}

void	print_token(t_token *token)
{
	if (!token)
		return ;
	ft_printf("\nToken type: %d\n", token->type);
	ft_printf("Token lexstr: [%s]\n", token->lexstr);
	ft_printf("Token path: %s\n", token->path);
	if (token->heredoc)
		ft_printf("Heredoc path: %s\n", token->heredoc->path);
}
