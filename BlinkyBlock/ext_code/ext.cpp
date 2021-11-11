#include "ext.hpp"
#include "stdio.h"

#include <iostream>


#define dir_modulus 63

typedef enum {
	top = 1, 
	front = 2,
	left = 4,
	right = 8,
	back = 16,		
	bottom = 32

} dir_type;


const char* connection (int connection_surface) {
	switch (connection_surface) {
		case top: return "Top ";
		case front: return "Front ";
		case left: return "Left ";
		case right: return "Right ";
		case back: return "Back ";
		case bottom: return "Bottom ";
		default: return "No_connection ";
	}
}
/*
//checker(0,surface_leaf)==1
int checker (const int to_check,const int summ_surfaces){
	int surface = to_check;
	int check = summ_surfaces;


    for(int i=0;i<6;i++){
        if(check&(1<<i)){
            int outnumber = 1<<i;
			if(outnumber == surface)
				return 1;
        }
    }
    return 0;
}
*/

//what connected
int what_connected (const int seed_check,const int leaf_check){
	int seed = seed_check;
	int leaf = leaf_check;
	printf("\033[32m[Bogdan's output]:\033[0m SEEDs: ");
	if(seed==0){printf(connection(seed));}
    for(int i=0;i<6;i++){
        if(seed&(1<<i)){
            int s_outnumber = 1<<i;
            printf(connection(s_outnumber));
			
        }
    }
	printf("\n\033[32m[Bogdan's output]:\033[0m LEAFs: ");
	if(leaf==0){printf(connection(leaf));}
    for(int i=0;i<6;i++){
        if(leaf&(1<<i)){
            int l_outnumber = 1<<i;
            printf(connection(l_outnumber));
			
        }
    }
	printf("\n");
	return 1;
}

int measure(){
	int ans = rand() % 255 +1;
	return ans;
}

int play_sound (){
	printf("\007");
}

