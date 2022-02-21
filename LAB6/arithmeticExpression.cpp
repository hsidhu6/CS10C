#include <iostream>
#include <cstdlib>
#include <stack>
#include <fstream>
#include <sstream>
#include "arithmeticExpression.h"

using namespace std;

arithmeticExpression::arithmeticExpression(const string &expr):infixExpression(expr), root(0){}
void arithmeticExpression::buildTree()
{
string postfix = infix_to_postfix();

//generate the tree from postfix expression
char key = 'a';
char c;

stack<TreeNode*> s;
for (unsigned int i = 0; i < postfix.length();i++)
  {
    c = postfix.at(i);
    if (c == '+' || c== '-' ||c== '*')
    {
      TreeNode* temp = new TreeNode(c, key++);
      temp -> right = s.top();
      s.pop();
      temp -> left = s.top();
      s.pop();
      s.push(temp);
    }
    else
    {
    s.push(new TreeNode(c, key++));
    }
    //if c is an operator 17
      //create the node TreeNode* temp = new TreeNbde(c, keys++);
      //assign right child of node, temp -> right = s.topO
      // s.pop()
      //temp -> left - s.top()
      //s.pop()
      //s.push(temp)
    
    //else
      //s.push(new TreeNode(c, keys+))
  }
  root = s.top();
}
void arithmeticExpression::infix() 
{
  infix(root);
}
void arithmeticExpression::prefix()
{
  prefix(root);
}
void arithmeticExpression::infix(TreeNode* n)
{ 
  // this is the helper function that we will call recursively
  //left child -> right child
  //check whether n is valid
  //if valid,if there is a left child, cout << '('
//infix(n -> left)
//cout << n-> data;
//infix (n -> right);
//if there is a right child, cout << ')';
// if there is a tree write it in infix notation
if (n == 0) {
		return;
	}
	if (priority(n->data)) {
		cout << "(";
		infix(n->left);
		cout << n->data;
		infix(n->right);
		cout << ")";
	}
	else {
		infix(n->left);
		cout << n->data;
		infix(n->right);
	}
}

void arithmeticExpression::prefix(TreeNode* n)
{
  //very similar to infix
  if (n == 0) {
		return;
	}
	cout << n->data;
	prefix(n->left);
	prefix(n->right);
}

void arithmeticExpression::postfix(TreeNode* n)
{
  if (n == 0) {
      return;
    }

    postfix(n->left);
    postfix(n->right);
    cout << n->data;
}

int arithmeticExpression::evaluate() //
{
  //this is the public function that will use the other helper functions 
  // if expression is not valid, throw invalid_argument ("expression not valid")
  if (!isValidIntegerExpression(root))
  {
    throw invalid_argument ("expression not valid");

  }
  //else, call evaluateIntegerExpression()
  else 
  {
    return evaluateIntegerExpression(root);
  }
}
bool arithmeticExpression::isValidIntegerExpression(TreeNode *n) //
{ 
  if (n -> data >= '0' && n -> data <= '9')
  {
    return true;
  }
  else if (n -> data == '-' || n -> data == '+' || n -> data == '*')
  {
    return isValidIntegerExpression(n -> left) && isValidIntegerExpression(n -> right);
  }
  else 
  {
     return false;
  }
   //this will check whether the given expression is valid or not
   // if there is any character other than integer, its not valid, 3 * p - 4 = not valid
   //we are given the root node of the tree
   //so we need to traverse the tree and then check if each value is a valid value or not
   //hint; you'll need recursion to traverse
   //if not n return false
   // if n->data > "O' and < '9' return true
   // if n-›data is an operator, see if left subtree is true (recursively, call this function again with n-›left) and right subtree is true
   //if both are true, then return true, if any one of them is false return false
}
int arithmeticExpression::evaluateIntegerExpression (TreeNode* n) //
{ 
  int value = int(n->data) - '0';
  if (value >= 0)
  {
    return value;
  }
  else if (value == -6) //*
  {
    return evaluateIntegerExpression (n -> left) * evaluateIntegerExpression (n -> right);
  }
  else if (value == -5) //+
  {
    return evaluateIntegerExpression (n -> left) + evaluateIntegerExpression (n -> right);
  }
  else if (value == -3) //-
  {
    return evaluateIntegerExpression (n -> left) - evaluateIntegerExpression (n -> right);
  }
  //if valid, this will output result 
  //n->data - '0'
  //if curr node is an integer, we return the integer, return n->data - '0'
  //calculate the left subtree (call this function recursively with n -> right)
  // if current value (n -> data) is '*'
  //if current value is '-'
 return 0;
}

string arithmeticExpression::infix_to_postfix()
{
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    //visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
 void arithmeticExpression::postfix()
 {
   postfix(root);
 }