#pragma once

class Meteorito
{
private:
	int ypos, xpos;
	float velocity;
public:
	Meteorito()
	{
		System::Random r;
		ypos = r.Next(0, 81);
		xpos = r.Next(0, 41);
		velocity = r.Next(0, 100) / 100;

	}
	~Meteorito(){}
	Meteorito(int x, int y, float vel)
	{
		ypos = y;
		xpos = x;
		velocity = vel;
	}
};