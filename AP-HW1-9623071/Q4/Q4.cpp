#include <iostream>
#include <fstream>
#include <string>

int main()
{

   int decrescent{};
   int nums{};
   int l{};

   std::ifstream inn{"input.txt"};
   
   //Calculating the number of inputs in file
   while(inn >> l)
    nums++;

   inn.close();
   
   std::ifstream in{"input.txt"};
   //Defining a array to storaging inputs
   int num_arr[size_t (nums)]{};
   
   //placing inputs in array
   for(int i{} ; i < size_t(nums) ; i++)
    in>>num_arr[i];
 
  in.close();
  
  //Dinfing a array to undeleting information  
  int new_arr[2*nums]{};
  new_arr[0] = 0;
  new_arr[2*nums - 1] = num_arr[0];
  
  //Undeleting information
  for(int i{1} ; i < nums ; i++)
  {
      if(num_arr[i - 1] < num_arr[i])
	decrescent = decrescent+num_arr[i] - num_arr[i-1];
     
      new_arr[2 * nums - 1 - i] = num_arr[i] - decrescent;
      new_arr[i] = decrescent;
    
  }
   std:: string answer;
   do
   {
    std::cout<<"Enter 'yes 'if you want a file consist of transactions "<<std::endl;
    std::cout<<"Enter ' no' if you want to see transactions at now"<<std::endl;
 
    std::cin>>answer;
 
    if(answer == "yes")
     {
      std::cout<<"Your list is ready!"<<std::endl;
      std::ofstream of{"new_list.txt"};
  
      for(int i{} ; i< 2 * nums ; i++)
       of<<new_arr[i]<<" ";
 
      of.close();
     }
     if(answer == "no")
     {
      	std::cout<<"This is your list"<<std::endl;

       for(int i{} ; i < 2 * nums;i++)
	 std::cout<<new_arr[i]<<" ";
       std::cout<<" "<<std::endl;
     }
    }
   while(answer != "yes"  && answer != "no");
   
      for(int i{} ; i < 2 * nums ; i = i + 2)
       num_arr[i / 2] = new_arr[i] + new_arr[i + 1];

      std::string answer1;

      do
      {
       std::cout<<" Enter 'yes' if you want list of result"<<std::endl;
       std::cout<<"Enter 'no' if you want to see result at now"<<std::endl;
       std::cin>>answer1;
       if(answer1 == "no")
	 {
	  std::cout<<"This is your list"<<std::endl;
          for(int i{} ; i < nums ; i++)
           std::cout<<num_arr[i]<<" ";
          std::cout<<" "<<std::endl;
         }
      if(answer1 == "yes")
	{
         std::cout<<"Your list is ready!"<<std::endl;
         std::ofstream out{"result.txt"};
  
         for(int i{} ; i < nums ; i++)
          out<<num_arr[i]<<" ";
 
         out.close();
        }
      }
      while(answer1 != "yes"  && answer1 != "no");
    
  return 0;
  
}
