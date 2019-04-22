// C++ program to solve Traveling Salesman Problem
// using Branch and Bound.
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define M 25
#define ll long long int 
 int N  = 4;
int adj[M][M]  ; 

int final_path[M+1];
bool visited[M];
int final_res = INT_MAX;
vector< pair < ll , ll  > > pv ; 

void copyToFinal(int curr_path[])
{
  for (int i=0; i<N; i++)
    final_path[i] = curr_path[i];
  final_path[N] = curr_path[0];
}
int firstMin( int i)
{
  int min = INT_MAX;
  for (int k=0; k<N; k++)
    if (adj[i][k]<min && i != k)
      min = adj[i][k];
  return min;
}
int secondMin(int i)
{
  int first = INT_MAX, second = INT_MAX;
  for (int j=0; j<N; j++)
  {
    if (i == j)
      continue;

    if (adj[i][j] <= first)
    {
      second = first;
      first = adj[i][j];
    }
    else if (adj[i][j] <= second &&
        adj[i][j] != first)
      second = adj[i][j];
  }
  return second;
}

void TSPRec( int curr_bound, int curr_weight,
      int level, int curr_path[])
{
  if (level==N)
  {

    if (adj[curr_path[level-1]][curr_path[0]] != 0)
    {

      int curr_res = curr_weight +
          adj[curr_path[level-1]][curr_path[0]];

      if (curr_res < final_res)
      {
        copyToFinal(curr_path);
        final_res = curr_res;
      }
    }
    return;
  }


  for (int i=0; i<N; i++)
  {
 
    if (adj[curr_path[level-1]][i] != 0 &&
      visited[i] == false)
    {
      int temp = curr_bound;
      curr_weight += adj[curr_path[level-1]][i];

     
      if (level==1)
      curr_bound -= ((firstMin(curr_path[level-1]) +
              firstMin( i))/2);
      else
      curr_bound -= ((secondMin(curr_path[level-1]) +
              firstMin( i))/2);


      if (curr_bound + curr_weight < final_res)
      {
        curr_path[level] = i;
        visited[i] = true;

        TSPRec( curr_bound, curr_weight, level+1,
          curr_path);
      }

      curr_weight -= adj[curr_path[level-1]][i];
      curr_bound = temp;

      memset(visited, false, sizeof(visited));
      for (int j=0; j<=level-1; j++)
        visited[curr_path[j]] = true;
    }
  }
}

void TSP()
{
  int curr_path[N+1];
  int curr_bound = 0;
  memset(curr_path, -1, sizeof(curr_path));
  memset(visited, 0, sizeof(curr_path));

  for (int i=0; i<N; i++)
    curr_bound += (firstMin( i) +
          secondMin(i));

  curr_bound = (curr_bound&1)? curr_bound/2 + 1 :
                curr_bound/2;

  visited[0] = true;
  curr_path[0] = 0;

  TSPRec( curr_bound, 0, 1, curr_path);
}

int main()
{
  if (fopen("inp.txt", "r")) {
      freopen("myfile.txt","w",stdout);
      freopen("inp.txt", "r", stdin);
  }
  int t ; 
  cin>>t;
  while(t--){
      cin>>N ; 
      int deg[N] ; 
      final_res = INT_MAX;
      for( int i = 0  ; i< N ; i++ ){
        deg[i+1] = 0 ; 
        for( int j = 0 ; j < N ; j ++ ){
            cin>>adj[i][j] ; 
            if(adj[i][j] > 0 ) deg[i+1]++;

        }
      }
      int f = 1 ; 
      sort(deg + 1,deg+N + 1) ; 
      
      //Posa theorem 
      // for( int i = 1 ; i < N /2   ; i++ ){
      //   if( N < 3 ) break ; 
      //   if(deg[i] <  i + 1   ) f = 0 ;
      // }

      // Dirac theorem
      // for( int i = 1 ; i <= N   ; i++ ){
      //   if( N < 3 ) break ; 
      //   if(deg[i ] < (N)/2    ) f = 0 ;
      // }

      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      // if(f) 
        TSP();
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>( t2 - t1 ).count();
      ll D = (ll) duration ; 
      // cout<<(D)<<endl;
      // pv.push_back ( make_pair(N , D) ); 
      if(f)
        cout<<N <<" " << duration<<"\n";
      else
        cout<<final_res<<"** "<<N <<" " << duration<<"\n";

      // printf("Minimum cost : %d\n", final_res);
      // printf("Path Taken : ");
      // for (int i=0; i<=N; i++)
      //   printf("%d ", final_path[i]);
  }
  // sort(pv.begin() , pv.end() ) ; 
  // for( auto it :pv)
  //     cout<<it.first<<" "<<it.second<<"\n" ; 
  return 0;
}
