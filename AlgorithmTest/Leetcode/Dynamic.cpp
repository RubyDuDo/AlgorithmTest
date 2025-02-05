//
//  Dynamic.cpp
//  AlgorithmTest
//
//  Created by pinky on 2024-09-17.
//

#include "Dynamic.hpp"

vector<string> generatePart( int m, int k )
 {
     vector<string> vecPre;
     vector<string> vecRes;
    
//    if( k == 0 )
//    {
//        std::string str;
//        for( int i = 0; i < m ; i++ )
//        {
//            str += "(";
//        }
//        
//        vector<string>({str});
//    }

     if( m == 1)
     {
         if( k > 1 )
         {
             return vector<string>();
         }
         else if( k == 1 )
         {
             return vector<string>({"()"});
         }
         else if( k == 0 )
         {
             return vector<string>({"("});
         }
         
     }

     for( int i = 0 ; i <= k  ; i++  )
     {
         int last = k - i;
         if( last > m )
         {
             continue;
         }
         
         if( i > m-1 )
         {
             break;
         }
         
         string post = "(";
         for( int j = 0 ; j < last; j++ )
         {
             post += ")";
         }

         vecPre = generatePart( m - 1 , i );

         for( auto str : vecPre )
         {
             vecRes.push_back( str + post );
         }
     }

     return vecRes;

 }
 vector<string> generateParenthesis(int n) {
     if( n == 1 )
     {
         return vector<string>({"()"});
     }

     std::vector<string> vecPre = generatePart( n, n-1 );
     std::vector<string> vecRes;
     std::string post = ")";
     for( auto str : vecPre )
     {
         vecRes.push_back( str + post );
     }

     return vecRes;
 }
#include<iostream>

string generatePre( int k )
{
    string str(k,'(');
    return str;
}

string generatePost( int k )
{
    string str(k,')');
    
    return str;
}

vector<string> generatePart2( int n )
{
    if( n == 1 )
    {
        return vector<string>({"()"});
    }
    vector< vector<string> > vecPre;
    
    vecPre.resize(2);
    vecPre[0].push_back({"("});
    vecPre[1].push_back({"()"});
    
    vector< vector<string> > vecCur;
    for( int i = 2 ; i < n ;i++ )
    {
        vecCur.resize( i + 1  );
        vector<string> cn0;
        vecCur[0].push_back( generatePre( i ) );
        
        for( int j = 1 ; j <= i ; j++ )
        {
            //calc C( i, j )
            for( int p = 0; p <= i-1 && p <= j; p++ )
            {
                int last = j - p ;
                
                for( auto str : vecPre[p] )
                {
                    vecCur[j].push_back( str + "(" + generatePost( last ) );
                }
            }
        }
        
        vecPre.swap( vecCur );
        vecCur.clear();
    }
    
    vector<string> vecRes;
    
    //gen n-1 choose C(n, n-1)
    for( int p = 0 ; p < n ; p ++ )
    {
        int last = n -p;
        for( auto str : vecPre[p] )
        {
            vecRes.push_back( str +  "(" + generatePost( last ));
        }
    }
    
    return vecRes;
    
}

vector<string> generateParenthesis2(int n)
{
    return generatePart2(n);
}

void testDynamic()
{
    auto vec = generateParenthesis2( 6);
    for( auto str : vec )
    {
        cout<< str <<endl;
    }
    
    cout<<"count:"<<vec.size()<<endl;
}
