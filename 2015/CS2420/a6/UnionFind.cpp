//
// Created by Adam on 11/20/15.
//

#include "UnionFind.h"

UnionFind::UnionFind( int size )
{
    n = size;
    n2 = n * n;
    for(int i = 0; i < n * n; i++)s.push_back( -1 );
    s.push_back(-1);
    s.push_back(-1);

}

void UnionFind::setUp(int size)
{
    n = size;
    n2 = n * n;
    for(int i = 0; i < n2; i++)s.push_back( -1 );
    s.push_back(-1);
    s.push_back(-1);
}

UnionFind::UnionFind() { }

// Union from class that utilizes path compression
void UnionFind::unionSets(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)return;
    if(s[a] < s[b])
        s[b] = a;
    else if(s[a] > s[b])
        s[a] = b;
    else
    {
        s[a]--;
        s[b] = a;
    }
}

// find with path compressions
int UnionFind::find(int x)
{
    if( x >= 0 && x < s.size())
    {
        if( s[ x ] < 0 )
            return x;
        else
            return s[ x ] = find( s[ x ] );
    }
}

string UnionFind::toString()
{
    stringstream ss;
    for(int i = 0; i < n2; i++)ss << s[i] << " ";
    ss << endl;
    return ss.str();
}

