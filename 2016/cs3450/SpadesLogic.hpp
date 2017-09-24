#ifndef SPADESLOGIC_HPP
#define SPADESLOGIC_HPP

#include "source/PlayerAPI/Game.hpp"
#include <vector>
#include <iostream>

class Spades : public Game
{
public:
	void setDeck(); // don't test
	void printPlayerHands(); // useless
	void start(); // useless
	void getBids(); // useless
	void beginRound(int); // useless
	void startTrick(); // useless
	bool validMove(std::vector<Card>, int, Suit&, int); // gonna be the worst
	int getTrickWinner(std::vector<Card>, int); // tested
	int getNextPlayer(int); // tested 
	void score(); // work on
	void recordMove(std::vector<Card>); // useless
	Spades(std::vector<std::shared_ptr<Player>>); // starts the loops... so not sure how to test... but it needs to be... probably
	~Spades() {}
private:
	int starter;
	bool spadesBroken;
};
#endif
