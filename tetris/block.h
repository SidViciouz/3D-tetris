#pragma once
#include <iostream>
#include <field.h>
#include <cstdlib>
#include <vector>

using namespace std;

class block{
public:
	block() = delete;
	block(field& f);
	~block(){};
	void print();
	bool update();
	void move(const int& dX,const int& dY,const int& dR,const int& dP,const int& dYaw);
	vector<int> getPosition();
	int getType();
	void rollBlock();
	void pitchBlock();
	void yawBlock();
	friend class graphic;
private:
	int type; // shape, 0~9
	int x; //0~49
	int y; //0~49
	int z; // height, 0~99
	int roll; // x-axis, 0~3
	int pitch;  // y-axis, 0~3 
	int yaw;  // z-axis, 0~3	
	field& myField;	
	int blockShape[3][3][3];
};
