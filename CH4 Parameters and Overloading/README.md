## Chapter summary
• A formal parameter is a kind of placeholder that is filled in with a function argument when the function is called. In C++, there are two methods of performing this substitution, call by value and call by reference, and so there are two basic kinds of  
parameters: call-by-value parameters and call-by-reference parameters.  
• A call-by-value formal parameter is a local variable that is initialized to the value of  
its corresponding argument when the function is called. Occasionally, it is useful to  
use a formal call-by-value parameter as a local variable.  
• In the call-by-reference substitution mechanism, the argument should be a variable,  
and the entire variable is substituted for the corresponding argument.  
• The way to indicate a call-by-reference parameter in a function definition is to attach  
the ampersand sign, & , to the type of the formal parameter. (A call-by-value parameter  
is indicated by the absence of an ampersand.)  
• An argument corresponding to a call-by-value parameter cannot be changed by a  
function call. An argument corresponding to a call-by-reference parameter can be  
changed by a function call. If you want a function to change the value of a variable,  
then you must use a call-by-reference parameter.  
• You can give multiple definitions to the same function name, provided that the  
 different functions with the same name have different numbers of parameters or  
some parameter position with differing types, or both. This is called overloading the  
function name.  
• You can specify a default argument for one or more call-by-value parameters in a  
function. Default arguments are always in the rightmost argument positions.   
