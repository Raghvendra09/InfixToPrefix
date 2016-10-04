//INFIX   TO POSTFIX CONVERSION
/*   This program is only for binary operator
     ^           3
     /  %  *     2
     +  -        1
 */  
 /*  Sample Input and output
   ENTER INFIX EXPRESSION : (A+B*C-D)
   THE POSTFIX EXPRESSION OF GIVEN INFIX : (ABC*+D-)
  */
   
#include<bits/stdc++.h>
using namespace std;

int main(){
	stack < pair<int,string> > s;    //  pair for precedence and operator
	string str,str1;
	cout<<"ENTER INFIX EXPRESSION : ";
	cin>>str;
	str1="";
	str +=')';
	int i=0;
	s.push(make_pair(-1,"("));   //for initializing stack pair
	while(str[i]){
		switch(str[i]){
			case '(':
				s.push(make_pair(-1,"("));
				break;
			case ')':
				while(s.top().second != "("){
					str1 +=s.top().second;
					s.pop();
				}
				s.pop();
				break;
			case '^':
			  while( s.top().first == 3 )
				{
					str1 +=s.top().second;
					s.pop();
					
				}
				s.push(make_pair(3,"^"));
				break;	
			case '*':
			while( s.top().first >= 2 )
				{
					str1 +=s.top().second;
					s.pop();
					
				}
				s.push(make_pair(2,"*"));
				break;
			case '/' :
	    	while(s.top().first>= 2 )
				{
					str1 +=s.top().second;
					s.pop();
					
				}
				s.push(make_pair(2,"/"));
				break;
			case '%' :
		      while(s.top().first>= 2  )
				{
					str1 +=s.top().second;
					s.pop();
					
				}
				s.push(make_pair(2,"%"));
				break;	
			case '+':
			 while(s.top().first>=1 )
				{
					str1 +=s.top().second;
					s.pop();
					
				}
				s.push(make_pair(1,"+"));
				break;
		   case '-' :
		   	 while(  s.top().first>=1 )
				{   
					str1 +=s.top().second;
					s.pop();
					
				}
				s.push(make_pair(1,"-"));
				break;
		   default :
		       str1 +=str[i];		 // for non-operator character
		   }
		i++;

		
	}
    cout<<"\nTHE POSTFIX EXPRESSION OF GIVEN INFIX : (";
	cout <<str1<<")"<<endl;

    return 0;
}
