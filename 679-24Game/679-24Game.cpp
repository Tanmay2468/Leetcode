// Last updated: 8/31/2025, 10:49:43 AM
class Solution {
public:
    static double add(double a, double b) {
        return a + b;
    }
    static double sub(double a, double b) {
        return a - b;
    }
    static double mul(double a, double b) {
        return a * b;
    }
    static double div(double a, double b) {
        return a / b;
    }
    map<char, function<double(double, double)>> oper={{'+', add}, {'-', sub}, {'*', mul}, {'/', div}};

    bool isApprox24(double val)
    {
        const double EPS = 1e-4;
        return fabs(val - 24.0) < EPS;
    }
    bool pat1(double a, double b, double c, double d){
        // (a, b)(c, d)
        for (auto it1: oper)
        {
            double temp1=it1.second(a, b);
            for (auto it2: oper)
            {
                double temp2=it2.second(c, d);
                for (auto it3: oper)
                {
                    double temp3=it3.second(temp1, temp2);
                    if (isApprox24(temp3)) return true;
                }
            }
        }
        return false;
    }
    bool pat2(double a, double b, double c, double d){
        // ((a, b)c)d
        for (auto it1: oper)
        {
            double temp1=it1.second(a, b);
            for (auto it2: oper)
            {
                double temp2=it2.second(temp1, c);
                for (auto it3: oper)
                {
                    double temp3=it3.second(temp2, d);
                    if (isApprox24(temp3)) return true;
                }
            }
        }
        return false;
    }
    bool pat3(double a, double b, double c, double d){
        // (a(b, c))d
        for (auto it1: oper)
        {
            double temp1=it1.second(b, c);
            for (auto it2: oper)
            {
                double temp2=it2.second(a, temp1);
                for (auto it3: oper)
                {
                    double temp3=it3.second(temp2, d);
                    if (isApprox24(temp3)) return true;
                }
            }
        }
        return false;
    }
    bool pat4(double a, double b, double c, double d){
        // a((b, c)d)
        for (auto it1: oper)
        {
            double temp1=it1.second(b, c);
            for (auto it2: oper)
            {
                double temp2=it2.second(temp1, d);
                for (auto it3: oper)
                {
                    double temp3=it3.second(a, temp2);
                    if (isApprox24(temp3)) return true;
                }
            }
        }
        return false;
    }
    bool pat5(double a, double b, double c, double d){
        // a(b(c, d))
        for (auto it1: oper)
        {
            double temp1=it1.second(c, d);
            for (auto it2: oper)
            {
                double temp2=it2.second(b, temp1);
                for (auto it3: oper)
                {
                    double temp3=it3.second(a, temp2);
                    if (isApprox24(temp3)) return true;
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        do{
            double a=cards[0];
            double b=cards[1];
            double c=cards[2];
            double d=cards[3];
            bool flag1=pat1(a, b, c, d);
            bool flag2=pat2(a, b, c, d);
            bool flag3=pat3(a, b, c, d);
            bool flag4=pat4(a, b, c, d);
            bool flag5=pat5(a, b, c, d);
            if (flag1 || flag2 || flag3 || flag4 || flag5) return true;
        } while (next_permutation(cards.begin(), cards.end()));
        return false;
    }
};