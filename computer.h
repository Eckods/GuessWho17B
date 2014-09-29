//
//  computer.h
//  guesssWho
//
//  Created by Joel Bateman on 9/27/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

#ifndef __guesssWho__computer__
#define __guesssWho__computer__
#include <vector>
#include <stdio.h>

#include "ctime"
#include "Person.h"

using namespace std;

enum status {HITS, NONE};

class computer{
    
protected:
	struct statusPicks{
        // Places holder for cards on opp. array
        int place;
        // Different attributes for characters profiles
        Person Basic, Hair, FacialHair, Accessories;
	};

    // Vector list of computers board
	vector<array<Person*, 24>> list;

public:
	computer();
    void selectQuestion();
	void play();
	void comp_choice();
	void test();
    status buildProfiles();
	~computer();
};

#endif /* defined(__guesssWho__computer__) */
