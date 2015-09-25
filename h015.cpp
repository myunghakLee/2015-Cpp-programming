#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

class kind_of_tryangle
{

private:
	float x1, y1;
	float x2, y2;
	float x3, y3;
	float line_square[3]; //lin1�� ����
	float hypo;//����
	float side1,side2;
	int tryangle;

public:

	kind_of_tryangle(ifstream& input)
	{
		input>>x1;
		input>>y1;
		input>>x2;
		input>>y2;
		input>>x3;
		input>>y3;
	}
	void calc()
	{
		line_square[0] = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		line_square[1] = (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
		line_square[2] = (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);

		if(line_square[2]>=line_square[1] && line_square[2]>=line_square[0])
		{
			hypo = line_square[2];
			side1= line_square[1];
			side2= line_square[0];
		}	
		else if(line_square[1]>=line_square[0] && line_square[1]>=line_square[2])
		{
			hypo = line_square[1];
			side1= line_square[0];
			side2= line_square[2];
		}
		else
		{
			hypo = line_square[0];
			side1= line_square[1];
			side2= line_square[2];
		}

		if(abs((x1-x2)/(y1-y2))==abs((x1-x3)/(y1-y3))||abs((x1-x3)/(y1-y3))==abs((x2-x3)/(y2-y3))||abs((x1-x2)/(y1-y2))==abs((x2-x3)/(y2-y3)))
		{
			tryangle = 0;
		}
		else if(hypo==side1+side2)
		{
			tryangle=1;

		}
		else if(hypo>side1+side2)
		{
			tryangle=2;

		}
		else if(hypo<side1+side2)
		{
			tryangle=3;
		}
		cout<<tryangle<<endl;
	}
};

void main()
{
	ifstream put;

	put.open("input.txt");

	int cases;
	put>>cases;
	for(int i=0; i<cases; i++)
	{
		kind_of_tryangle try1(put);
		try1.calc();
	}

}
