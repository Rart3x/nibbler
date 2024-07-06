#include "../includes/Game.hpp"

Game::Game()
{
	return ;
}

Game::~Game()
{

}

Game::Game(Game const &other)
{
	(void)other;
}

Game& Game::operator=(Game const &other)
{
	(void)other;
	return (*this);
}
