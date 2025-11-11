#include "so_long.h"

void	render_tile(t_game *game, int x, int y, char tile)
{
	void	*img;

	if (tile == '1')
		img = game->img_wall;
	else if (tile == '0')
		img = game->img_floor;
	else if (tile == 'P')
	{
		if (game->player_direction == DIRECTION_RIGHT)
			img = game->img_player_right;
		else
			img = game->img_player_left;
	}
	else if (tile == 'C')
		img = game->img_collectible;
	else if (tile == 'E')
		img = game->img_exit;
	else if (tile == 'X')
		img = game->img_enemy_frames[game->animation_frame];
	else
		img = game->img_floor;
	mlx_put_image_to_window(game->mlx, game->window,
		img, x * TILE_SIZE, (y * TILE_SIZE) + UI_HEIGHT);
}

static void	render_single_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img_floor,
		x * TILE_SIZE, (y * TILE_SIZE) + UI_HEIGHT);
	if (x == game->player_x && y == game->player_y)
		render_tile(game, x, y, 'P');
	else
	{
		if (game->map[y][x] != '0')
			render_tile(game, x, y, game->map[y][x]);
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	render_ui(game);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_single_tile(game, x, y);
			x++;
		}
		y++;
	}
}
