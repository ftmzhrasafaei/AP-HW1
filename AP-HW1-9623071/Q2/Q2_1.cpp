#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

long long decimal2binary(int num);

int main()
{
  //The victim's name
  std::string name{""};
  
  //The victim's age
  int age{};
  
  std::cout<<"Enter the name:"<<std::endl;
  std::cin>>name;
  
  std::cout<<"Enter the birthday's year:"<<std::endl;
  std::cin>>age;
  
  //?The number of name's letter
  int letters = name.size();
  
  //?The number of permutations
  int states = pow(2,letters);
  
  //Total permutations
  char guess[states][size_t(letters)]{};
  
  //Placing the name in the first row
  for(int i{} ; i < letters ; i++)
    guess[0][i] = name[i];
  
  //Defining a array to storaging name in binary form 
  long long binarynums[states];
  
  //Transforming name to binary
  for(int i{} ; i < states ; i++)
    binarynums[i] = decimal2binary(i);

  //Defining a array to storaging states in binary form 
  int binaries[states][letters]{};
  
  //Generate the entire state in binary form
  for(int i{} ; i < states ; i++)
   {
     for(int j{} ; j < letters ; j++)
        {
         binaries[i][letters - j - 1] = binarynums[i]%10;
         binarynums[i] /= 10;
         //std::cout<<binaries[i][letters-j-1];
	}
       //std::cout<<std::endl;
  }

  //Writing in file
  std::ofstream of{"dictionary.txt"};

  //Generate the entire state in alphabetical order
  for(int i{} ; i < states ; i++){
    for(int j{} ; j < letters ; j++){
      if(binaries[i][j] == 1)
	guess[i + 1][j] = toupper(guess[0][j]);
      
      else
	guess[i + 1][j] = tolower(guess[0][j]);
       of<<guess[i + 1][j];
    }
    //Writing age at the end of names
    of<<age<<std::endl;
  }

    for(int i{} ; i < states ; i++)
      {
      	of<<age;
    	for(int j{} ; j < letters ; j++)
	  {
      		if(binaries[i][j] == 1)
			guess[i + 1][j] = toupper(guess[0][j]);
     		else
			guess[i + 1][j] = tolower(guess[0][j]);
     		of<<guess[i + 1][j];
    }

    //Writing age at the first of names        
    	of<<std::endl;
  }
  of.close();
  
  std::cout<<"Your dictionary is ready!"<<std::endl;
  
  return 0;
}



//functions:

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//This function transfers a number to binary form
long long decimal2binary(int num)
{
  //Binary form
  long long binarynum{};
  //Digits
  int reminder{};
  
  int i{1};
  //Generateing digits
  while(num != 0)
    {
    reminder = num%2;
    
    num /= 2;
    
    binarynum += reminder*i;
    
    i *= 10;
    
  }
  
  return binarynum;
}



//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-




