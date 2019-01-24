#include <iostream>
#include "physicalobj.h"
#include "graph.h"
#include <string>
#include "libxl.h"

using namespace std;
using namespace libxl;

void setupvectorlist(graph& g1)
{
	physical a(1,4);
	powerplant p1(a,100);

	physical b(-2,2);
	powerplant p2(b,120);

	physical c(4,0);
	powerplant p3(c,50);	
	
	physical e(-1,-1);
	consumers c1(e);

	physical f(1,1);
	consumers c2(f);

	physical g(1,-1);
	consumers c3(g);

	node a1(&p1);
	a1.printnode();

	node a2(&p2);
	a2.printnode();

	node a3(&p3);
	a3.printnode();

	node a4(&c1);
	a4.printnode();

	node a5(&c2);
	a5.printnode();

	node a6(&c3);
	a6.printnode();
	
	g1.vectorlist.push_back(a1);
	g1.vectorlist.push_back(a2);
	g1.vectorlist.push_back(a3);
	g1.vectorlist.push_back(a4);
	g1.vectorlist.push_back(a5);
	g1.vectorlist.push_back(a6);
	
}

void setupedgelist(graph& g1)
{
	Book* book1 = xlCreateBook();
	
	if(book1)
	{
		if(book1->load(L"neweg.xls"))
		{
			cout << "Start\tEnd\tWeight\n";
			Sheet* sheet = book1->getSheet(0);
			for (int row=1 ;; row++)
			{
				edge e;
				if (sheet->readNum(row,3)==0.00) break;

				if(sheet)
				{
					int col=1;
					{	
						e.start=sheet->readNum(row, col);
						e.end= sheet->readNum(row, col+1);
						e.weight= sheet->readNum(row, col+2);

					}

					g1.edgelist.push_back(e);
				}
			}
			book1->release();
		}
	}
	//cout << endl;
}

int main ()
{
	graph x;

	setupvectorlist(x);

	setupedgelist(x);
	
	int row =0;
	for (row=0; row<x.size(); row ++)
	{
		cout << x.edgelist.at(row).start << "\t" << x.edgelist.at(row).end << "\t" << x.edgelist.at(row).weight << endl; 
	}
	x.update();
	cout << endl;
	cout << "Relate\tStart\tEnd\tDistance\n";
	for (row=0; row<x.size(); row ++)
	{
		cout << x.a[row] << "\t" <<x.edgelist.at(row).start << "\t" << x.edgelist.at(row).end << "\t" << x.edgelist.at(row).weight << endl; 
	} 
}