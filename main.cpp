#include <iostream>
#include <cstring>
using namespace std;
int matrix[105][105];
void print_matrix(int n, int m);
void DFS(int i,int j,int n,int m, int (*matrix_cp)[105]);
void DFS2(int i,int j,int n,int m, int (*matrix_cp2)[105]);
int main(){
    int n,m;
    char temp;
    while(cin>>n>>m){
        getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>temp;
                if(temp == '0'){
                    matrix[i][j] = 0;
                }
                else if(temp == '1'){
                    matrix[i][j] = 1;
                }

            }
            getchar();
        }


        int matrix_cp[105][105];
        int matrix_cp2[105][105];
        int matrix_cp3[105][105];
        memcpy(matrix_cp,matrix, sizeof(matrix));
        memcpy(matrix_cp2,matrix, sizeof(matrix));
        memcpy(matrix_cp3,matrix, sizeof(matrix));




        int connected_component_1 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix_cp[i][j]==1){
                   // cout<<"i: "<<i<<"j: "<<j<<endl;
                    connected_component_1++;
                    DFS(i,j,n,m,matrix_cp);
                }
            }
        }



        int connected_component_0 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix_cp2[i][j]==0){
                    connected_component_0++;
                    DFS2(i,j,n,m,matrix_cp2);
                }
            }
        }
       // cout<<"0:  "<<connected_component_0<<endl;


        for(int i=0;i<n;i++){
            if(matrix_cp3[i][0]==0){
                DFS2(i,0,n,m,matrix_cp3);
            }
            if(matrix_cp3[i][m-1]==0){
                DFS2(i,m-1,n,m,matrix_cp3);
            }
        }

        for(int j=0;j<m;j++){
            if(matrix_cp3[0][j]==0){
                DFS2(0,j,n,m,matrix_cp3);
            }
            if(matrix_cp3[n-1][j]==0){
                DFS2(n-1,j,n,m,matrix_cp3);
            }
        }




        int connected_0 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix_cp3[i][j]==0){
                    connected_0++;
                    DFS2(i,j,n,m,matrix_cp3);
                }
            }
        }

       // cout<<connected_component_1<<"---"<<connected_0<<endl;
        if(connected_component_1==1 && connected_0==1) {
            cout << 0 << endl;
        }
        else if(connected_component_1==1 && connected_0==0){
            cout<<1<<endl;
        }
        else{
            cout<<-1<<endl;

        }
    }
    return 0;
}



void print_matrix(int n, int m) {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}


void DFS(int i,int j,int n,int m, int (*matrix_cp)[105]){
    if(i < 0 || j < 0 || i > n - 1 || j > m - 1){
        return;
    }
    matrix_cp[i][j]=0;
    for(int a=-1;a<=1;a++){
        for(int b=-1;b<=1;b++){
            if(a*b!=0){
                continue;
            }
            if(matrix_cp[i+a][j+b]==1){
                matrix_cp[i][j]=0;
                DFS(i+a,j+b,n,m,matrix_cp);
            }
        }
    }
}

void DFS2(int i,int j,int n,int m, int (*matrix_cp2)[105]){

    if(i < 0 || j < 0 || i > n - 1 || j > m - 1){
        return;
    }
    matrix_cp2[i][j]=1;
    for(int a=-1;a<=1;a++){
        for(int b=-1;b<=1;b++){
            if(a*b!=0){
                continue;
            }

            if(matrix_cp2[i+a][j+b]==0){
                DFS2(i+a,j+b,n,m,matrix_cp2);
            }
        }
    }
}