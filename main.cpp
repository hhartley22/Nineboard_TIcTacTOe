//
// Created by Hayden on 24/8/20.
//
/*********** Declaration *******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
*******************************/
#include "NBGame.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "MonteCarloPlayer.h"

#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(0));

  Player* player1 = new HumanPlayer();
  Player* player2 = new MonteCarloPlayer();

  NBGame gameController(player1, player2);
  gameController.play();

  return 0;
}
