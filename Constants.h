#pragma once
class Constants
{
private:
	 //Do not change the values below !!!!!
	static const int TOTALCARDS = 112;
	static const int BLUE = 19;
	static const int GREEN = 19;
	static const int RED = 19;
	static const int YELLOW = 19;

public:
	Constants();
	~Constants();
	int getTotalCards() const;
	int getBlueCards() const;
	int getGreenCards() const;
	int getRedCards() const;
	int getYellowCards() const;
};

