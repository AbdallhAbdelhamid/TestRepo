#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED

#include <iostream>


template<class T>
class MyList
{

public:

    MyList<T>(int Size_In = 0);        /// Constructor with default Size = 0;
    MyList<T>(MyList& Other);    /// Copy Ctor
    ~MyList();                      /// Destructor


    void AddElementAtFirst(T Element);             /// Insert  As First Element
    void AddElementAtLast(T Element);              /// Insert  As Last Element
    void AddElementAtIndex(int Index, T Element);  /// Insert  in Specific Index , doesn't remove the old element, shifts the array
    void AddElementArray(const MyList& Other);      /// Adds element array at the end
    void ReplaceElementAtIndex(int Index, T Element);  /// Insert in specefic index , replacing old element.

    void RemoveElementAt(int Index);
    void RemoveElements();                          /// Removes all elements and frees the memory

    int GetSize() const;
    int GetLength() const;
    void PrintAll() const;                       /* Not Implemented yet */
    void ShrinkToFit();
    void ResizeInto(int NewSize);                 /// Increase or decrease capacity to specific size.
    int IsEmpty() const;                          /// Checks if has elements or no -- List might have 0 elements but has memory reserved

    /** Operators **/
    T& operator[](int Index);
    const MyList& operator = (const MyList& Other);
    MyList<T> operator+(const MyList& Other);
    const MyList& operator+=(const MyList& Other);


private:
    void ShiftElementsBackByOne(int Index);
    void ShiftElementsForwardByOne(int Index);

    T* Arr;             /// Underlying Structure
    int Size;           /// Current Size (Full List Size )
    int Length;         /// Current Length ( Number of objects currently stored )


};

/***************************************************************************************************************************************/
/******************************************** END OF HEADER FILE ************************************************************************/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/


template<class T>
MyList<T>::MyList(int Size_In)
{
    Size = Size_In;
    Arr = new T[Size];
    Length = 0;
}

template<class T>
MyList<T>::MyList(MyList& Other)
{
    Size = Other.Size;
    Arr = new T[Size];
    Length = Other.Length;

    for(int i = 0 ; i < Other.Length ; i++)
        Arr[i] = Other.Arr[i];
}

template<class T>
MyList<T>::~MyList()
{
    delete[] Arr;
    Arr = nullptr;
}

template<class T>
const MyList<T>& MyList<T>::operator=(const MyList& Other)  /// TODO: Can be optimized to not reallocate if new size is smaller
{
    if(Other.Size > Size)
    {
        delete[] Arr;
        Arr = nullptr;
        Size = Other.Size;
        Arr = new T[Size];
    }

    for(int i = 0 ; i < Other.Length ; i++)
        Arr[i] = Other.Arr[i];

    Length = Other.Length;


    return Other;
}

template<class T>
T& MyList<T>::operator[](int Index)
{
    if(Index >= 0 && Index < Size)
        return Arr[Index];
    std::cout<<std::endl<<"Out Of Array Boundary"<<std::endl;
    exit(0);    /// Stop The Program
}

template<class T>
int MyList<T>::GetSize() const
{
    return Size;
}

template<class T>
int MyList<T>::GetLength() const
{
    return Length;
}

template<class T>
void MyList<T>::PrintAll() const            /// works for integers ONLY until now
{
    for(int i = 0 ; i < Size ; i++)
        std::cout<< Arr[i]<< " ";
}

template<class T>
void MyList<T>::ShrinkToFit()       /// Make List Fit Exactly the number of elements , no free spaces. /** Tested **/
{
    if(Length < Size)
    {
        T* Temp = Arr;
        Size = Length;
        Arr = new T[Size];

        for(int i = 0 ; i < Size ; i++)
            Arr[i] = Temp[i];

        delete[] Temp;
    }
}

