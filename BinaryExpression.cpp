
#include "BinaryExpression.h"
using namespace std;

BinaryExpression::BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}

Expression *BinaryExpression::getLeft() const {
 return left;
}

Expression *BinaryExpression::getRight() const {
 return right;
}

BinaryExpression::~BinaryExpression() {
delete left;
delete right;
}

