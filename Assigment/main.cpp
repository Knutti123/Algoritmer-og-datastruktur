#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
// task 1
int task_1(int N)
{
    if (N == 0)
    {
        return 0;
    }

    if (N % 2 != 0)
    {
        return N * N + task_1(N - 1);
    }
    else
    {
        return task_1(N - 1);
    }
}

// Task 2
//Siden der er 3 for-loops som alle incrementer deres respektive variabaler, vil Store o-tidskomplesksitet være O(n^3)

// Task 3
bool additive(string s)
{
    int i = s.length();
    vector<int> v;
    for (int j = 0; j < i; j++)
    {
        v.push_back(s[j] - '0');
    }
    for (int j = 0; j < i; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            for (int l = k + 1; l < i; l++)
            {
                if (v[j] + v[k] == v[l])
                {
                    return true;
                    break;
                }
            }
        }
    }
    return false;
}

// Task 4
int sum_calc(int input)
{
    int sum = 0;
    for (size_t i = 0; i < 64; i++)
    {
        if (log2(input + i) == static_cast<int>(log2(input + i)))
        {
            sum = input + i;
            break;
        }
        else if (log2(input - i) == static_cast<int>(log2(input - i)))
        {
            sum = input - i;
            break;
        }
    }
    return sum;
}
void task_4(vector<int> v)
{
    int size = v.size();
    vector<int> v2;
    v2.clear();
    int big_num = 0;
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (v[i] > big_num)
        {
            big_num = v[i];
        }
    }
    int big_pot = log2(big_num);

    for (size_t x = 0; x < big_pot; x++)
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                for (size_t k = 0; k < size; k++)
                {
                    int placeholder = v[i] + v[j] + v[k];
                    if (v2.size() != 3)
                    {
                        if (j != k && j != i && i != k)
                        {
                            if (log2(placeholder + x) == static_cast<int>(log2(placeholder + x)) || (log2(placeholder - x) == static_cast<int>(log2(placeholder - x))))
                            {
                                v2.push_back(v[k]);
                                v2.push_back(v[j]);
                                v2.push_back(v[i]);
                                result = v[k] + v[j] + v[i];
                            }
                        }
                    }
                }
            }
        }
    }
    v2.push_back(sum_calc(result));

    // Print the entire v2 vector
    cout << "v2 contains: ";
    for (size_t i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " "; // Print each element followed by a space
    }
    cout << endl; // Move to the next line after printing the vector}
}
//Siden der er et 3 nestede for loops i et for loop, hvor alle respektive variabler incrementer med 1 i dennne algoritme vil den have en O(n^4) tidskomplesksitet

// Task 5
//Siden det første loop går fra 0 til sqrt(N) vil tidskompleksiteten være O(sqrt(N))
//Den næste loop er en standard increment så tidskompleksiteten vil være O(N)
//Den sidste loop er en hvor variablen fordobler hvergang dermed må tidskompleksiteten være O(log(N))
//Dermed må tidskompleksiteten være O(sqrt(N)*N*log(N))
// Task 6
int sumDivisbleby3(int N)
{
    if (N == 0)
        return 0;

    if (N % 3 == 0)
        return N + sumDivisbleby3(N - 3);
    else
        sumDivisbleby3(N - 1);
    return N;
}

// Task 7
void Task7(int Z)
{
    if (Z <= 0 || Z > 100000)
        cout << "Number is not in criterion" << endl;
    int best_X = 0;
    int best_Y = 0;

    for (int X = 3; X < sqrt(Z); X++)
    {
        for (int Y = 3; Y < sqrt(Z); Y++)
        {
            if (pow(X, Y)==Z)
        {
                if (X > best_X)
                {
                    best_X = X;
                    best_Y = Y;
                }
        }
        }
        
    }
    cout << "X: " << best_X << " Y: " << best_Y << endl;
}

//Task 8

//Task 9
//Siden dette omhandler en rekursiv funktion som udregner de forskellige fibonaci tal vil tidskomplesksiteten være O(2^n) grundet at den udvider sig eksposentielt for hver gang den kaldes


//Task 10
int LogTo(int N)
{
    if(N==1)
    return 0;

    return 1+LogTo(N/2);
}

//Task 11
int Task11(vector <int> v)
{
    int size = v.size();
    int smallest_number=1;
    int biggest_number=0;
    int counter =0;
    int condition=0;
    for (size_t i = 0; i < size; i++)
    {
        if(v[i]>biggest_number)
        {
            biggest_number=v[i];
        }
        if(v[i]<smallest_number)
        {
            smallest_number=v[i];
        }
    }
    for (size_t i = smallest_number; i < biggest_number; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
        if(v[j]==i)
        {
            counter++;
            if (counter>=(size/2))
            {
                counter=0;
                return i;
                condition = true;
            }
        }
        else
        {
            counter=0;
        }
        }
    }
   if (condition==false)
    {
        return -1;
    }
}
// Siden det er et forloop med et nested forloop vil tidskomplesksiteten være O(n^2)


int main()
{
    vector<int> v = {23, 56, 22, 11, 65, 89, 3, 44, 87, 910, 45, 35, 98};
    task_4(v);
    int N = 12;
    int test = sumDivisbleby3(N);
    cout << test << endl;
    int Z = 6561;
    Task7(Z);
    int N2 =32;
    int test2 = LogTo(N2);
    cout << test2 << endl;
    vector<int> v2 = {7,4,3,5,3,1,6,4,5,1,7,5};
    int test3 = Task11(v2);
    cout << test3 << endl;
    return 0;
}


