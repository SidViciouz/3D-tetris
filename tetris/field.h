#pragma once

class field{
public:
	field();
	~field(){};
	bool get(int x,int y,int z);
	void check();
	bool isGameOver();
	friend class block;
	friend class graphic;
private:
	bool fieldfilled[15][9][9];
};
