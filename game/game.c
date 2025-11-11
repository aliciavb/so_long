#include "so_long.h"

int	expose_hook(t_game *game)
{
	render_map(game);
	return (0);
}

void	run_game(t_game *game)
{
	mlx_loop(game->mlx);
}
