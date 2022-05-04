#include <cstring>
#include <field.h>
#include <block.h>
#include <iostream>
extern int shape[3][3][3][3];

field::field(){
	memset(this->fieldfilled,false,sizeof fieldfilled);
}

bool field::get(int x,int y,int z){
	return this->fieldfilled[z][x][y];
}

void field::check(){
	for(int k=0;k<15;++k){
		bool success = true;
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j){
				if(this->fieldfilled[k][i][j] == 0){
					success = false;
					break;
				}
			}
			if(!success)
				break;
		}
		if(success){
			for(int i=0;i<9;++i)
				for(int j=0;j<9;++j)
					this->fieldfilled[14][i][j] = 0;
			for(int h=k+1;h<15;++h)
				for(int i=0;i<9;++i)
					for(int j=0;j<9;++j)
						this->fieldfilled[h-1][i][j] = this->fieldfilled[h][i][j];

		}
	}
}

bool field::isGameOver(){

	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			if(this->fieldfilled[14][i][j] == 1)
				return true;

	return false;
}
