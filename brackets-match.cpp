/* 
 * Code in C++ that checks whether the brackets in an expression match.
 * 
 * Author: Hussama Ismail <hussama.ismail@gmail.com>
 * Date: 15/03/2018
 */
 
#include <iostream>
#include <string>
#include <regex>
#include <stack>

int main ()
{
  std::string expression = "[(3+2)+4]("; 
  const std::regex regex_pop ("\\)|\\]");
  const std::regex regex_push ("\\(|\\[");
  const std::regex regex_bracket_pair ("\\(\\)|\\[\\]");
  std::stack <std::string> brackets_stack;
  unsigned short expression_length, aux = 0u;
  expression_length = expression.length();
  bool unbalanced = false;

  for (aux = 0u; aux < expression_length; aux++)
  {
    std::string temp_char = std::string(1, expression.at(aux));
    /* check whether this char is a bracket opening */
    if (std::regex_match (temp_char, regex_push))
    {
      brackets_stack.push (temp_char);
    }
    else if (std::regex_match(temp_char, regex_pop))
    {
      /* check whether there was a previous bracket */
      if (brackets_stack.empty())
      {
        unbalanced = true;
        break;
      }
      std::string previous_bracket = brackets_stack.top();
      brackets_stack.pop();
      std::string temp_brackets_match = previous_bracket + temp_char;
      /* check whether the pair of brackets match */
      if (std::regex_match(temp_brackets_match, regex_bracket_pair) == false)
      {
        unbalanced = true;
        break;
      }
    }
  }
  
  /* if there is any remaining on the stack, it is unbalanced */
  if (!brackets_stack.empty())
  {
    unbalanced = true;
  }
  
  /* print the final veredict */
  if (unbalanced)
  {
    std::cout << "it is an unbalanced expression!" << std::endl;
  }
  else
  {
    std::cout << "that is a perfectly balanced expression!" << std::endl;
  }
  
  return 0;
}
