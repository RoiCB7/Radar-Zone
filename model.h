#ifndef MODEL_H
#define MODEL_H

typedef struct _PlayerBot
{
    unsigned int x;
    unsigned int y;   /*position coordinates*/
    int delta_x; 
    int delta_y;

}PlayerBot;

typedef struct _EnemyBot
{
    unsigned int x, y;   /*position coordinates*/
}EnemyBot;

void move_player(PlayerBot *player);

#endif