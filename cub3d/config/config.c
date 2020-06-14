/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:39:55 by youlee            #+#    #+#             */
/*   Updated: 2020/06/14 21:47:39 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		init_config(t_config *config)
{
	int		i;

	i = 0;
	config->request_width = 848;
	config->request_height = 480;
	while (i < TEXTURES)
		config->tex_p[i++] = NULL;
	config->c[TEX_NORTH] = 0XFFFFFF;
	config->c[TEX_SOUTH] = 0XCCCCCC;
	config->c[TEX_WEST] = 0XFF44FF;
	config->c[TEX_EAST] = 0X44FF44;
	config->c[TEX_SKY] = 0X33C6E3;
	config->c[TEX_FLOOR] = 0XA0764C;
	config->map = NULL;
	config->rows = NULL;
	config->columns = NULL;
	config->save_arg = NULL;
	config->rotate_speed = .11;
	config->move_speed = .11;
	config->fov = .66;
	i = 0;
	while (i < C_LAST)
		config->set[i++] = 0;
}

int			clear_config(t_config *config)
{
	int		i;
	
	i = 0;
	while (i < TEXTURES)
	{
		if (config->tex_p[i])
			free(config->tex_p[i];
		config->tex_p[i] = NULL;
		i++;
	}
	if (config->map)
		free(config->map);
	config->map = NULL;
	return (0);
}

int			parse_config(t_config *config, char *path)
{
	int		fd;
	char	*line;
	int		ret;
	t_str	*buff;

	if (!ft_endwith(conf_path, ".cub"))
		return (0);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	buff = NULL;
	ret = 1;
	while (get_next_line(fd, &line))
	{
		ret = (ret && parse_line(config, line, &buff));
		free(line);
	}
	if (ret && ft_strlen(line) > 0)
		ret = 
}