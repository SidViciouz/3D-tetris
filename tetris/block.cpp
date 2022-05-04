#include <block.h>
#include <algorithm>

//type,z,x,y
int shape[3][3][3][3] = {
		{	
			{{1,1,1},
			{1,1,1},
			{1,1,1}}
			
			,{{1,1,0},
			{1,1,0},
			{1,1,0}}

			,{{0,1,0},
			{0,1,0},
			{0,1,0}}

		},
		{	
			{{1,1,1},
			{1,1,1},
			{1,1,1}}
			
			,{{0,0,0},
			{0,0,0},
			{0,0,0}}

			,{{0,0,0},
			{0,0,0},
			{0,0,0}}

		},
		{	
			{{1,1,1},
			{1,1,1},
			{1,1,1}}
			
			,{{0,1,0},
			{0,1,0},
			{0,1,0}}

			,{{0,0,0},
			{0,0,0},
			{0,0,0}}

		}

	};

block::block(field& f) : myField{f} {	
	this->type = rand()%3;	
	this->x = 3;
	this->y = 3;
	this->z = 12;
	this->roll = 0;
	this->pitch = 0;
	this->yaw = 0;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				this->blockShape[i][j][k] = shape[this->type][i][j][k];
}

void block::print(){
	
	cout << "type of this block is ";
	cout << this->type << "\n";
	cout << "(" << this->x << ",";
	cout << this->y << ",";
	cout << this->z << ")";
}

bool block::update(){

	for(int k=0; k<3; ++k)
		for(int i=0; i<3; ++i)
			for(int j=0; j<3; ++j){
				if(k+this->z-1 < 0 || (this->blockShape[k][i][j] == 1 &&this->myField.get(i+this->x,j+this->y,k+this->z-1) == true)){
					
					for(int k=0; k<3; ++k)
						for(int i=0; i<3; ++i)
							for(int j=0; j<3; ++j)
								this->myField.fieldfilled[z+k][x+i][y+j] = bool(this->blockShape[k][i][j]);

					return true;		
				}
			}

	this->z -= 1;
	return false;
}
void block::move(const int& dX,const int& dY,const int& dR,const int& dP,const int& dYaw){
	
	if(this->x + dX >= 0 && this->x + dX <= 6)
		this->x += dX;
	if(this->y + dY >= 0 && this->y + dY <= 6)
		this->y += dY;

	if(dR > 0){
		this->roll = (this->roll+1)%4;
		this->rollBlock();
	}
	if(dP > 0){
		this->pitch = (this->pitch+1)%4;
		this->pitchBlock();
	}
	if(dYaw > 0){
		this->yaw = (this->yaw+1)%4;
		this->yawBlock();
	}

}
vector<int> block::getPosition(){
	vector<int> position = {x,y,z};
	return position;
}

int block::getType(){
	return type;
}
void block::rollBlock(){
	for(int i=0; i<3; ++i){
		for(int j=0;j<3;++j)
			for(int k=j;k<3;++k)
				swap(this->blockShape[i][j][k],this->blockShape[i][k][j]);
		for(int j=0; j<3;++j)
			for(int k=0,h=2; k<h; ++k,--h)
				swap(this->blockShape[i][k][j],this->blockShape[i][h][j]);
	}
}
void block::pitchBlock(){
	for(int i=0; i<3; ++i){
		for(int j=0;j<3;++j)
			for(int k=j;k<3;++k)
				swap(this->blockShape[j][i][k],this->blockShape[k][i][j]);
		for(int j=0; j<3;++j)
			for(int k=0,h=2; k<h; ++k,--h)
				swap(this->blockShape[k][i][j],this->blockShape[h][i][j]);
	}

}
void block::yawBlock(){
	for(int i=0; i<3; ++i){
		for(int j=0;j<3;++j)
			for(int k=j;k<3;++k)
				swap(this->blockShape[k][j][i],this->blockShape[j][k][i]);
		for(int j=0; j<3;++j)
			for(int k=0,h=2; k<h; ++k,--h)
				swap(this->blockShape[j][k][i],this->blockShape[j][h][i]);
	}

}
