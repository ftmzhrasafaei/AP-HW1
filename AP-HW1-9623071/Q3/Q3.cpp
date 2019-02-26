#include <iostream>
#include <cmath>

double x_newer(double x, double y, double z, double w);

double Error(double x, double y);

void root_finder(double err, double old ,double older,double arr[],int n);

double f(double x,double arr[],int size_of_arr);

void display(double arr[],int size_of_arr);


int main(int argc ,char* argv[])
{
  //Defining the highest degree of function
  int highest_degree = argc-2;
  
  //Defining a array to storaging coefficients
  double coefficients[highest_degree + 1]{};
  
  for(int i{1} ; i < argc ; i++)
     coefficients[i - 1] = atof(argv[i]);

  display(coefficients,highest_degree + 1);

  std::cout<<"What is your first initial guess?!"<<std::endl;
  
  double first_guess{};
  double second_guess{};
  double max_error{};
  
  //giving guesses and max error
  std::cin>> first_guess;
  std::cout<<"What is your second initial guess?!"<<std::endl;
  std::cin>>second_guess;
  std::cout<<"What is the maximum acceptable error?!"<<std::endl;
  std::cin>>max_error;
  
  //finding root  
  root_finder(max_error,second_guess,first_guess,coefficients,highest_degree+1);
  
  return 0;


}



//functions:



//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//This function calculates the value of function
double f(double x,double arr[],int size_of_arr ){
  double sum{};
  for(int i{} ; i < size_of_arr ; i++)
    sum = sum + arr[i]*(pow(x,(size_of_arr - 1 - i)));
  return sum;
}

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//This function displays fucntion  
void display(double arr[],int size_of_arr){
  
  for(int i{} ; i < size_of_arr - 1;i++)
    std::cout<<arr[i]<<"x^"<<size_of_arr - 1 - i<<"+";
  std::cout<<arr[size_of_arr - 1]<<std::endl;
}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//This function calculates error for 2 numbers
double Error(double x, double y){
  double epsilon{};
  epsilon= (x - y) / y;
  if (epsilon >= 0)
	return epsilon;
  else
	return (-1)*epsilon;
}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


//This function calculates a new x
double x_newer(double x, double y, double z, double w){
  //double l= x-(z*(x-y))/((z-w));
  double l = (y * z - x * w) / (z - w);
  return l ;
}



//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//This functin finds root
void root_finder(double err, double old ,double older,double arr[],int n){
  int i{};
  double x_new{};
  double x_old = old;
  double x_older = older;
  double loop_error{};
  double f_x{};
  do{
   
   std::cout<<"============level  "<<i + 1<<"=========="<<std::endl;
   i = i + 1;
   x_new = x_newer(x_old,x_older,f(x_old,arr,n),f(x_older,arr,n));
   loop_error = Error(x_new,x_old);
   f_x = f(x_new,arr,n);
   std::cout<<x_new<< " is new x!"<<std::endl;
   std::cout <<x_old<<" is old x!"<<std::endl;
   std::cout<<"f(x)="<<f_x<<std::endl;
   std::cout<< "and error in this level is "<<loop_error<<std::endl;
   x_older = x_old;
   x_old = x_new;
  }
  while(loop_error>err);
  std::cout<<"========The End========"<<std::endl;
  std::cout<<"The final answer is  "<<x_new<<std::endl;
}
   

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-   
