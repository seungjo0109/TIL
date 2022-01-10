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

    bool operator==(Operator& op){
        return val_ == op.val_;
    }
    int operator+(Operator& op){
        return val_ + op.val_;
    }

    int val_;

};

#endif // OPERATOR_H_