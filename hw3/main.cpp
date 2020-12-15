//==============================================================//
//|         NCCU CS Data Structure Homework 2 by.CTHua         |//
//==============================================================//
#include <bits/stdc++.h>
#include "skiplist.h"
#define pb push_back
#define PII pair<int, int>
#define mkp make_pair
#define Lint long long
#define N_max 28
#define R_max 1073741824 //2^30

using namespace std;

//Main
int main()
{
    string command;
    srand(time(NULL));
    fstream outfile;
    while (cin >> command)
    {
        if (command == "unordered_set")
        {
            unordered_set<int> SC;
            outfile.open("./o_set.csv", ios::out);
            outfile << "insert,search" << endl;
            outfile.close();
            for (int N = 10; N <= N_max; N++)
            {
                //open file and write N(power of 2)
                outfile.open("./o_set.csv", ios::app);
                outfile << N << endl;
                outfile.close();
                //
                cout << N << ": "; //output to check run situation
                int size = 1;
                size <<= N; //size=2^N
                for (int t = 1; t <= 10; t++)
                {
                    double start, end;
                    outfile.open("./o_set.csv", ios::app);
                    SC.clear();
                    //
                    //insert part
                    start = clock();
                    for (int i = 0; i < size; i++)
                        SC.insert(rand() % R_max + 1);
                    end = clock();
                    outfile << (end - start) / CLOCKS_PER_SEC << ",";
                    //
                    //search part
                    start = clock();
                    for (int i = 0; i < 1e5; i++)
                        SC.find(rand() % R_max + 1);
                    end = clock();
                    outfile << (end - start) / CLOCKS_PER_SEC << endl;
                    //
                    outfile.close();
                    cout << t << " "; //output to check run situation
                }
                //
                cout << endl;
            }
        }

        else if (command == "set")
        {
            set<int> SC;
            outfile.open("./set.csv", ios::out);
            outfile << "insert,search" << endl;
            outfile.close();
            for (int N = 10; N <= N_max; N++)
            {
                //open file and write N(power of 2)
                outfile.open("./set.csv", ios::app);
                outfile << N << endl;
                outfile.close();
                //
                cout << N << ": "; //output to check run situation
                int size = 1;
                size <<= N; //size=2^N
                for (int t = 1; t <= 10; t++)
                {
                    double start, end;
                    outfile.open("./set.csv", ios::app);
                    SC.clear();
                    //
                    //insert part
                    start = clock();
                    for (int i = 0; i < size; i++)
                        SC.insert(rand() % R_max + 1);
                    end = clock();
                    outfile << (end - start) / CLOCKS_PER_SEC << ",";
                    //
                    //search part
                    start = clock();
                    for (int i = 0; i < 1e5; i++)
                        SC.find(rand() % R_max + 1);
                    end = clock();
                    outfile << (end - start) / CLOCKS_PER_SEC << endl;
                    //
                    outfile.close();
                    cout << t << " "; //output to check run situation
                }
                //
                cout << endl;
            }
        }
        else if (command == "skiplist")
        {
            double SKIP_LIST_LVL_RATE;
            cin >> SKIP_LIST_LVL_RATE;
            outfile.open("./skip.csv", ios::app);
            outfile << "insert,search,rate=," << SKIP_LIST_LVL_RATE << endl;
            outfile.close();
            for (int N = 10; N <= N_max; N++)
            {
                //open file and write N(power of 2)
                outfile.open("./skip.csv", ios::app);
                outfile << N << endl;
                outfile.close();
                //
                cout << N << ": "; //output to check run situation
                int size = 1;
                size <<= N; //size=2^N
                for (int t = 1; t <= 10; t++)
                {
                    SkipList SC(N, SKIP_LIST_LVL_RATE);
                    double start, end;
                    outfile.open("./skip.csv", ios::app);
                    //
                    //insert part
                    start = clock();
                    for (int i = 0; i < size; i++)
                        SC.insert(rand() % R_max + 1);
                    end = clock();
                    outfile << (end - start) / CLOCKS_PER_SEC << ",";
                    //
                    //search part
                    start = clock();
                    for (int i = 0; i < 1e5; i++)
                        SC.find(rand() % R_max + 1);
                    end = clock();
                    outfile << (end - start) / CLOCKS_PER_SEC << endl;
                    //
                    outfile.close();
                    cout << t << " "; //output to check run situation
                }
                //
                cout << endl;
            }
        }
    }
    return 0;
}
