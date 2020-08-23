class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        if (n <= 0) return result;

        for (int i = 1; i <= n; i++) {
            if (aliquot3_5(i)) {
                result.push_back("FizzBuzz");
            } else if (aliquot3(i)) {
                result.push_back("Fizz");
            } else if (aliquot5(i)) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i));
            }
        }

        return result;
    }

    bool aliquot3(int num) {
        return num % 3 == 0;
    }

    bool aliquot5(int num) {
        return num % 5 == 0;
    }

    bool aliquot3_5(int num) {
        return num % 3 == 0 && num % 5 == 0;
    }
};
