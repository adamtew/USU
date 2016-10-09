//
// Created by Adam on 11/23/15.
//

#include "Simulator.h"
using namespace std;

Simulator::Simulator( int size )
{
    n = size;
    n2 = n * n;
    vector<int> row(0 , n);
    uf.setUp( n );
    srand(time(nullptr));
    for(int i = 0; i < n; i++)
    {
        s.push_back(row);
        for(int j = 0; j < n; j++)
        {
            s[i].push_back(j);
        }
    }
}

string Simulator::toString()
{
    stringstream ss;
    ss << "\t ";
    for(int i = 0; i < n; i++)ss << "_";
    ss << endl;
    for(int i = 0; i < n; i++)
    {
        ss << "\t|";
        for(int j = 0; j < n; j++)
        {
            if(s[i][j] == -99)
            {
//                ss << uf.find( n * i + j );
                ss << " ";
                continue;
            }
           ss << "X";
        }
        ss << "|" << endl;
    }
    ss << "\t ";
    for(int i = 0; i < n; i++)ss << "\u203E";
    ss << endl;
    return ss.str();
}

void Simulator::put()
{
    int x = rand() % n;
    int y = rand() % n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == y && x == j)
            {
//                Check adjent points
                int point = (n * i + j);
//                Check x axis
                int left = n * i + (j - 1);
                int right = n * i + (j + 1);

                if( j - 1 > 0) {
                    if(s[i][j - 1] == -99 || uf.s[ left ] != -1) {
                        uf.unionSets( point , left);
                    }
                }
                if( j + 1 < n ) {
                    if(s[i][j + 1] == -99 || uf.s[ right ] != -1) {
                        uf.unionSets( point , right);
                    }
                }

//                Check y axis
                int up = n * (i - 1) + j;
                int down = n * (i + 1) + j;

//                Check up
                if( i - 1 < 0)uf.unionSets( n2 , point );
                else
                    if(s[i - 1][j] == -99 || uf.s[ up ] != -1)
                        uf.unionSets( point , up );

//                Check down
                if( i + 1 >= n)uf.unionSets( n2 + 1 , point );
                else
                    if( s[i + 1][j] == -99 || uf.s[ down ] != -1)
                        uf.unionSets( point , down );

                s[i][j] = -99;
            }
        }
    }
}

bool Simulator::perc()
{
    return uf.find( n2 ) == uf.find( n2 + 1 );
}