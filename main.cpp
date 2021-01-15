#include <iostream>
#include "MyList.h"

// first merge

using namespace std;

class Complex
{
public:

    int x ; int y;
    Complex(int X , int Y)
    {
        x = X;
        y = Y;
    }

    Complex()
    {
        x = 0; y = 0;
    }

    void Print()
    {
        cout<<x<<" ,"<<y<<endl;
    }
};



int main()
{

 //   MyList<double> Listo(11);
 //   Listo.AddElement(5.5);
  //  Listo.AddElement(3.3);
   // Listo.AddElement(1.1);

/*

    for(int i = 0 ; i < 10 ; i++)
        cout<<Listo[i] << " ,";
    cout<<endl;

    Listo.RemoveElementAt(1);

       for(int i = 0 ; i < Listo.GetLength() ; i++)
        cout<<Listo[i] << " ,";
    cout<<endl;


    cout<<"--------------------------------------------------------------------"<<endl;

    MyList<Complex> Listo2(3);
    Complex C1(5,5);
    Listo2.AddElement(C1);
    Listo2.AddElement(Complex(10,10));


    Listo2.RemoveElementAt(1);
    for(int i = 0 ; i < Listo2.GetSize() ; i++)
        Listo2[i].Print();
*/
/*
    MyList<int> listo;
    cout<<endl<<listo.GetSize()<<endl;

    listo.AddElementAtLast(5);
    listo.AddElementAtLast(10);
    listo.AddElementAtLast(15);


    for(int i = 0 ; i < listo.GetLength() ; i++)
        cout<<listo[i] << " ,";

    cout<<endl<<listo.GetSize() << " " << listo.GetLength() << endl;

    listo.ShrinkToFit();

  //  cout<<endl<<listo.GetSize()<<endl;

      cout<<endl<<listo.GetSize() << " " << listo.GetLength() << endl;


    for(int i = 0 ; i < listo.GetLength() ; i++)
        cout<<listo[i] << " ,";


*/


    MyList<int> list1(2);
    MyList<int> list2(0);

    list1.AddElementAtLast(5);
    list1.AddElementAtLast(5);
    list2.AddElementAtLast(10);
    list2.AddElementAtLast(10);




    for(int i = 0 ; i < list1.GetLength() ; i++)
        cout<<list1[i] << " ,";
    cout<<endl<<list1.GetSize()<<endl;

        for(int i = 0 ; i < list2.GetLength() ; i++)
        cout<<list2[i] << " ,";
    cout<<endl<<list2.GetSize()<<endl;

    MyList<int> list3(2);
    cout<<"---------------------------------------------"<<endl;



    list1.AddElementArray(list2);
       for(int i = 0 ; i < list1.GetLength() ; i++)
        cout<<list1[i] << " ,";
    cout<<endl<<list1.GetSize()<<endl;
    cout<<endl<<list1.GetLength()<<endl;



}



