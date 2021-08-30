#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <thread>
#include "game.h"
#include "level.h"
#include "snake.h"
#include "ai.h"

using namespace std;

Game::Game(string mode, Snake* snake, Level* level, AI* ai)
{
	this->user_input = "";
	this->frame_count = 0;
	this->state = RUNNING;
	this->mode = mode;

	this->snake = snake;
	this->level = level;
	this->ai = ai;
}

void Game::get_input()
{
	switch (this->state) {
	case WAITING_USER:
		cin >> ws >> this->user_input;
		break;
	default:
		break;
	}
}

void Game::update()
{
	switch (this->state) {
	case RUNNING: {
		/* if (this->frame_count > 0 && this->frame_count % 20 == 0) {
			this->state = WAITING_USER;
			break;
		} */

		if (this->level->snake_died()) {
			this->snake->respawn();
			break;
		}

		if (this->snake->get_lifes() <= 0) {
			this->state = GAME_OVER;
			break;
		}

		if (this->snake->get_food_eaten() >= this->level->get_food_count()) {
			this->state = GAME_OVER;
			break;
		}

		if (!this->ai->has_solution())
			this->ai->find_solution();

		if (!this->ai->has_solution()) {
			this->ai->random_direction();
			this->snake->move(this->ai->next_move(), this->mode, false);
			break;
		}

		Snake::Direction next = this->ai->next_move();

		if (this->ai->has_solution()) {
			this->snake->move(next, this->mode, false);
		} else {
			this->snake->move(next, this->mode, true);
			this->level->spawn_food();
		}
		break; }
	case WAITING_USER:
		if (this->user_input == "n" || this->user_input == "N")
			this->state = GAME_OVER;
		else
			this->state = RUNNING;
		break;
	default:
		break;
	}
}

void wait(int ms)
{
	this_thread::sleep_for(chrono::milliseconds(ms));
}

void clear_screen()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

void Game::render()
{
	clear_screen();
	switch (this->state) {
	case RUNNING:
		cout << this->level->generate_map() << endl;
		break;
	case WAITING_USER:
		cout << "CONTINUAR JOGANDO? [S/N]" << endl;
		break;
	case GAME_OVER:
		cout << "FIM DE JOGO!" << endl;
		break;
	}
	this->frame_count++;
}

void Game::game_over()
{
	wait(750);
}

void Game::loop()
{
	render();
	wait(1000);
	while (this->state != GAME_OVER) {
		get_input();
		update();
		render();
		wait(350);
	}
	game_over();
}
