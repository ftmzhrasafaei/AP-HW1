#include <iostream>

void swap(int* ,int*);

void sort(int arr[],int size_of_arr);

int calculator(int arr[],int size_of_arr);



int main(int argc ,char* argv[])
{
  //the minimum money for lending
  int loan{};
  
  //the number of companies
  int companies{argc-1};
  
  // the capital of companies
  int capitals [companies]{};
  
  //get capitals from commandline
  for(int i{1} ; i < argc ;i++) 
    capitals[i-1] = std::stoi(argv[i]);
  
  //sorting capitals
  sort(capitals,companies);
  
  //calculating loan
  loan=calculator(capitals,companies);

  //showing loan
  std::cout<<"\n"<<"The minimum amount of money spent from the fund to lend to comanies is  "<<loan<<" million dollers"<<std::endl;
			 
 return 0;
}




//functions:



//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//This function swaps 2 variables

void swap(int* x,int* y)
{
  //the broker for swaping
  int broker{*x};
  *x = *y ;
  *y = broker;
}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

// This is function stors elements of array

void sort(int arr[],int size_of_arr)
{
  // swaping in a bright way
  for(int i{} ;  i < size_of_arr-1 ; i++)
    for(int j{} ; j < size_of_arr-i-1 ; j++)
      if(arr[j] > arr[j+1])
	swap(&arr[j] , &arr[j+1]);
}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//This function calculates loan

int calculator(int arr[],int size_of_arr)
{
  int loan{};
  
  //  calculating loan
  for(int i{} ; i < size_of_arr ; i = i + 2) 
    loan = loan + arr[i+1] - arr[i];
  
  return loan;
}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
