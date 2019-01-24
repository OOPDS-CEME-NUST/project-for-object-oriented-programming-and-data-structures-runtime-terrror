#include "libxl.h"
#include <iostream>
using namespace std;
using namespace libxl;

int main ()
{
	
	//{
 //   Book* book = xlCreateBook(); // xlCreateXMLBook() for xlsx
 //   if(book)
 //   {
 //       Sheet* sheet = book->addSheet(L"Sheet1");
 //       if(sheet)
 //       {
 //           sheet->writeStr(1, 30, L"Hello, World !");
 //           sheet->writeNum(1, 4, 1000);
 //       }
 //       book->save(L"example.xls");
 //       book->release();
 //   } 

	  //  Book* book = xlCreateBook(); // xlCreateXMLBook() for xlsx
   // if(book)
   // {
   //     Sheet* sheet = book->addSheet(L"Sheet1");
   //     if(sheet)
   //     {
   //         sheet->writeStr(4, 4, L"sdds, World !");
   //         sheet->writeNum(3, 1, 1000);

			//sheet->writeStr(2, 2, L"ass, World !");
   //         sheet->writeNum(3, 3, 2);
   //     }
   //     book->save(L"example.xls");
   //     book->release();
   // } 

Book* book1 = xlCreateBook();
if(book1)
{
    if(book1->load(L"neweg.xls"))
    {
        Sheet* sheet = book1->getSheet(0);
        if(sheet)
        {
            double d = sheet->readNum(3, 1);
            cout << d << endl;

            double f = sheet->readNum(3, 3);
            cout << f << endl;
        }
    }

    book1->release();
}
    return 0;
}

