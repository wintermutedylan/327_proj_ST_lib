//
/*
 * Functions.cpp
 *
 *  Created on: Nov 22, 2019
 *      Author: Dylan Wintermute
 */
#include <iostream>
#include <memory>

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

using namespace std;

std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit,
		int numAmerican, int numbAmericanDonutEnthusiest,
		int numWatches) {
	std::vector<std::unique_ptr<Smalltalk>> smalltalkPointers;
	for (int i = 0; i < numAmerican; ++i){
				std::unique_ptr<Smalltalk> a(new Smalltalk_American(i));
				smalltalkPointers.push_back(std::move(a));
			}
	for (int i = 0; i < numBrit; ++i){
		std::unique_ptr<Smalltalk> a(new Smalltalk_Brit(i));
		smalltalkPointers.push_back(std::move(a));
	}

	for (int i = 0; i < numbAmericanDonutEnthusiest; ++i){
			std::unique_ptr<Smalltalk> a(new ST_American_DonutEnthusiest(i));
			smalltalkPointers.push_back(std::move(a));
		}

	for (unsigned int i = 0; numWatches > 0 && i < smalltalkPointers.size(); ++i){
					std::unique_ptr<Watch> a(new Watch());

					if (smalltalkPointers[i]->giveWatch(a)){
						numWatches--;
					}
				}

	return smalltalkPointers;
}
