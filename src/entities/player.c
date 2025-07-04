
#include "so_long.h"

t_entity *new_player(t_game *game)
{
	t_entity *player;

	player = malloc(sizeof(t_entity));
	player->position = malloc(sizeof(t_position));
	player->position->x = 32;
	player->position->y = 64;
	player->image = malloc(sizeof(t_image));
	player->animation = malloc(sizeof(t_animation));
	load_idler_image(game, player);
	load_idlel_image(game, player);
	load_rright_image(game, player);
	load_rleft_image(game,player);
	load_jumpr_image(game,player);
	load_jumpl_image(game,player);
	load_landingr_image(game,player);
	load_landingl_image(game,player);

	player->gravity = malloc(sizeof(t_gravity));
	player->gravity->is_jumping = 0;
	player->gravity->velocity = 0.0f;
	player->velocity = malloc(sizeof(t_velocity));
	player->velocity->x = 0;
	player->velocity->y = 0;
	player->collision = malloc(sizeof(t_collision));
	player->collision->width = 32;
	player->collision->height = 32;
	player->keyboard = malloc(sizeof(t_keyboard));
	game->entities[game->count_entities] = *player;
	game->count_entities++;
	return (player);
}
