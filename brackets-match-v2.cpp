/* 
 * Code in C++ that checks whether the brackets in an expression match (without stack).
 * 
 * Author: Hussama Ismail <hussama.ismail@gmail.com>
 * Date: 15/03/2018
 */

#include <iostream>
#include <string>

int main ()
{
  std::string expression = "[(3+2)+4]"; 
  
  unsigned short expression_length, aux = 0u;
  short counter_bracket1 = 0, counter_bracket2 =0;
  expression_length = expression.length();

  for (aux = 0u; aux < expression_length; aux++)
  {
    std::string temp_char = std::string(1, expression.at(aux));
    if (temp_char == "(") 
    {
      counter_bracket1++;
    } 
    else if (temp_char == ")") 
    {
      counter_bracket1--;
    }
    if (temp_char == "[") 
    {
      counter_bracket2++;
    } 
    else if (temp_char == "]") 
    {
      counter_bracket2--;
    }
  }
  
  if ((counter_bracket1 != 0) || (counter_bracket2 != 0))
  {
    std::cout << "unbalanced" << std::endl;     
  }
  else
  {
    std::cout << "balanced" << std::endl; 
  }
  
  return 0;
}
