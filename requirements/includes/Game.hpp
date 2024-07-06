#pragma once

#include <iostream>


class Game
{
	public:
		Game();
		~Game();
		Game(Game const &other);
		Game &operator=(Game const &other);
};