template<class T>
void MyList<T>::ResizeInto(int NewSize)
{
    if(NewSize > 0)
    {
        T* Temp = Arr;
        Size = NewSize;    /// Resize New..
        Arr = new T[Size];

        if(NewSize < Length)
            Length = NewSize;

        for (int i = 0 ; i < Length ; i++)    /// Copy Old Elements
            Arr[i] = Temp[i];

        delete[] Temp;                      /// De allocate old elements
    }
}

template<class T>
int MyList<T>::IsEmpty() const
{
    return Length == 0;
}


template<class T>
void MyList<T>::AddElementAtFirst(T Element) /** Tested **/
{
    Length++;
    if(Length >= Size)      /// Resize list if needed
        ResizeInto(Size*1.5+1);     /// Expand by percentage
    ShiftElementsForwardByOne(0);
    Arr[0] = Element;
}


template<class T>
void MyList<T>::AddElementAtLast(T Element) /** Tested **/
{
    int Current_Index = Length++;
    if(Length >= Size)      /// Resize list if needed
        ResizeInto(Size*1.5+1);     /// Expand by percentage

    Arr[Current_Index] = Element;
}

template<class T>
void MyList<T>::AddElementAtIndex(int Index, T Element)
{
    if(Index >= 0 && Index < Size)
    {
        Length++;
        if(Length >= Size)      /// Resize list if needed
            ResizeInto(Size*1.5+1);     /// Expand by percentage
        ShiftElementsForwardByOne(Index);
        Arr[Index] = Element;
    }
}

template<class T>
void MyList<T>::ReplaceElementAtIndex(int Index, T Element)  /// Insert in specefic index , replacing old element
{
    if(Index >= 0 && Index < Size)
        Arr[Index] = Element;
}




template<class T>
void MyList<T>::RemoveElementAt(int Index)      /// Removes element at a Specific index
{
    if (Index >= 0 && Index< Length)
    {
        ShiftElementsBackByOne(Index);
        Length--;
    }
    else
        std::cout<<std::endl<<"No Such Element"<<std::endl;
}

template<class T>
void MyList<T>::RemoveElements()    /** Tested **/
{
    delete[] Arr;
    Arr = nullptr;
    Size = 0;
    Length = 0;
}

template<class T>
void MyList<T>::ShiftElementsBackByOne(int Index)   /** Tested **/
{
    if(Index > 0 && Index < Size )
    {
        for(int i = Index ; i < Length-1 ; i++)
            Arr[i] = Arr[i+1];
    }
}


template<class T>
void MyList<T>::ShiftElementsForwardByOne(int Index)    /** Tested **/
{
    if(Index >= 0 && Index < Size)
    {
        T Temp = Arr[Index];
        for( int i = Length-1 ; i >= Index; i--)
            Arr[i] = Arr[i-1];
    }
}


template<class T>
const MyList<T>&  MyList<T>::operator+=(const MyList<T>& Other)
{
    int OldLength = Length;

    if(Length + Other.Length >= Size)           /// Check If Resize is needed
        ResizeInto(Length + Other.Length);

    Length = Length + Other.Length;             /// Set New Length

    for(int i = OldLength, j = 0 ; i < Length ; i++, j++)
        Arr[i] = Other.Arr[j];

    return *this;
}


template<class T>
MyList<T> MyList<T>::operator+(const MyList<T>& Other)
{
    int NewSize = Length+Other.Length;
    MyList<T> Result(NewSize);

    for(int i = 0 ; i < Length ; i++ )         /// Copy First Array
        Result.Arr[i] = Arr[i];

    for(int i = Length, j = 0 ; i < NewSize ; i++, j++)   /// Copy Second Array
        Result.Arr[i] = Other.Arr[j];

    Result.Length = NewSize;            /// Save Length

    return Result;
}

template<class T>
void MyList<T>::AddElementArray(const MyList<T>& Other)
{
    *this+=Other;
}


#endif // MYLIST_H_INCLUDED
