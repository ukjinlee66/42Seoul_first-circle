/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:03:22 by youlee            #+#    #+#             */
/*   Updated: 2020/06/12 19:03:26 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		exit_game(t_game *game, int code)
{

}

void	init_game(t_game *game, int save)
{
	int		i;

	set_pos(&game->move, 0, 0);
	set_pos(&game->x_move, 0, 0);
	set_pos(&game->rotate, 0, 0);
	game
