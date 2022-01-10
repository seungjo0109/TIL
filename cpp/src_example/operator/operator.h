#ifndef OPERATOR_H_
#define OPERATOR_H_

class Operator
{
public:

    Operator(int val): val_(val){}

    // default copy constructor(shallow copy)
    Operator& operator=(const Operator& op){
        val_ = op.val_;

        return *this;
    }
    /* 
        통상적으로 자기 자신을 리턴하지 않는 이항 연산자들 (+, -, *, / 등)은 외부 함수로 선언하는 것이 원칙
        반대로 자기 자신을 리턴하는 이항 연산자들 (+=, -= 등)은 멤버함수로 선언하는 것이 원칙 
    */
    bool operator==(Operator& op){
        return val_ == op.val_;
    }
    int operator+=(Operator& op){
        return val_ + op.val_;
    }

    int val_;

};

Operator operator+(const Operator& op1, const Operator& op2){

    Operator op(op1.val_ + op2.val_);

    return op;
}

#endif // OPERATOR_H_