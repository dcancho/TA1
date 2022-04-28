#pragma once

class Meteorito
{
private:
	int ypos, xpos, vel;
public:
	Meteorito()
	{
		System::Random r;
		ypos = r.Next(0, 81);
		xpos = r.Next(0, 41);
		vel = r.Next(0; 100) / 100;
	}
	~Meteorito(){}

};