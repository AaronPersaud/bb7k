#include <iostream>
#include <string>
#include "auction.h"
#include "player.h"
#include "board.h"

using namespace std;

Auction::Auction(): price(0) {}

void Auction::auction(Player* players[], int size, Square* square) {

	char player;  // token of a player who bidded hightest price.
	int highestPrice = 0;  // update the hightest price bidded in each round.
	int biddingPrice = 0;  // the price bidded in the current round.
	int numBidding = size;  // the number of players participating the current round of bidding.
	int newNum = 0;  // the number of players going to the next round.
	int priceIndex = 0; // update when highest price is bidded. This is used when we track all prices
						// bidded in the current round when print out the bidding result.
	int priceBidded[numBidding];  // record all bidding price from all players on the current round.
	Player* copy[size];  // copy players array to make change in array the array.
	Player* newCopy[size];  // keep players remaining in the next round.

	for (int i = 0; i < size; i++) {
		copy[i] = players[i];  // copy players.
	}

	// bidding continues until only one player is left. 
	while (1) {

		for (int i = 0; i < numBidding; i++) {
			cout << copy[i]->getToken() << ", ";
			cout << "what's your bidding price?" << endl;
			cout << endl;
			cout << "Please enter 0 if you want to withraw your bidding." << endl;
			cout << endl;
			cout << "Please notice that players who don't bid price higher than previous bidding price will be withdrew :) !" << endl;
			cout << ":";

			cin >> biddingPrice; // price the players offering in the current bidding.

			cout << endl;

			//priceBidded[i] = biddingPrice;  // record the prices in this round. 

			if (biddingPrice > highestPrice) {  // player want to continue bidding in the next round.
				newCopy[newNum] = copy[i];  // pass this player to the next round. 
				newNum++;  
			}

			// keep tracking the hightest price and player bidded this price. 
			if (biddingPrice > highestPrice) {
				priceBidded[priceIndex] = biddingPrice;  // record the prices in this round.
				priceIndex++;
				player = players[i]->getToken();  // player bidding the highest price
				highestPrice = biddingPrice;  // the highest price.

				cout << copy[i]->getToken() << " bidded " << biddingPrice << "!" << endl;
				cout << endl;
				cout << "Please bid higher price than " << biddingPrice << "!" << endl;
				cout << endl;	
			} else {
				cout << copy[i]->getToken() << " withdrew!" << endl;
				cout << endl;
			}

		} // for


		// update players who go to the next round. 
		for (int i = 0; i < newNum; i++) {
			copy[i] = newCopy[i];
		}

		numBidding = newNum;  // update the number of players who go to the next round. 
		newNum = 0;
		priceIndex = 0;		  

		// print out the result of this round.
		if (numBidding != 0) {

			cout << "The result of the bidding in this round:" << endl;
			cout << endl;
			for (int i = 0; i < numBidding; i++) {

				cout << copy[i]->getToken() << ": " << priceBidded[i] << endl;
			}

		}
		

		// end bidding if only one player remains. 
		if (numBidding == 1) {
			cout << endl;
			cout << copy[0]->getToken() << " is a winner!" << endl;
			cout << square->getBuildingName() << " is sold in $" << highestPrice << "!" << endl;
			break;
		} else if (numBidding == 0) {
			cout << endl;
			cout << "All bidding participants withdrew, so " << square->getBuildingName()
				 << " is still available for the next players!" << endl;
			cout << endl;
			break;
		}

		cout << endl;
		cout << "Start the new round!" << '\n' << endl;
	} // while

	price = highestPrice;  // update final price.
	Winner = copy[0];   // update the winner.
}

/*
void Auction::auctionBankruptcy(Player* player[], int numPlayers, Square** property) {

	// check all squares and start auction when we find squares that the player who declared 
	// bankruptcy.
	for (int i = 0, i < 40; i++) {
		if (&(property[i]->getOwner()) == &player) {
			auction(players, numPlayers, property[i]);
		}
	}
}
*/ //not working

void Auction::winner(Player* player, int price, Square* square) {
	player->setMoney(-price);  // the winner pay price for the purchasing. 
	square->setOwner(player);  // update the owner of this square to the winner. 
}
