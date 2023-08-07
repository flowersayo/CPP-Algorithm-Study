#include <string>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> graph(rows);

    int num=1;
    for(int i=0; i<rows;i++){ //그래프 입력
        for(int j=0; j<columns;j++){
            graph[i].push_back(num);
            num++;
        }
    }

    for(int i=0; i<queries.size();i++){ 
        int r1=queries[i][0]-1; //그래프 인덱스는 0부터 시작하기 때문에 -1
        int c1=queries[i][1]-1;
        int r2=queries[i][2]-1;
        int c2=queries[i][3]-1;
        int temp=graph[r1][c1]; //처음 값
        int mini=temp;
        //시계 반대 방향으로 뒤에서부터 하나씩 땡겨옴
        for(int a=r1; a<r2;a++){ 
            graph[a][c1] = graph[a+1][c1];
            mini = min(mini,graph[a][c1]);
        }
        for(int a=c1; a<c2;a++){
            graph[r2][a] = graph[r2][a+1];
            mini = min(mini,graph[r2][a]);
        }
        for(int a=r2; a>r1;a--){
            graph[a][c2] = graph[a-1][c2];
            mini = min(mini,graph[a][c2]);
        }
        for(int a=c2; a>c1;a--){
            graph[r1][a] = graph[r1][a-1];
            mini = min(mini,graph[r1][a]);
        }
        //처음 빼놓은 값 저장
        graph[r1][c1+1] =temp;

    answer.push_back(mini);       
    }

    return answer;
}