#include <string>
#include <map>
#include <stack>
#include <cmath> 
#include <iostream> 

#define atividade "05"
#define nome "Antonio Rewelli Oliveira dos santos"
#define matricula "554047"

using namespace std;

int precedence(char c) {
  switch (c) {
    case '+':
    case '-': return 1;
    
    case '*':
    case '/': return 2;

    case '^': return 3;

    case '(': return 0;

    default: return 0;
  }
}

bool isOperand(char ch) {
    return (isdigit(ch) || isalpha(ch));
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')');
}

bool isValidOperand(string str) {
  for (char c : str) {
    if (isdigit(c)) {
      return false;
    }
  }

  return true;
}

bool isValidNumber(string str) {
  for (char c : str) {
    if (isalpha(c) || (c != '.' && !isdigit(c))) {
      return false;
    }
  }

  return true;
}

float getOperationResult(float a, float b, char op) {
  switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    default:  return 0;
  }
}

float calculate(stack<float>& operands, stack<char>& operators) {
  float b = (operands.empty() ? throw runtime_error("error: stack underflow") : operands.top()); operands.pop();
  float a = (operands.empty() ? throw runtime_error("error: stack underflow") : operands.top()); operands.pop();

  char op = operators.top(); operators.pop();

  float result = getOperationResult(a, b, op);

  return result;
}

float xEval(string x, map<string, float> &m){
  // x é a ///expressão  de entrada
  // m é o mapa de variáveis/valor
  stack<float> operands;
  stack<char> operators;
  stack<char> parentheses;

  string operand = "";

  for (int i = 0; i < x.length(); i++) {
    char c = x[i];
    if (c == ' ') {
      continue;
    }

    while (!isOperator(c) && i < x.length() && !(c == ' ')) {
      operand += c;
      c = x[++i];
    }

    if (operand.length() > 0) {
      if (isdigit(operand[0])) {
        if (!isValidNumber(operand)) {
          throw runtime_error("error: invalid constant number finded");
        }
        operands.push(stof(operand));
      } else if (!isValidOperand(operand) || !m.count(operand)) {
        throw runtime_error("error: invalid operand finded");
      } else {
        operands.push(m[operand]);
      }
      operand.clear();
    }

    if (isOperator(c)) {
      if (c == '(') {
        operators.push(c);
        parentheses.push(c);
        continue;
      }

      if (c == ')') {
        if (parentheses.empty()) {
          throw runtime_error("invalid expression");
        }

        while (operators.top() != '(') {
          float res = calculate(operands, operators);
          operands.push(res);
        }
        operators.pop();
        parentheses.pop();
        continue;
      }

      while (!operators.empty()  && precedence(c) <= precedence(operators.top())){
        float result = calculate(operands, operators);
        operands.push(result);
      }
      operators.push(c);
    }
  }

  while (!operators.empty()) {

    float result = calculate(operands, operators);

    operands.push(result);
  }
  return operands.top(); 
}

int main() {
  map<string, float> m;
  m["x"] = 10;
  m["beta"] = 5;
  string str = "1+3-beta+x";


  try {
    float r = xEval(str, m);
    cout << "valor final: " << r << endl;
  } catch (const runtime_error& e) {
    cerr << e.what() << endl;
  }

  return 0;
}